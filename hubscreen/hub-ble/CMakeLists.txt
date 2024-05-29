cmake_minimum_required(VERSION 3.0)
project(hub-ble)

include_directories(proto/hub proto/ble)

include_directories(transport/mqtt)
include_directories(transport/uart)


set(SOURCES 
    main.cc 
    proto/hub/typedef.pb.cc 
    proto/ble/ble.pb.cc 
    transport/mqtt/mqtt.cc
    transport/uart/uart.cc
)

add_executable(hub-ble ${SOURCES})

target_link_libraries(hub-ble mosquitto protobuf pthread)
