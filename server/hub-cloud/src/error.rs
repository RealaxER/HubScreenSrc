#[derive(Debug, PartialEq, Clone)]
pub enum BridgeIpErr {
    MqttErr,
    MqttConvertJsoErr,
    CreateSqlErr,
    AddSqlErr,
    GetSqlErr,
    DeleteSqlErr,
}
