#include <SFML/Graphics.hpp>
#include <iostream>
#include "uart.hpp"


#define LOOPBACK_FORMAT "loopback: %s\r\n"
#define LOOPBACK_FORMAT_LEN strlen(LOOPBACK_FORMAT)
#define MAX_LOOPBACK_SIZE MAX_READ_SIZE + LOOPBACK_FORMAT_LEN

#define debug(x) std::cout << x << std::endl

int main()
{

    /* Serial port init */

     
    struct UartDevice dev; // Initialize structure of UART device
    int rc; //Status of initialization UART

    //Adjust settings of UART device
    dev.BaudRate = BAUD_RATE;
    dev.DevicePath = DEVICE_PATH;

    //Initializing UART
    rc = UartInit(&dev, false);
	if (rc) {
		return rc;
	}

    debug("Uart port sucessfully initialized"); 

    /* UART String containers*/
    char ReadData[MAX_READ_SIZE];
	char LoopbackData[MAX_LOOPBACK_SIZE];
	size_t ReadDataLength;

    while (true)
    {


        ReadDataLength = UartRead(&dev, ReadData, MAX_READ_SIZE);

        if (ReadDataLength > 0)
        {

            debug("Read:" << ReadData);
        }
        
    }


    /* Close UART*/
    UartStop(&dev);

    return 0;
}