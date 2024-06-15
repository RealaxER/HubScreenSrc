use crate::error::BridgeIpErr;
use crate::logic::{BrLogic, BrLogicIn, BrLogicOut};
use crate::proto::typedef::{Buffer, User_t, Vpn_t};
use crate::transport::mqtt::MqttDriver;
use crate::master::Master;
use crate::timer::{SystemTimer, Timer};
// use crate::sqlite::Sqlite;
use protobuf::Message;
use tokio::{
    select,
    time::{interval, Duration, Interval},
};


pub struct SystemIntergration {
    interval: Interval,
    logic: BrLogic,
    timer: SystemTimer,
    broker: MqttDriver,
    transport: MqttDriver,
    master: Master,
   // sql: Sqlite,
}

impl SystemIntergration {
    pub async fn new(mac: String) -> Self {
        SystemIntergration {
            interval: interval(Duration::from_secs(60)),
            logic: BrLogic::new(),
            timer: SystemTimer::default(),
            broker: MqttDriver::new(
                "hub-master".to_string(),
                "3.26.238.229".to_string(),
                1883,
                45,
                mac.clone(),
                false,
            )
            .await,
            transport: MqttDriver::new(
                "hub-master-transport".to_string(),
                "127.0.0.1".to_string(),
                1883,
                45,
                mac,
                true
            )
            .await,
            //sql: Sqlite::new("/home/bhien/data.db".to_string()).await,
            master: Master{
                buff: Buffer::new(),
                devices: Vec::new()
            },
        }
    }

    pub async fn init(&mut self) {
        // let mut buffer = Buffer::new();

        // let topic =  "hub/ai".to_string();
        // buffer.sender = User_t::Hub.into();
        // buffer.receiver = User_t::Ai.into();
        
        // let mut sw = Sw_t::new();
        // sw.name = "Sw1".to_string();
        // sw.mac = 0xaaaa;
        // sw.status = true;
        // sw.ep = 1;
        // buffer.sw.push(sw);

        // let mut sw = Sw_t::new();
        // sw.name = "Sw2".to_string();
        // sw.mac = 0xaaaa;
        // sw.status = true;
        // sw.ep = 2;
        // buffer.sw.push(sw);

        // let message = buffer.write_to_bytes().unwrap();
        // let _ = self.transport.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;

        // let topic =  "hub/ai".to_string();
        // let mut buffer = Buffer::new();
        // buffer.sender = User_t::Hub.into();
        // buffer.receiver = User_t::Ai.into();

        // let message = buffer.write_to_bytes().unwrap();
        // let _ = self.transport.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
        self.logic.init();
    }

    pub async fn recv(&mut self) -> Result<(), BridgeIpErr> {
        select! {
            _ = self.interval.tick() => {
                self.logic.on_tick(self.timer.now_ms());
            },

            etransport  = self.broker.recv() => {
                self.logic.on_event(BrLogicIn::Transport(etransport));
            },

            etransport  = self.transport.recv() => {
                self.logic.on_event(BrLogicIn::Transport(etransport));
            },
        }

        while let Some(out) = self.logic.pop_action() {
            match out {
                BrLogicOut::DataToClient { mut buffer } => {
                    if buffer.time.is_none() {
                        let topic = format!("hub/{:?}", buffer.cotroller);
                        let topic = topic.to_ascii_lowercase();
                        buffer.sender = User_t::Hub.into();
                        buffer.receiver = buffer.cotroller.clone();
                        let message = buffer.write_to_bytes().unwrap();
                        let _ = self.transport.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;

                        if self.master.check_device(buffer.clone()).await {
                            let topic = format!("hub/ai");
                            buffer.receiver = User_t::Ai.into();
                            let message = buffer.write_to_bytes().unwrap();
                            let _ = self.transport.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;


                            let topic = format!("hub/screen");
                            buffer.receiver = User_t::Screen.into();
                            let message = buffer.write_to_bytes().unwrap();
                            let _ = self.transport.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
                        }
                    }
                    else {
                        log::info!("SET TIMER: {}:{}:{}:{}", buffer.time.hour, 
                                                             buffer.time.minute,
                                                             buffer.time.day, 
                                                             buffer.time.month);
                        self.logic.scheduler.push(buffer);
                    }
                }

                BrLogicOut::DataToServer { mut buffer } => {
        
                    let topic = format!("hub/master/{}",self.transport.mac);
                    buffer.sender = User_t::Hub.into();
                    buffer.receiver = User_t::Server.into();
                    let message = buffer.write_to_bytes().unwrap();
                    let _ = self.broker.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
                }

                BrLogicOut::DisableVpn => {
                    let old_mac = self.logic.get_local_ip().unwrap();
                    self.master.disable_vpn().await;
                    let mut buffer = Buffer::new();
                    buffer.sender = User_t::Hub.into();
                    buffer.receiver = User_t::Server.into();
                    buffer.mac_hub = self.transport.mac.clone();
                    while self.logic.get_local_ip().unwrap() == old_mac{}
                    let mut vpn = Vpn_t::new();
                    vpn.status = false;
                    vpn.mac = self.logic.get_local_ip().unwrap();
                    buffer.vpn = Some(vpn).into();

                    let topic = format!("hub/master/{}",self.transport.mac);
                    let message = buffer.write_to_bytes().unwrap();
                    let _ = self.broker.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
                }

                BrLogicOut::EnableVpn => {
                    let old_mac = self.logic.get_local_ip().unwrap();
                    self.master.enable_vpn().await;

                    while self.logic.get_local_ip().unwrap() == old_mac{}
                    let mut buffer = Buffer::new();
                    buffer.sender = User_t::Hub.into();
                    buffer.receiver = User_t::Server.into();
                    buffer.mac_hub = self.transport.mac.clone();
                    let mut vpn = Vpn_t::new();
                    vpn.status = true;
                    vpn.mac = self.logic.get_local_ip().unwrap();
                    buffer.vpn = Some(vpn).into();

                    let topic = format!("hub/master/{}",self.transport.mac);
                    let message = buffer.write_to_bytes().unwrap();
                    let _ = self.broker.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
                }

                BrLogicOut::CheckKeepAlive => {
                    
                }

                BrLogicOut::UpgradeDevice { mut buffer } => {
                    log::info!("=======UPGRADE DEVICE===========");
		            if buffer.sync.sync {
                        let mut buff = Buffer::new();
                        buff.sender = User_t::Hub.into();
                        buff.receiver = User_t::Zigbee.into();
                        buff.cotroller = User_t::Zigbee.into();
                        let topic = format!("hub/zigbee");
                        let message = buff.write_to_bytes().unwrap();
                        let _ = self.transport.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
                    }
                    self.master.update_device(buffer.clone()).await;

                    let topic = format!("hub/screen");
                    let topic = topic.to_ascii_lowercase();
                    buffer.sender = User_t::Hub.into();
                    buffer.receiver = User_t::Screen.into();
                    buffer.cotroller = User_t::Hub.into();
                    let message = buffer.write_to_bytes().unwrap();
                    let _ = self.transport.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;

                    let topic = format!("hub/ai");
                    buffer.receiver = User_t::Ai.into();
                    let message = buffer.write_to_bytes().unwrap();
                    let _ = self.transport.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
                }

                BrLogicOut::SyncDevice => {
                    self.master.enable_hub().await;
                    let topic = format!("hub/master/{}",self.transport.mac);
                    let mut buffer = Buffer::new();
                    buffer.mac_hub = self.transport.mac.clone();
                    buffer.sender = User_t::Hub.into();
                    buffer.receiver = User_t::Server.into();
                    buffer.cotroller = User_t::Hub.into();
                    let message = buffer.write_to_bytes().unwrap();
                    let _ = self.broker.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
                }

                BrLogicOut::VendorData { vendor } => {
                    let topic = format!("vendor/pub/{}", vendor.mac_ven);
                    let message = vendor.write_to_bytes().unwrap();
                    let _ = self.broker.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
                }

                BrLogicOut::TimerHandle { mut buffer } => {
                    log::info!("==============TimerHandle==============");
                    buffer.sender = User_t::Hub.into();

                    let topic = format!("hub/zigbee");
                    buffer.receiver = User_t::Zigbee.into();
                    buffer.cotroller = User_t::Zigbee.into();
                    let message = buffer.write_to_bytes().unwrap();
                    let _ = self.broker.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;

                    let topic = format!("hub/wifi");
                    buffer.receiver = User_t::Wifi.into();
                    buffer.cotroller = User_t::Wifi.into();
                    let message = buffer.write_to_bytes().unwrap();
                    let _ = self.broker.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;

                    let topic = format!("hub/ble");
                    buffer.receiver = User_t::Ble.into();
                    buffer.cotroller = User_t::Ble.into();
                    let message = buffer.write_to_bytes().unwrap();
                    let _ = self.broker.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
                }
                _ => {}
            }
        }
        Ok(())
    }
}
