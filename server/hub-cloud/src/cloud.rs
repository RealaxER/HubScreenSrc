pub struct HubCloud {
    pub devices: Vec<(String,String)>
}

impl HubCloud {
    pub async fn get_ip(&mut self, mac: String) -> String {
        for (mac_old, ip_old) in self.devices.clone() {
            if mac_old == mac {
                return ip_old.clone();
            }
        }
        return "".to_string();
    }
}
