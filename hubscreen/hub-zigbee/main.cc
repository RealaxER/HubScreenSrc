#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include "mqtt.hh"
#include "uart.hh"
#include "config.hh"

#include "zigbee.pb.h"
#include "typedef.pb.h"

#define MAX_BUFFER 255

struct Event {
    enum EventType { UART_DATA_RECEIVED, MQTT_MESSAGE_RECEIVED } type;
    const std::vector<uint8_t> data;
    const std::string topic;

    Event(EventType t, const std::string p, const std::vector<uint8_t>& d) : type(t), topic(p), data(d) {}
};

std::queue<Event> eventQueue;
std::mutex mtx;
std::condition_variable cv;

class HubDevice_t {
public:
    Zigbee_t zigbee;
    Buffer buff;
    Mqtt_t transport;
    Uart_t uart;

    HubDevice_t(const char *id, const char *port)
        : transport(id), uart(port) {
        this->zigbee = Zigbee_t();
        this->buff = Buffer();
    }
};

void uart_callback(const unsigned char *data, int length) {
    std::lock_guard<std::mutex> lock(mtx);
    LOG_INFO("<-- " << "UART" << " : " << data);
    std::vector<uint8_t> vec_data(data, data + length);
    eventQueue.push(Event(Event::UART_DATA_RECEIVED, "", vec_data));
    cv.notify_one();
}

void mqtt_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message) {
    std::lock_guard<std::mutex> lock(mtx);
    LOG_INFO("<-- " << message->topic << " : " << message->payload);
    std::vector<uint8_t> vec_data((const uint8_t *)message->payload, (const uint8_t *)message->payload + message->payloadlen);
    eventQueue.push(Event(Event::MQTT_MESSAGE_RECEIVED, message->topic, vec_data));
    cv.notify_one();
}



uint8_t zigbee_arr[MAX_BUFFER];
void convertBufferToZigbee(HubDevice_t device){
    memset(zigbee_arr , 0, sizeof(zigbee_arr));
    if(device.buff.sender() != User_t::Hub || device.buff.receiver() != User_t::Zigbee ) {
        return;
    }

    if(device.buff.sw_size() == 0){
        Zigbee_t zigbee;
        zigbee.set_sync(true);
        zigbee.SerializeToArray(zigbee_arr, sizeof(zigbee_arr));
        LOG_INFO("Packet sync to zigbee");
        LOG_INFO("--> " << "UART" << " : " << zigbee.DebugString() );
        // start byte data
        device.uart.send(zigbee_arr, zigbee.ByteSize());
        // end byte data
        uint8_t end = 0xff;
        device.uart.send(&end, 1);

    }

    for (int i = 0; i < device.buff.sw_size(); ++i) {       
        Sw_t sw = device.buff.sw(i); 

        Zigbee_t zigbee;
        SwZb_t* sw_zigbee = zigbee.mutable_sw(); 
        sw_zigbee->set_endpoint(sw.ep());
        sw_zigbee->set_deviceid(sw.mac());
        sw_zigbee->set_status(sw.status());
        zigbee.SerializeToArray(zigbee_arr, sizeof(zigbee_arr));

        LOG_INFO("--> " << "UART" << " : " << zigbee.DebugString() );
        // start byte data
        device.uart.send(zigbee_arr, zigbee.ByteSize());
        // end byte data
        uint8_t end = 0xff;
        device.uart.send(&end, 1);
    }
}

Buffer convertZigbeeToBuffer(Zigbee_t zigbee){

}

int main(void) {
    // Test MQTT
    __test_mqtt();
    // Test UART

    // Setup HubDevice_t
    HubDevice_t hub_zigbee(DEVICE_NAME, PATH_SEZIAL);

    // Set MQTT
    hub_zigbee.transport.set_callback(mqtt_callback);
    hub_zigbee.transport.setup(BROKER, PORT, 45);
    hub_zigbee.transport.subscribe(SUB , 1);
    hub_zigbee.transport.connect();

    // Set UART
    hub_zigbee.uart.connect(B1152000);

    while (true) {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, []{ return !eventQueue.empty(); });

        Event event = eventQueue.front();

        eventQueue.pop();

        lock.unlock();


        switch (event.type) {

            case Event::UART_DATA_RECEIVED:
                // Handle UART data here
                break;

            case Event::MQTT_MESSAGE_RECEIVED:
                if (!hub_zigbee.buff.ParseFromArray(event.data.data(), event.data.size())) {
                    std::cerr << "Failed to parse protobuf message from vector" << std::endl;
                    break;
                }

                convertBufferToZigbee(hub_zigbee);
                break;

            default:
                std::cerr << "Unknown event type" << std::endl;
        }
    }

    return 0;
}
