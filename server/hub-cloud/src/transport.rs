pub mod mqtt;
pub mod http;
pub enum TransportIn {}
use tokio::net::TcpStream;

use crate::proto::typedef::Buffer;
use crate::transport::http::CloudResponse;


pub enum TransportOut {
    ResponseMqttEvent(String, Buffer),
    ResponseHttpEvent(CloudResponse, TcpStream),
}
