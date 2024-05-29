#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <string.h>
#include "mqtt.hh"
#include "uart.hh"
#include "config.hh"

#include "ble.pb.h"
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
    Ble_t ble;
    Buffer buff;
    Mqtt_t transport;
    Uart_t uart;

    HubDevice_t(const char *id, const char *port)
        : transport(id), uart(port) {
        this->ble = Ble_t();
        this->buff = Buffer();
	uart.connect(B115200);
    }
};

std::vector<std::vector<uint8_t>> extract_uart(const uint8_t *input, size_t size) {
    std::vector<std::vector<uint8_t>> results;
    std::vector<uint8_t> current_message;
    bool in_message = false;

    for (size_t i = 0; i < size; ++i) {
        if (input[i] == 0xFF && i + 1 < size && input[i + 1] == 0xFF) {
            if (in_message && !current_message.empty()) {
                results.push_back(current_message);
                current_message.clear();
            }
            in_message = true;
            ++i; // Skip the next 0xFF
        } else if (in_message) {
            current_message.push_back(input[i]);
        }
    }

    if (!current_message.empty()) {
        results.push_back(current_message);
    }

    return results;
}


void uart_callback(const unsigned char *data, int length) {
    std::lock_guard<std::mutex> lock(mtx);

    std::vector<uint8_t> vec_data(data, data + length);
    eventQueue.push(Event(Event::UART_DATA_RECEIVED, "", vec_data));
    cv.notify_one();
    LOG_INFO("<-- " << "UART" << " : " << data);
}

void mqtt_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message) {
    std::lock_guard<std::mutex> lock(mtx);
    LOG_INFO("<-- " << message->topic << " : " << message->payload);
    std::vector<uint8_t> vec_data((const uint8_t *)message->payload, (const uint8_t *)message->payload + message->payloadlen);
    eventQueue.push(Event(Event::MQTT_MESSAGE_RECEIVED, message->topic, vec_data));
    cv.notify_one();
}


void convertBufferToWifi(HubDevice_t device){
    uint8_t ble_arr[MAX_BUFFER];
    memset(ble_arr , 0, sizeof(ble_arr));

    if(device.buff.sender() != User_t::Hub || device.buff.receiver() != User_t::Ble ) {
        return;
    }

    if(device.buff.sw_size() == 0){
        Ble_t ble;
        ble.set_sync(true);
        ble.SerializeToArray(ble_arr, sizeof(ble_arr));
        LOG_INFO("Packet sync to ble");
        LOG_INFO("--> " << "UART" << " : " << ble.DebugString() );
        // start byte data
        device.uart.send(ble_arr, ble.ByteSizeLong());
	for(int i =0;i<ble.ByteSizeLong(); i++){
		printf("%d ", ble_arr[i]);
	}
	printf("\n");

    }

    for (int i = 0; i < device.buff.sw_size(); ++i) {
        Sw_t sw = device.buff.sw(i);

        Ble_t ble;
        SwBle_t* sw_ble = ble.mutable_sw();
        sw_ble->set_endpoint(sw.ep());
        sw_ble->set_deviceid(sw.mac());
        sw_ble->set_status(sw.status());
        ble.SerializeToArray(ble_arr, sizeof(ble_arr));

        LOG_INFO("--> " << "UART" << " : " << ble.DebugString() );
        // start byte data
        device.uart.send(ble_arr, ble.ByteSizeLong());
        // end byte data
        uint8_t end[2] = {0xff, 0xff};
        device.uart.send(end, 2);
    }
}

void convertBleToBuffer(HubDevice_t device){
    if(device.ble.has_sw()){
        Buffer buffer;
        buffer.set_sender(User_t::Ble);
        buffer.set_receiver(User_t::Hub);
        buffer.set_cotroller(User_t::Ble);
	buffer.set_mac_hub("8xff");

        uint8_t buffer_arr[MAX_BUFFER];

        // Convert SwZb_t to Sw_t and add to the buffer
        Sw_t* sw = buffer.add_sw();
        sw->set_mac(device.ble.sw().deviceid());
        sw->set_ep(device.ble.sw().endpoint());
        sw->set_status(device.ble.sw().status());
	sw->set_name("led " + std::to_string(device.ble.sw().endpoint()));

        buffer.SerializeToArray(buffer_arr, sizeof(buffer_arr));

        const char * topic = "hub/ble";
        LOG_INFO("--> " << topic << " : " << buffer.DebugString());
        device.transport.publish(topic, reinterpret_cast<const unsigned char*>(buffer_arr), buffer.ByteSizeLong());
    }
}

int main(void) {
    // Test MQTT
    __test_mqtt();
    // Test UART

    // Setup HubDevice_t
    HubDevice_t hub_ble(DEVICE_NAME, PATH_SEZIAL);

    // Set MQTT
    hub_ble.transport.set_callback(mqtt_callback);
    hub_ble.transport.setup(BROKER, PORT, 45);
    hub_ble.transport.subscribe(SUB , 1);
    hub_ble.transport.connect();
    // Set UART
    std::vector<std::vector<uint8_t>> messages;

    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !eventQueue.empty(); });
        Event event = eventQueue.front();
        eventQueue.pop();
        lock.unlock();

        switch (event.type) {
		    case Event::UART_DATA_RECEIVED:
                LOG_INFO("In received data");
                messages = extract_uart(event.data.data(), event.data.size());
                std::cout << "Extracted messages:" << std::endl;
                for (const auto& message : messages) {
                    if (!hub_ble.ble.ParseFromArray(message.data(), message.size())) {
                        std::cerr << "Failed to parse ble message from vector" << std::endl;
                        break;
                    }
                    convertBleToBuffer(hub_ble);
                }
                break;

            case Event::MQTT_MESSAGE_RECEIVED:
                if (!hub_ble.buff.ParseFromArray(event.data.data(), event.data.size())) {
                    std::cerr << "Failed to parse protobuf message from vector" << std::endl;
                    break;
                }

                convertBufferToWifi(hub_ble);
                break;

            default:
                std::cerr << "Unknown event type" << std::endl;
        }
    }

    return 0;
}
