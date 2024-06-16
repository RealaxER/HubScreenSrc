#[derive(Debug, PartialEq, Clone)]
pub enum BridgeIpErr {
    FormatErr,
    MqttErr,
    MqttConvertJsoErr,
    HttpSendErr,
    HttpErr,
    CreateSqlErr,
    AddSqlErr,
    DeleteSqlErr,
    GetSqlErr,
}
