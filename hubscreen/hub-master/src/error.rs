#[derive(Debug, PartialEq, Clone)]
pub enum BridgeIpErr {
    MqttErr,
    MqttConvertJsoErr,
    HttpSendErr,
    HttpErr,
    CreateSqlErr,
    AddSqlErr,
    DeleteSqlErr,
    GetSqlErr,
}
