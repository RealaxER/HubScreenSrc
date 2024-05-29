use super::TransportOut;
use crate::error::BridgeIpErr;
use crate::proto::buffer::typedef::Buffer;
use crate::proto::wifi::wifi::Wifi_t;
use crate::proto::buffer::typedef::User_t;
use protobuf::Message;
use rumqttc::{AsyncClient, Event, EventLoop, MqttOptions, QoS};
use tokio::sync::mpsc;
use tokio::time::Duration;

pub struct MqttDriver {
    pub tx: mpsc::Sender<Result<TransportOut, BridgeIpErr>>,
    pub rx: mpsc::Receiver<Result<TransportOut, BridgeIpErr>>,
    pub options: MqttOptions,
    pub client: AsyncClient,
    pub eventloop: EventLoop,
    pub mac: String,
}
// packed install from app
impl MqttDriver {
    pub async fn new(id: String, host: String, port: u16, keep_alive: u64, mac: String) -> Self {
        let mut mqttoptions = MqttOptions::new(id, host, port);

        mqttoptions.set_keep_alive(Duration::from_secs(keep_alive));
        
        let (client, eventloop) = AsyncClient::new(mqttoptions.clone(), 10);

        client
        .subscribe("hub/wifi", QoS::AtMostOnce)
        .await
        .unwrap();

        client
        .subscribe("device/wifi/+", QoS::AtMostOnce)
        .await
        .unwrap();

        let (tx, rx) = mpsc::channel::<Result<TransportOut, BridgeIpErr>>(5);
        MqttDriver {
            mac: mac,
            tx: tx,
            rx: rx,
            options: mqttoptions.clone(),
            client: client,
            eventloop: eventloop,
        }
    }
    pub async fn send(
        &mut self,
        topic: String,
        message: Vec<u8>,
        qos: QoS,
        retain: bool,
    ) -> Result<(), BridgeIpErr> {
        if let Ok(buffer) =  Buffer::parse_from_bytes(&message.clone()) {
            if buffer.sender == User_t::App.into() &&
            buffer.receiver == User_t::App.into() &&
            buffer.cotroller == User_t::App.into() {
                log::info!("--> {} : {:?}", topic.clone(), message); 
            }
            else {
                log::info!("--> {} : {:?}", topic.clone(), buffer); 
            }
        }
        match self.client.publish(topic, qos, retain, message).await {
            Ok(res) => Ok(res),
            Err(_) => Err(BridgeIpErr::MqttErr),
        }
    }

    pub async fn recv(&mut self) -> Result<TransportOut, BridgeIpErr> {
        loop {
            let event = self.eventloop.poll().await;
            match &event {
                Ok(v) => match v {
                    Event::Incoming(packet) => match packet {
                        rumqttc::Packet::Publish(publish) => {
                            if let Ok(buff) = Buffer::parse_from_bytes(&publish.payload.to_vec()) {
                                if buff.receiver == User_t::Wifi.into() {
                                    log::info!(
                                        "<-- {} : {:?}",
                                        publish.topic.clone(),
                                        buff.clone()
                                    );
                                    self.tx
                                        .send(Ok(TransportOut::ResponseBuffer(
                                            buff
                                        )))
                                        .await
                                        .unwrap();
                                }
                                else {
                                    self.tx.send(Err(BridgeIpErr::MqttErr)).await.unwrap();
                                }
                            }
                            else if let Ok(wifi) = Wifi_t::parse_from_bytes(&publish.payload.to_vec()) {
                                self.tx
                                .send(Ok(TransportOut::ResponseWifi(
                                    publish.topic.clone(),
                                    wifi,
                                )))
                                .await
                                .unwrap();
                            }
                            else {
                                self.tx.send(Err(BridgeIpErr::MqttErr)).await.unwrap();
                            }
                            return self.rx.recv().await.unwrap();
                        }

                        _ => {}
                    },
                    Event::Outgoing(_) => {}
                },
                Err(e) => {
                    log::info!("Error = {e:?}");
                    self.tx.send(Err(BridgeIpErr::MqttErr)).await.unwrap();
                    return self.rx.recv().await.unwrap();
                }
            }
        }
    }
}
