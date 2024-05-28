#pragma once
#include <iostream>

#define DEVICE_NAME "hub-zigbee"
#define PATH_SEZIAL "/dev/ttyAMA0"
#define BROKER "127.0.0.1"
#define PORT 1883
#define SUB "hub/zigbee"

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define LOG_INFO(...) std::cout << ANSI_COLOR_GREEN << "[INFO] " << ANSI_COLOR_RESET << __VA_ARGS__ << std::endl
#define LOG_ERR(...) std::cout << ANSI_COLOR_RED << "[ERR] " << ANSI_COLOR_RESET << __VA_ARGS__ << std::endl

