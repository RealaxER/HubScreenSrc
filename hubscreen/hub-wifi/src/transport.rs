pub mod mqtt;
pub enum TransportIn {}

use crate::proto::buffer::typedef::Buffer;
use crate::proto::wifi::wifi::Zigbee_t;


#[derive(Clone)]
pub enum TransportOut {
    ResponseBuffer(Buffer),
    ResponseWifi(String, Zigbee_t),
}
