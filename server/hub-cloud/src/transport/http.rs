use tokio::net::TcpListener;
use tokio::net::TcpStream;
use tokio::io::AsyncReadExt;
use tokio::io::AsyncWriteExt;
use httparse::Request;
use tokio::sync::mpsc;
use super::TransportOut;
use crate::error::BridgeIpErr;
use crate::proto::typedef::{Buffer, User_t};
use protobuf::Message;

#[derive(Debug, Default)]
pub struct CloudResponse {
    pub body: Buffer,
    pub headers: Vec<(String, String)>,
    pub method: String,
    pub path: String,
}

#[derive(Debug)]
pub struct Cloud {
    tx: mpsc::Sender<Result<TransportOut, BridgeIpErr>>,
    rx: mpsc::Receiver<Result<TransportOut, BridgeIpErr>>,
    listener: TcpListener,
    pub response: CloudResponse,
}

impl Cloud {
    pub async fn new(addr: String) -> Cloud {
        let listener = TcpListener::bind(addr).await.unwrap();
        let (tx, rx) = mpsc::channel::<Result<TransportOut, BridgeIpErr>>(5);
        Cloud {
            tx: tx,
            rx: rx,
            listener,
            response: CloudResponse::default(),
        }
    }
    pub async fn recv(&mut self)  -> Result<TransportOut, BridgeIpErr> {
        match self.listener.accept().await {
            Ok((mut socket, addr)) => {
                let tx_clone = self.tx.clone(); 
                //let rx_clone  = self.rx.clone();
                tokio::spawn(async move {
                    let mut buf = [0; 1024];
                    let n = socket.read(&mut buf).await.unwrap();
                    let mut headers = [httparse::EMPTY_HEADER; 16];
                    let mut req = Request::new(&mut headers);
                    req.parse(&buf[..n]).unwrap();

                    let mut response = handle_request(&req);
                    let body = get_buf(&buf).unwrap();
                    match Buffer::parse_from_bytes(&body) {
                        Ok(body) => {
                            log::info!("<-- {}: {:?}", addr.ip(), body);
                            if body.sender != User_t::App.into() &&
                            body.receiver != User_t::App.into() &&
                            body.cotroller != User_t::App.into() {
                                response.body = body;
                                tx_clone
                                .send(Ok(TransportOut::ResponseHttpEvent(
                                    response,
                                    socket,
                                )))
                                .await
                                .unwrap();
                            }
                            else {

                            }
                        }
                        Err(e) => {
                            log::error!("{}", e);
                        }   
                    }
                    
                });
            }
            Err(e) => {
                log::error!("Failed to connecting: {:?}", e);
            }
        }
        return self.rx.recv().await.unwrap();
    }

    pub async fn convert_str(&mut self, body: String) -> String{
        format!(
            "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: {}\r\n\r\n{}",
            body.len(),
            body
        )
    }

    
    pub async fn convert_vec(&mut self, body: Vec<u8>) -> Vec<u8> {
        // Tính độ dài của body
        let body_len = body.len();
        
        // Tạo vector chứa chuỗi HTTP response
        let mut http_response: Vec<u8> = Vec::new();
        
        // Thêm phần header vào vector của HTTP response
        http_response.extend_from_slice(b"HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n");
        http_response.extend_from_slice(format!("Content-Length: {}\r\n\r\n", body_len).as_bytes());
        
        // Thêm body vào vector của HTTP response
        http_response.extend_from_slice(&body);
        
        return http_response;
    }


    pub async fn send(&mut self, mut socket: TcpStream, buf: Vec<u8>) {
        if let Ok(addr) = socket.peer_addr() {
            log::info!("--> {}: {:?}", addr.ip(), buf);
        }
        socket.write_all(&buf).await.unwrap();
        socket.flush().await.unwrap();
    }
    
}

fn get_body(data: &[u8]) -> Option<&[u8]> {
    if let Some(index) = data.windows(4).position(|window| window == b"\r\n\r\n") {
        // Trả về phần thân của HTTP, bắt đầu từ sau "\r\n\r\n"
        Some(&data[index + 4..])
    } else {
        // Nếu không tìm thấy "\r\n\r\n", trả về None
        None
    }
}

fn get_buf(data: &[u8]) -> Option<Vec<u8>> {
    let body = get_body(data)?;
    let mut vec = body.to_vec();
    vec.retain(|&x| x != 0);
    Some(vec)
}

fn handle_request(req: &Request) -> CloudResponse {
    let mut response = CloudResponse::default();
    response.method = req.method.unwrap().to_string();
    response.path = req.path.unwrap().to_string();

    for header in req.headers.iter() {
        response.headers.push((header.name.to_string(), std::str::from_utf8(header.value).unwrap().to_string()));
    }

    return response;
}
