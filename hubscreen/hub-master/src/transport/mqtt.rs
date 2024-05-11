use super::TransportOut;
use crate::error::BridgeIpErr;
use crate::proto::typedef::Buffer;
use crate::proto::typedef::User_t;
use crate::proto::typedef::Vendor_t;
use protobuf::Message;
use protobuf::Enum;
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
    pub async fn new(id: String, host: String, port: u16, keep_alive: u64, mac: String, mode:bool) -> Self {
        let mut mqttoptions = MqttOptions::new(id, host, port);

        mqttoptions.set_keep_alive(Duration::from_secs(keep_alive));
        
        let (client, eventloop) = AsyncClient::new(mqttoptions.clone(), 10);
        if mode {
            for i in 3..=7 {
                if let Some(user) = User_t::from_i32(i) {
                    let topic = format!("hub/{:?}", user);
                    let topic = topic.to_lowercase();
                    log::info!("Topic: {:?}", topic);
                    client
                        .subscribe(topic, QoS::AtMostOnce)
                        .await
                        .unwrap();
                }
            }
            client
            .subscribe("vendor/sub/+", QoS::AtMostOnce)
            .await
            .unwrap();
        }
        else {
            let topic: String = format!("hub/server/{}", mac);
            log::info!("Connecting to hub: {}", topic);
            client
                .subscribe(topic, QoS::AtMostOnce)
                .await
                .unwrap();
    
            client
                .subscribe("hub/vendor/+", QoS::AtMostOnce)
                .await
                .unwrap();
        }

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
                            if publish.topic.clone().contains("hub/vendor/"){
                                if let Ok(vendor) = Vendor_t::parse_from_bytes(&publish.payload.to_vec()) {
                                    log::info!(
                                        "<-- {} : {:?}",
                                        publish.topic,
                                        vendor.clone()
                                    );

                                    self.tx
                                    .send(Ok(TransportOut::ResponseVendorEvent(
                                        vendor,
                                    )))
                                    .await
                                    .unwrap();
                                }
                            }

                            else if publish.topic.clone().contains("vendor/sub/"){

                            }
                            else {
                                if let Ok(buff) = Buffer::parse_from_bytes(&publish.payload.to_vec()) {
                                    if buff.receiver == User_t::Hub.into() {
                                        log::info!(
                                            "<-- {} : {:?}",
                                            publish.topic.clone(),
                                            buff.clone()
                                        );
                                        self.tx
                                            .send(Ok(TransportOut::ResponseMqttEvent(
                                                publish.topic.clone(),
                                                buff,
                                            )))
                                            .await
                                            .unwrap();
                                    }
                                    else {
                                        self.tx.send(Err(BridgeIpErr::MqttErr)).await.unwrap();
                                    }
                                }
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
