pub mod mqtt;
pub enum TransportIn {}

use crate::proto::buffer::typedef::{Buffer, Vendor_t};
use crate::proto::wifi::wifi::Wifi_t;


#[derive(Clone)]
pub enum TransportOut {
    ResponseBuffer(Buffer),
    ResponseWifi(String, Wifi_t),
}
