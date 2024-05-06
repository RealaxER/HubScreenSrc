pub mod mqtt;
pub mod http;
pub enum TransportIn {}

use crate::proto::typedef::Buffer;

#[derive(Clone)]
pub enum TransportOut {
    ResponseMqttEvent(String, Buffer),
    ResponseHttpEvent(Buffer),
    ResponseOtaEvent(Vec<u8>),

}
