#include <uart.hh>
#include <string.h>
#include <stdio.h>

#define MAX_DATA_LENGTH 255
uint8_t buffer[MAX_DATA_LENGTH];

extern void uart_callback(const uint8_t * data, int length);

void* uart_handle(void* arg) {
    int fd = *((int*) arg);
    ssize_t bytes_read;

    while (1) {
        bytes_read = read(fd, buffer, MAX_DATA_LENGTH);
        if (bytes_read > 0) {
	    for(int i =0; i<bytes_read;i++){
	    	printf("%d ", buffer[i]);
		}
	    printf("\n");
	    uart_callback(buffer, bytes_read);
	    memset(buffer, 0, sizeof(buffer));
        }
        sleep(5);
    }
    return NULL;
}

int Uart_t::send(uint8_t * data, int len) {
	return write(fd, data, len);
}

Uart_t::Uart_t(const char* port){
    fd = open(port, O_RDWR | O_NDELAY | O_NOCTTY);
    if (fd < 0) {
        perror("Error opening serial port");
    }
}

Uart_t::~Uart_t(){
	std::cout <<"huy" << std::endl;
}

int Uart_t::connect(int baud) {
    tcgetattr(this->fd, &this->options);
    this->options.c_cflag = baud | CS8 | CLOCAL | CREAD;
    this->options.c_iflag = IGNPAR;
    this->options.c_oflag = 0;
    this->options.c_lflag = 0;
    tcflush(this->fd, TCIFLUSH);
    tcsetattr(this->fd, TCSANOW, &this->options);

    if (pthread_create(&thread_id, NULL, uart_handle, &fd)) {
        perror("Error creating thread");
        return -1;
    }
//    pthread_join(thread_id, NULL);

    return 0;
}

int Uart_t::disconnect() {
    pthread_cancel(thread_id);
    close(fd);
}
