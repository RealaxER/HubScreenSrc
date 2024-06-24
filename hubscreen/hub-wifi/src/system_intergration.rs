use crate::error::BridgeIpErr;
use crate::logic::TickLogicOut;
use crate::logic::{BrLogic, BrLogicIn, BrLogicOut};
use crate::proto::buffer::typedef::{Buffer, User_t, Sw_t};
use crate::proto::wifi::wifi::{SwZb_t, Zigbee_t};
use crate::transport::mqtt::MqttDriver;
use protobuf::Message;
use tokio::{
    select,
    time::{interval, Duration, Interval},
};


pub struct SystemIntergration {
    interval: Interval,
    logic: BrLogic,
    transport: MqttDriver,
}

impl SystemIntergration {
    pub async fn new(mac: String) -> Self {
        SystemIntergration {
            interval: interval(Duration::from_secs(45)),
            logic: BrLogic::new(),
            transport: MqttDriver::new(
                "hub-wifi".to_string(),
                "127.0.0.1".to_string(),
                1883,
                45,
                mac
            )
            .await,
        }
    }

    pub async fn init(&mut self) {
        self.logic.init();
    }

    pub async fn recv(&mut self) -> Result<(), BridgeIpErr> {
        select! {
            _ = self.interval.tick() => {
                self.logic.on_event(BrLogicIn::Tick(TickLogicOut::CheckKeepAlive));
            },

            etransport  = self.transport.recv() => {
                self.logic.on_event(BrLogicIn::Transport(etransport));
            },
        }

        while let Some(out) = self.logic.pop_action() {
            match out {
                BrLogicOut::DataToDevice { buffer }  => {
                    let mut wifi = Zigbee_t::new();
                    let mut sw_wf = SwZb_t::new();
                    for sw in buffer.sw {
                        sw_wf.status = sw.status;
                        sw_wf.deviceID = sw.mac as u32;
                        sw_wf.endpoint = sw.ep;
                    }
                    wifi.sw = Some(sw_wf).into();
                    
                    let topic = format!("hub/wifi/9118");
                    let message = wifi.write_to_bytes().unwrap();
                    let _ = self.transport.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
                }

                BrLogicOut::SyncDevice => {
                    let mut wifi = Zigbee_t::new();
                    wifi.sync = true;
                    let topic = format!("hub/wifi/9118");
                    let message = wifi.write_to_bytes().unwrap();
                    let _ = self.transport.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
                }

                BrLogicOut::DataToHub { mac, wifi } => {
                    let mut buffer = Buffer::new();
                    buffer.mac_hub = self.transport.mac.clone();
                    buffer.sender = User_t::Wifi.into();
                    buffer.receiver = User_t::Hub.into();
                    buffer.cotroller = User_t::Wifi.into();
                    let mut sw = Sw_t::new();
                    sw.ep = wifi.sw.endpoint;
                    sw.mac = wifi.sw.deviceID as u64;
                    sw.status = wifi.sw.status;
                    sw.name = format!("wifi {}",sw.ep);
		    buffer.sw.push(sw);

                    let topic = format!("hub/wifi");
                    let message = buffer.write_to_bytes().unwrap();
                    let _ = self.transport.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
                }
                _ => {}
            }
        }
        Ok(())
    }
}
