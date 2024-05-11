cmake_minimum_required(VERSION 3.0)
project(hub-zigbee)

include_directories(proto/hub proto/zigbee)

include_directories(transport/mqtt)
include_directories(transport/uart)


set(SOURCES 
    main.cc 
    proto/hub/typedef.pb.cc 
    proto/zigbee/zigbee.pb.cc 
    transport/mqtt/mqtt.cc
    transport/uart/uart.cc
)

add_executable(hub-zigbee ${SOURCES})

target_link_libraries(hub-zigbee mosquitto protobuf pthread)
