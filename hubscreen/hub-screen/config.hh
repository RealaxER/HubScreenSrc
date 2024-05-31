#pragma once
#include <iostream>
#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <gui_guider.h>
#include <hub/typedef.pb.h>
#include <mqtt/mqtt.h>

#define DISP_BUF_SIZE (256 * 1024)
#define DEVICE_NAME "hub-screen"
#define BROKER "127.0.0.1"
#define PORT 1883
#define SUB "hub/screen"

class HubScreen_t {
public:
    lv_style_t  style;
    lv_ui guider_ui;
    Mqtt_t transport;
    Buffer buffer;

    HubScreen_t(const char *id) : transport(id) {
        this->buff = Buffer();
    }
};

HubScreen_t hub_screen(DEVICE_NAME);

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define LOG_INFO(...) std::cout << ANSI_COLOR_GREEN << "[INFO] " << ANSI_COLOR_RESET << __VA_ARGS__ << std::endl
#define LOG_ERR(...) std::cout << ANSI_COLOR_RED << "[ERR] " << ANSI_COLOR_RESET << __VA_ARGS__ << std::endl

