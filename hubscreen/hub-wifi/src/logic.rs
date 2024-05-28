use crate::error::BridgeIpErr;
use crate::proto::buffer::typedef::{Buffer, User_t, Vendor_t};
use crate::proto::wifi::wifi::Wifi_t;

use crate::transport::TransportOut;
use std::collections::VecDeque;

#[derive(Clone)]

pub struct BrLogic {
    pub outputs: VecDeque<BrLogicOut>,
}

#[derive(Clone)]
pub enum TickLogicOut {
    CheckKeepAlive,
}

#[derive(Clone)]
pub enum BrLogicIn {
    Transport(Result<TransportOut, BridgeIpErr>),
    Tick(TickLogicOut),
}

#[derive(Debug, Clone)]
pub enum BrLogicOut {
    None,
    SyncDevice, 
    DataToDevice{buffer: Buffer},
    DataToHub{mac:String ,wifi: Wifi_t}
}

impl BrLogic {
    pub fn init(&mut self) {
        
    }

    pub fn new() -> Self {
        let outputs = std::iter::once(BrLogicOut::None).collect();

        BrLogic { outputs: outputs }
    }

    pub fn get_local_ip(&mut self) -> Result<String, BridgeIpErr> {
        let socket = std::net::UdpSocket::bind("0.0.0.0:0").unwrap();
        socket.connect("8.8.8.8:80").unwrap();
        let local_ip = socket.local_addr().unwrap().ip();
        return Ok(local_ip.to_string());
    }

    pub fn on_event(&mut self, _event: BrLogicIn) {
        match _event {
            BrLogicIn::Transport(result) => match result {
                Ok(transport) => match transport {
                    TransportOut::ResponseBuffer(buffer) => {
                        if buffer.sender == User_t::Hub.into() {
                            if buffer.led.is_empty() && buffer.sw.is_empty() {
                                self.outputs.push_back(BrLogicOut::SyncDevice);
                            }
                            self.outputs.push_back(BrLogicOut::DataToDevice { buffer});
                        }     
                    }
                    TransportOut::ResponseWifi(topic, wifi) => {
                        let parts: Vec<&str> = topic.split('/').collect();
                        if let Some(last_part) = parts.last() {
                            let mac = last_part.to_string();
                            self.outputs.push_back(BrLogicOut::DataToHub { mac, wifi});
                        } 
                    }

                },
                Err(e) => match e {
                    _ => {}
                },
            },
            BrLogicIn::Tick(tick_event) => match tick_event {
                TickLogicOut::CheckKeepAlive => {
                    // self.outputs.push_back(BrLogicOut::CheckKeepAlive);
                }
            },
        }
    }
    pub fn pop_action(&mut self) -> Option<BrLogicOut> {
        self.outputs.pop_front()
    }
}

#[cfg(test)]
mod test {

    // use super::*;
}
