#pragma once 
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h> 

class Uart_t {
private:
    int fd;
    struct termios options; /* Serial ports setting */
    pthread_t thread_id; // ID của thread
public:
    Uart_t(const char * port);
    int connect(int baud);
    int disconnect(void);

};