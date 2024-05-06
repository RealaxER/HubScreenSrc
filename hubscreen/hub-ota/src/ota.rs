use std::io;
use tokio::fs::File;
use tokio::io::AsyncWriteExt;

pub struct Ota {
    pub mac: String,
    pub dir: String,
}

impl Ota {
    // Hàm ghi một Vec<u8> vào file
    pub async fn write_ota(&self,path:String, data: Vec<u8>) -> io::Result<()> {
        let mut file = File::create(&path).await?;
        file.write_all(&data).await?;
        Ok(())
    }
}
