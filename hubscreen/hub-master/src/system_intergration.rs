use crate::error::BridgeIpErr;
use crate::logic::TickLogicOut;
use crate::logic::{BrLogic, BrLogicIn, BrLogicOut};
use crate::proto::typedef::{Buffer, Sw_t, User_t, Vpn_t};
use crate::transport::mqtt::MqttDriver;
use crate::master::Master;
use protobuf::Message;
use tokio::{
    select,
    time::{interval, Duration, Interval},
};


pub struct SystemIntergration {
    interval: Interval,
    logic: BrLogic,
    broker: MqttDriver,
    transport: MqttDriver,
    master: Master
}

impl SystemIntergration {
    pub async fn new(mac: String) -> Self {
        SystemIntergration {
            interval: interval(Duration::from_secs(45)),
            logic: BrLogic::new(),
            broker: MqttDriver::new(
                "hub-master".to_string(),
                "54.253.168.98".to_string(),
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

            master: Master{
                buff: Buffer::new()
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
                self.logic.on_event(BrLogicIn::Tick(TickLogicOut::CheckKeepAlive));
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
                BrLogicOut::DataToClient { mut buffer } =>{
                    let topic = format!("hub/{:?}", buffer.cotroller);
                    let topic = topic.to_ascii_lowercase();
                    buffer.sender = User_t::Hub.into();
                    buffer.receiver = buffer.cotroller.clone();
                    let message = buffer.write_to_bytes().unwrap();
                    let _ = self.transport.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
                }

                BrLogicOut::DataToServer { mut buffer } => {
                    if buffer.sender == User_t::Ai.into() {
                        buffer.mac_hub = self.transport.mac.clone(); 
                        if !buffer.led.is_empty() {
                            for led_ct in buffer.led.iter_mut() {
                                for mut led in self.master.buff.led.clone() {
                                    if led_ct.name == led.name {
                                        let mut temp = Buffer::new();
                                        temp.sender = User_t::Hub.into();
                                        temp.receiver = User_t::Wifi.into();
                                        led.status = led_ct.status.clone();
                                        *led_ct = led.clone();
                                        temp.led.push(led.clone());

                                        let topic = format!("hub/wifi");
                                        let message = temp.write_to_bytes().unwrap();
                                        let _ = self.broker.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
                                    }
                                }
                            }
                        }
                        else if !buffer.sw.is_empty() {
                            for sw_ct in buffer.sw.iter_mut() {
                                for mut sw in self.master.buff.sw.clone() {
                                    if sw_ct.name == sw.name {
                                        let mut temp = Buffer::new();
                                        temp.sender = User_t::Hub.into();
                                        temp.receiver = User_t::Wifi.into();
                                        sw.status = sw_ct.status.clone();
                                        *sw_ct = sw.clone();
                                        temp.sw.push(sw.clone());

                                        let topic = format!("hub/ai");
                                        let message = temp.write_to_bytes().unwrap();
                                        let _ = self.broker.send(topic, message, rumqttc::QoS::AtMostOnce, false).await;
                                    }
                                }
                            }
                        }
                    }
           
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

                BrLogicOut::UpgradeDevice { buffer } => {
                    log::info!("Device to upgrade: {:?}", buffer);
                    self.master.upgrade_device(buffer).await;
                }

                BrLogicOut::SyncDevice => {
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
                _ => {}
            }
        }
        Ok(())
    }
}
