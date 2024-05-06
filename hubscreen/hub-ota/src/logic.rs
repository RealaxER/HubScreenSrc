use crate::error::BridgeIpErr;
use crate::proto::typedef::User_t;
use crate::transport::TransportOut;
use std::collections::VecDeque;

#[derive(Clone)]

pub struct BrLogic {
    pub outputs: VecDeque<BrLogicOut>,
}

#[derive(Clone)]
pub enum TickLogicOut {
    KeepAlive,
    CheckOta,
}

#[derive(Clone)]
pub enum BrLogicIn {
    Transport(Result<TransportOut, BridgeIpErr>),
    Tick(TickLogicOut),
}

#[derive(Debug, Clone)]
pub enum BrLogicOut {
    None,
    KeepAlive,
    CheckOta,
    RequestOta,
    DownloadOta{content:Vec<u8>},
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
                    TransportOut::ResponseMqttEvent(_, _) => {
                        //self.outputs.push_back(BrLogicOut::RequestOta { buffer });
                    }
                    TransportOut::ResponseHttpEvent(buffer) => {
                        if buffer.sender == User_t::Server.into() && buffer.ota.ack {
                            if buffer.ota.status {
                                self.outputs.push_back(BrLogicOut::RequestOta);
                            }
                        }else {

                        }
                    }
                    TransportOut::ResponseOtaEvent(content) => {
                        self.outputs.push_back(BrLogicOut::DownloadOta{content});
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
                TickLogicOut::CheckOta => {
                    self.outputs.push_back(BrLogicOut::CheckOta);
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
