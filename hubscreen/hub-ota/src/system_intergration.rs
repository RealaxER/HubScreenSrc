use crate::error::BridgeIpErr;
use crate::logic::TickLogicOut;
use crate::logic::{BrLogic, BrLogicIn, BrLogicOut};
use crate::proto::typedef::{Buffer, KeepAlive_t, Ota_t, User_t};
use crate::transport::mqtt::MqttDriver;
use crate::transport::http::Cloud;
use protobuf::Message;
use crate::ota::Ota;
use rand::prelude::*;

use tokio::{
    select,
    time::{interval, Duration, Interval},
};

pub struct SystemIntergration {
    interval: Interval,
    keepalive: Interval,
    logic: BrLogic,
    transport: MqttDriver,
    cloud: Cloud,
    ota: Ota,
}

impl SystemIntergration {
    pub async fn new(dir_ota: String, mac: String) -> Self {
        let mut rng = rand::thread_rng();
        let mut logic = BrLogic::new();
        let broker_id = logic.get_local_ip().unwrap();
        log::info!("Address: {}", broker_id);
        let random = rng.gen_range(30..=120) * 60;
        log::info!("Random ota: {}", random);
        
        SystemIntergration {
            interval: interval(Duration::from_secs(20)),
            keepalive: interval(Duration::from_secs(45)),
            logic: BrLogic::new(),
            transport: MqttDriver::new(
                "hub-ota".to_string(),
                "127.0.0.1".to_string(),
                1883,
                45,
            )
            .await,
            cloud: Cloud::new().await,
            ota: Ota{
                mac: mac,
                dir: dir_ota
            }
        }
    }

    pub async fn init(&mut self) {
        
    }

    pub async fn recv(&mut self) -> Result<(), BridgeIpErr> {
        select! {
            _ = self.interval.tick() => {
                self.logic.on_event(BrLogicIn::Tick(TickLogicOut::CheckOta));
            },

            _ = self.keepalive.tick() => {
                //self.logic.on_event(BrLogicIn::Tick(TickLogicOut::KeepAlive));
            },

            etransport  = self.transport.recv() => {
                self.logic.on_event(BrLogicIn::Transport(etransport));
            },

            transport = self.cloud.recv() => {
                self.logic.on_event(BrLogicIn::Transport(transport));
            }
        }

        while let Some(out) = self.logic.pop_action() {
            match out {
                BrLogicOut::KeepAlive => {
                    let mut ka = KeepAlive_t::new();
                    ka.sender = User_t::Ota.into();
                    let topic = format!("hub/master/keepalive");
                    let message = ka.write_to_bytes().unwrap();
                    let _ = self
                        .transport
                        .send(topic, message, rumqttc::QoS::AtMostOnce, false)
                        .await;
                }

                BrLogicOut::CheckOta => {
                    let mut body = Buffer::new();
                    body.sender = User_t::Ota.into();
                    body.receiver = User_t::Server.into();
                    body.cotroller = User_t::Ota.into();
                    let mut ota = Ota_t::new();
                    ota.ack = true;
                    body.mac_hub = self.ota.mac.clone();
                    body.ota = Some(ota).into();

                    let mut vec:Vec<u8> = Vec::new();
                    let _  = body.write_to_vec(&mut vec);
                    let _ = self.cloud.send(vec, ("hubscreen".to_string(), "ota".to_string())).await;
                }

                BrLogicOut::RequestOta => {
                    let mut body = Buffer::new();
                    body.sender = User_t::Ota.into();
                    body.receiver = User_t::Server.into();
                    body.cotroller = User_t::Ota.into();
                    body.mac_hub = self.ota.mac.clone();
 
                    let mut vec:Vec<u8> = Vec::new();
                    let _  = body.write_to_vec(&mut vec);
                    let _ = self.cloud.send(vec, ("updateota".to_string(), "true".to_string())).await;
                }

                BrLogicOut::DownloadOta{content} => {
                    let ota_dir = self.ota.dir.clone();
                    match self.ota.write_ota(ota_dir, content).await {
                        Ok(_) => {
                            log::info!("Write successfuly");
                        },
                        Err(e) => {
                            log::error!("Write err {:?}", e);
                        }
                    }
                }
                _ => {}
            }
        }
        Ok(())
    }
}
