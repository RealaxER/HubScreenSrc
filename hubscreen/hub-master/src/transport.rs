pub mod mqtt;
pub enum TransportIn {}

use crate::proto::typedef::{Buffer, Vendor_t};

#[derive(Clone)]
pub enum TransportOut {
    ResponseMqttEvent(String, Buffer),
    ResponseVendorEvent(Vendor_t),
}
