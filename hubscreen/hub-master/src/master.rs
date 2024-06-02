use tokio::process::Command;

use crate::proto::typedef::Buffer;

pub struct Master {
    pub buff: Buffer,
    pub devices: Vec<String>
}

impl Master {

    pub async fn update_device(&mut self, buffer:Buffer) {
        for led in buffer.led.clone() {
            self._update_device(led.name).await;
        }
        for sw in buffer.sw.clone() {
            self._update_device(sw.name).await;
        }
    }

    pub async fn check_device(&mut self, buffer:Buffer) -> bool {
        let mut check = false;
        for led in buffer.led.clone() {
            check = self._update_device(led.name).await;
        }
        for sw in buffer.sw.clone() {
           check = self._update_device(sw.name).await;
        }

        return check;
    }

    async fn _update_device(&mut self, device_name: String) -> bool{
        let mut check = false;
        for name in &self.devices {
            if name == &device_name {
                // Implement your logic here
                check = true;
            }
        }
        if !check {
            self.devices.push(device_name);
        }
        return check
    }
    pub async fn enable_vpn(&mut self) {
        log::info!("Enable vpn");
        Command::new("sh")
        .arg("-c")
        .arg("sudo systemctl start vpn.service")
        .spawn() 
        .expect("failed to execute process");
    }

    pub async fn disable_vpn(&mut self) {
        log::info!("Disable vpn");
        Command::new("sh")
        .arg("-c")
        .arg("sudo systemctl stop vpn.service")
        .spawn() // Sử dụng `spawn` thay vì `output` để chạy child process
        .expect("failed to execute process");
    }
}
