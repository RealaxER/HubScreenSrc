use std::io;
use tokio::fs::File;
use tokio::io::AsyncReadExt;

pub struct Ota {
    pub path: String,
    pub have_ota: bool,
    pub update_ota: bool,
    pub devices: Vec<String>,
    pub dir_ota: String
}

impl Ota {
    // Hàm đọc toàn bộ nội dung của file zip và trả về một Vec<u8>
    pub async fn read_ota(&mut self) -> io::Result<Vec<u8>> {
        let mut file = File::open(self.path.clone()).await?;
        let mut buffer = Vec::new();
        file.read_to_end(&mut buffer).await?;
        Ok(buffer)
    }

    pub async fn add_device (&mut self, mac_i: String) {
        self.devices.push(mac_i);
    }
    
    pub async fn get_device (&mut self, mac_i: String) -> bool {
        for mac in &self.devices {
            if mac_i == *mac {
                return true;
            }
        }
        return false;
    }
}
