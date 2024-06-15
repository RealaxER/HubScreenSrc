use super::TransportOut;
use crate::error::BridgeIpErr;
use crate::proto::typedef::Buffer;
use crate::proto::typedef::User_t;
use crate::proto::typedef::Vendor_t;
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
}
// packed install from app
impl MqttDriver {
    pub async fn new(id: String, host: String, port: u16, keep_alive: u64) -> Self {
        let mut mqttoptions = MqttOptions::new(id, host, port);

        mqttoptions.set_keep_alive(Duration::from_secs(keep_alive));
        
        let (client, eventloop) = AsyncClient::new(mqttoptions.clone(), 10);

        client
            .subscribe("hub/control/app/+", QoS::AtMostOnce)
            .await
            .unwrap();

        client
            .subscribe("hub/master/+", QoS::AtMostOnce)
            .await
            .unwrap();

        client
            .subscribe("vendor/wifi/+", QoS::AtMostOnce)
            .await
            .unwrap();

        client
            .subscribe("vendor/master/+", QoS::AtMostOnce)
            .await
            .unwrap();
    
        let (tx, rx) = mpsc::channel::<Result<TransportOut, BridgeIpErr>>(5);
        log::info!("Connecting to mqtt server");
        MqttDriver {
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
        match Buffer::parse_from_bytes(&message.clone()) {
            Ok(buff) => {
                log::info!("--> {} : {:?}", topic.clone(), buff);
            }
            Err(e) => {
                log::info!("{:?}", e);
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
                            if publish.topic.contains("hub/master") || publish.topic.contains("hub/control/app"){
                                if let Some(buff) = Buffer::parse_from_bytes(&publish.payload.to_vec()).ok() {
                                    if buff.receiver.unwrap() == User_t::Server {
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

                            else if publish.topic.contains("vendor/master") {
                                if let Some(vendor) = Vendor_t::parse_from_bytes(&publish.payload.to_vec()).ok() {
                                    log::info!(
                                        "<-- {} : {:?}",
                                        publish.topic.clone(),
                                        vendor.clone()
                                    );
                                    self.tx
                                        .send(Ok(TransportOut::ResponeMacEvent(
                                            publish.topic.clone(),
                                            vendor,
                                        )))
                                        .await
                                        .unwrap();
                                }
                            }
                            else if publish.topic.contains("vendor/wifi") {
                                log::info!(
                                    "<-- {} : {:?}",
                                    publish.topic.clone(),
                                    publish.payload.clone()
                                );
                                self.tx
                                    .send(Ok(TransportOut::ResponeVendor(
                                        publish.topic.clone(),
                                        String::from_utf8(publish.payload.to_vec()).unwrap(),
                                    )))
                                    .await
                                    .unwrap();
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
