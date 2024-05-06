use crate::error::BridgeIpErr;
use crate::proto::typedef::{Buffer, User_t, Vendor_t};
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
    CheckKeepAlive,
    DataToClient{buffer:Buffer},
    DataToServer{buffer:Buffer},
    VendorData{vendor: Vendor_t},
    SyncDevice,
    UpgradeDevice{buffer:Buffer},
    EnableVpn,
    DisableVpn
}

impl BrLogic {
    pub fn init(&mut self) {
        self.outputs.push_back(BrLogicOut::SyncDevice);
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
                    TransportOut::ResponseMqttEvent(topic, buffer) => {
                        if buffer.sender == User_t::Server.into() && topic.contains("hub/server/"){
                            if !buffer.vpn.is_none() {
                                if buffer.vpn.status {
                                   self.outputs.push_back(BrLogicOut::EnableVpn); 
                                }
                                else {
                                    self.outputs.push_back(BrLogicOut::DisableVpn); 

                                }
                                
                            }else {
                                if buffer.cotroller == User_t::Hub.into() {
                                    self.outputs.push_back(BrLogicOut::UpgradeDevice {buffer});
                                }
                                else {
                                    self.outputs.push_back(BrLogicOut::DataToClient {buffer});
                                }
                                
                            }
                            
                        }else {
                            self.outputs.push_back(BrLogicOut::DataToServer {buffer});
                        }
                    }
                    TransportOut::ResponseVendorEvent( vendor) => {
                        self.outputs.push_back(BrLogicOut::VendorData { vendor});
                    }
                },
                Err(e) => match e {
                    _ => {}
                },
            },
            BrLogicIn::Tick(tick_event) => match tick_event {
                TickLogicOut::CheckKeepAlive => {
                    self.outputs.push_back(BrLogicOut::CheckKeepAlive);
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
