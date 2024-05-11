#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include "mqtt.hh"
#include "uart.hh"
#include "config.hh"

#include "zigbee.pb.h"
#include "typedef.pb.h"


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
    Zigbee_t zigbee_pt;
    Buffer buff_pt;
    Mqtt_t transport;
    Uart_t uart;

    HubDevice_t(const char *id, const char *port)
        : transport(id), uart(port) {
        this->zigbee_pt = Zigbee_t();
        this->buff_pt = Buffer();
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
                // Handle MQTT message here
                break;
            default:
                std::cerr << "Unknown event type" << std::endl;
        }
    }

    return 0;
}
