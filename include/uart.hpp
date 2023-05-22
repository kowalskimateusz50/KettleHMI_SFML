#pragma once

// C library headers
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <cstdlib>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

//Uart device settings
#define MAX_READ_SIZE 235
#define DEVICE_PATH "/dev/ttyACM0"
#define BAUD_RATE B115200

//Define device description structure 
struct UartDevice 
{
	char* DevicePath;
	int BaudRate;
	int fd;
	struct termios *tty;
};

int UartInit(struct UartDevice* dev, bool canonic);
int UartRead(struct UartDevice *dev, char *Buffer, size_t BufLen);
int UartWrite(struct UartDevice* dev, char* Buffer, size_t BufLen);
int UartWriteString(struct UartDevice* dev, char* Buffer);
int UartStop(struct UartDevice* dev);