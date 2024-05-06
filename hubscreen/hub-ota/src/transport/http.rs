use crate::error::BridgeIpErr;
use crate::proto::typedef::Buffer;
use protobuf::Message;
use reqwest::Client;
use tokio::sync::mpsc;
use super::TransportOut;
pub struct Cloud {
    tx: mpsc::Sender<Result<TransportOut, BridgeIpErr>>,
    rx: mpsc::Receiver<Result<TransportOut, BridgeIpErr>>,
}

impl Cloud {
    pub async fn new() -> Cloud {
        let (tx, rx) = mpsc::channel::<Result<TransportOut, BridgeIpErr>>(5);
        Cloud {
            tx: tx,
            rx: rx,
        }
    }

    pub async fn recv(&mut self)  -> Result<TransportOut, BridgeIpErr> {
        return self.rx.recv().await.unwrap();
    }
    
    pub async fn send(&mut self, body:Vec<u8>, header:(String , String)) -> Result<(), BridgeIpErr> {
        let client = Client::new();
        let (key,value ) = header;
        let response = client
            .post("http://54.253.168.98:8080")
            .header(key, value)
            .body(body.clone())
            .send()
            .await
            .map_err(|_| BridgeIpErr::HttpSendErr);

        log::info!("--> {}:{:?}","http://54.253.168.98:8080", body);
        match response?.bytes().await  {
            Ok(bytes) => {
                if let Ok(buffer) = Buffer::parse_from_bytes(&bytes) {
                    log::info!("<-- {}:{:?}","http://54.253.168.98:8080", buffer);
                    self.tx
                    .send(Ok(TransportOut::ResponseHttpEvent(
                        buffer,
                    )))
                    .await
                    .unwrap();
                }else {
                    log::info!("<-- {}:{:?}","http://54.253.168.98:8080", bytes);
                    self.tx
                    .send(Ok(TransportOut::ResponseOtaEvent(
                        bytes.to_vec(),
                    )))
                    .await
                    .unwrap();
                }

            }
            Err(e) => {
                log::info!("{:?}", e);
                return Err(BridgeIpErr::HttpErr);
            }
        }

        Ok(())
    }

}