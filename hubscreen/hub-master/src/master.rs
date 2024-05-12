use tokio::process::Command;

use crate::proto::typedef::Buffer;

pub struct Master {
    pub buff: Buffer
}

impl Master {
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
