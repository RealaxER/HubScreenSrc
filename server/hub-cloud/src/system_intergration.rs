use crate::error::BridgeIpErr;
use crate::logic::TickLogicOut;
use crate::logic::{BrLogic, BrLogicIn, BrLogicOut};
use crate::proto::typedef::{User_t, Ota_t};
use crate::transport::http::Cloud;
use crate::transport::mqtt::MqttDriver;
use crate::ota::Ota;
use crate::cloud::HubCloud;
use crate::sqlite::Sqlite;
use protobuf::Message;

use tokio::{
    select,
    time::{interval, Duration, Interval},
    fs
};

pub struct SystemIntergration {
    interval: Interval,
    logic: BrLogic,
    transport: MqttDriver,
    http: Cloud,
    ota: Ota,
    sql: Sqlite,
    cloud: HubCloud
}

impl SystemIntergration {
    pub async fn new(db: String, dir_ota:String) -> Self {
        let mut logic = BrLogic::new();

        let mut broker_id = logic.get_local_ip().unwrap();
        broker_id = format!("{}:{}", broker_id, "8080");
        log::info!("Local ip {}", broker_id);
        SystemIntergration {
            interval: interval(Duration::from_millis(45000)),
            logic: BrLogic::new(),
            transport: MqttDriver::new(
                "hub-cloud".to_string(),
                "54.253.168.98".to_string(),
                1883,
                45,
            ).await,
            http: Cloud::new(broker_id.to_string()).await,
            ota: Ota{
                path: "".to_string(),
                have_ota: false,
                update_ota: false,
                devices: Vec::new(),
                dir_ota: dir_ota ,
            },
            sql: Sqlite::new(db).await,
            cloud: HubCloud{
                devices: Vec::new()
            }
        }
    }

    pub async fn init(&mut self) {
        let _ = self.sql.connect().await;
        let vec = self.sql.get_devices().await.unwrap();
        for mac in vec {
            self.ota.add_device(mac.clone()).await;
        }
        log::info!("Connecting to server");
    }

    pub async fn recv(&mut self) -> Result<(), BridgeIpErr> {
        select! {
            _ = self.interval.tick() => {
                self.logic.on_event(BrLogicIn::Tick(TickLogicOut::FindOta));
            },

            etransport  = self.transport.recv() => {
                self.logic.on_event(BrLogicIn::Transport(etransport));
            },

            cloud = self.http.recv() => {
                self.logic.on_event(BrLogicIn::Transport(cloud));

            }
        }

        while let Some(out) = self.logic.pop_action() {
            match out {
                BrLogicOut::AllowOta { buffer } => {
                    if buffer.ota.check_ota {
                        self.ota.update_ota = true;
                        log::info!("Allow {} update ota", buffer.mac_hub.clone());
                    }else {
                        self.ota.update_ota = false;
                        log::info!("Not allow {} update ota", buffer.mac_hub.clone());
                    }

                }

                BrLogicOut::DataToHub { mut buffer } => {
                    if buffer.sender.unwrap() == User_t::App {
                        let topic = format!("hub/server/{}", buffer.mac_hub);
                        buffer.sender = User_t::Server.into();
                        buffer.receiver = User_t::Hub.into();
                        let message = buffer.write_to_bytes().unwrap();
                        let _ = self
                            .transport
                            .send(topic, message, rumqttc::QoS::AtMostOnce, false)
                            .await;
                    }
                }

                BrLogicOut::DataToApp { mut buffer } => {
                    if buffer.sender.unwrap() == User_t::Hub {
                        let topic = format!("hub/status/app/{}", buffer.mac_hub);
                        buffer.sender = User_t::Server.into();
                        buffer.receiver = User_t::App.into();
                        let message = buffer.write_to_bytes().unwrap();
                        let _ = self
                            .transport
                            .send(topic, message, rumqttc::QoS::AtMostOnce, false)
                            .await;
                    }
                }
                
                BrLogicOut::CheckOta{response , socket } => {
                    let headers = response.headers;
                    let mut buffer = response.body;
                    buffer.sender = User_t::Server.into();
                    buffer.receiver = User_t::Ota.into();
                    let mut message = Vec::new();

                    for (key, value) in headers {
                        if key.contains("hubscreen") && value.contains("ota") {
                            log::info!("INFO OTA for {} : {} {}",buffer.mac_hub, self.ota.update_ota, self.ota.have_ota);
                            let mut ota = Ota_t::new();
                            if self.ota.update_ota && self.ota.have_ota {
                                if self.ota.get_device(buffer.mac_hub.clone()).await {
                                    ota.status = true;
                                }
                            }
                            ota.ack = true;
                            buffer.ota = Some(ota).into();
                            message = self.http.convert_vec(buffer.write_to_bytes().unwrap()).await;
                            break;
                        }
                        else if key.contains("updateota") && value.contains("true") {
                            log::info!("Update OTA {}", buffer.mac_hub);
                            if self.ota.update_ota && self.ota.have_ota {
                                if let Ok(content)= self.ota.read_ota().await {
                                    log::info!("Content update OTA: {:?}", content);
                                    message  = self.http.convert_vec(content).await;  
                                }
                            }
                        }
                    }
                    if !message.is_empty() {
                        self.http.send(socket, message).await;
                    } 
                }

                BrLogicOut::FindOta => {
                    let directory_path = self.ota.dir_ota.clone();
                    if let Ok(mut entries)  =  fs::read_dir(directory_path.clone()).await {
                        self.ota.have_ota = false;
                        self.ota.path = "".to_string(); 
                        while let Ok(Some(entry)) = entries.next_entry().await {
                            if let Ok(file_ota) = entry.file_name().to_os_string().into_string() {
                                self.ota.have_ota = true;
                                log::info!("File ota : {:?}", file_ota);
                                
                                self.ota.path = format!("{}{}",directory_path ,file_ota);
                            }   
                        }
                    }
                }

                BrLogicOut::MacToWifi { request, mac } => {
                    let topic = format!("master/wifi/{}", request);
                    let message = self.cloud.get_ip(mac).await;
                    let _ = self
                            .transport
                            .send(topic, message.into(), rumqttc::QoS::AtMostOnce, false)
                            .await;
                }

                BrLogicOut::ResponseMac { mac, vendor } => {
                    let mut check = true;
                    for (mac_old, ip_old) in &mut self.cloud.devices {
                        if *mac_old == mac {
                            check = false;
                            *ip_old = vendor.mac_ven.clone();
                        }
                    }
                    
                    if check {
                        self.cloud.devices.push((mac, vendor.mac_ven));
                    }
                }

                _ => {}
            }
        }
        Ok(())
    }
}
