use crate::error::BridgeIpErr;
use crate::proto::typedef::Buffer;
use crate::proto::typedef::User_t;
use crate::transport::http::CloudResponse;
use crate::transport::TransportOut;
use std::collections::VecDeque;
use tokio::net::TcpStream;


pub struct BrLogic {
    pub outputs: VecDeque<BrLogicOut>,
}

#[derive(Clone)]
pub enum TickLogicOut {
    KeepAlive,
    FindOta,
}

pub enum BrLogicIn {
    Transport(Result<TransportOut, BridgeIpErr>),
    Tick(TickLogicOut),
}

#[derive(Debug)]
pub enum BrLogicOut {
    None,
    KeepAlive,
    DataToHub { buffer: Buffer },
    DataToApp { buffer: Buffer },
    CheckOta {response: CloudResponse , socket: TcpStream},
    FindOta,
    AllowOta{buffer: Buffer}
}

impl BrLogic {
    pub fn init(&mut self) {
        //self.outputs.push_back(BrLogicOut::GetDeviceFromSql);
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
                        if topic.contains("hub/control/app") {
                            if buffer.cotroller == User_t::Ota.into() && buffer.sender == User_t::App.into() {
                                self.outputs.push_back(BrLogicOut::AllowOta { buffer});
                            }
                            else {
                                self.outputs.push_back(BrLogicOut::DataToHub { buffer});
                            }
                        }else if topic.contains("hub/master/") {
                            self.outputs.push_back(BrLogicOut::DataToApp { buffer});
                        }
                    }
                    TransportOut::ResponseHttpEvent(response, socket ) => {
                        self.outputs.push_back(BrLogicOut::CheckOta { response, socket })
                    }
                },
                Err(e) => match e {
                    _ => {}
                },
            },
            BrLogicIn::Tick(tick_event) => match tick_event {
                TickLogicOut::KeepAlive => {
                    self.outputs.push_back(BrLogicOut::KeepAlive);
                }
                TickLogicOut::FindOta => {
                    self.outputs.push_back(BrLogicOut::FindOta);
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
