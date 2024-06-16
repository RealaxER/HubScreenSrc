use crate::error::BridgeIpErr;
use crate::proto::typedef::{Buffer, User_t, Vendor_t};
use crate::transport::TransportOut;
use std::collections::VecDeque;
use chrono::{TimeZone, DateTime, Datelike, Utc, Timelike, FixedOffset};

#[derive(Clone)]

pub struct BrLogic {
    pub outputs: VecDeque<BrLogicOut>,
    pub scheduler: Vec<Buffer>,
    pub time: String,
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
    TimerHandle{buffer:Buffer},
    UpgradeDevice{buffer:Buffer},
    EnableVpn,
    DisableVpn,
    RestartMqtt,
}

impl BrLogic {
    pub fn init(&mut self) {
        self.outputs.push_back(BrLogicOut::SyncDevice);

    }

    pub fn new() -> Self {
        let outputs = std::iter::once(BrLogicOut::None).collect();
        BrLogic { 
            outputs: outputs,
            scheduler: Vec::new(),
            time: "".to_string()
        }
    }

    pub fn get_local_ip(&mut self) -> Result<String, BridgeIpErr> {
        let socket = std::net::UdpSocket::bind("0.0.0.0:0").unwrap();
        socket.connect("8.8.8.8:80").unwrap();
        let local_ip = socket.local_addr().unwrap().ip();
        return Ok(local_ip.to_string());
    }

    pub fn on_tick(&mut self, now_ms: u64) {

        let timestamp = now_ms; // Example: 1st January 2021, 00:00:00 UTC
        let datetime_utc: DateTime<Utc> = Utc.timestamp_opt((timestamp / 1000) as i64, 0).unwrap();
        let datetime_vn = datetime_utc.with_timezone(&FixedOffset::east_opt(7 * 3600).unwrap());
        let hour = datetime_vn.hour();
        let minute = datetime_vn.minute();
        let day = datetime_vn.day();
        let month = datetime_vn.month();
        self.time = format!("{:02}:{:02}:{:02}:{:02}", hour, minute, day, month);

        let mut index = 0;
        while index < self.scheduler.len() {
            if self.scheduler[index].time.hour == hour
                && self.scheduler[index].time.minute == minute
                && self.scheduler[index].time.day == day
                && self.scheduler[index].time.month == month {

                    self.outputs.push_back(BrLogicOut::TimerHandle { buffer: self.scheduler[index].clone() });
                    self.scheduler.remove(index);
            } else {
                index += 1;
            }
        }
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
                                if buffer.cotroller == User_t::Hub.into() && buffer.time.is_none() {
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
                    BridgeIpErr::MqttErr => {
                        self.outputs.push_back(BrLogicOut::RestartMqtt);
                    }
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
