#include <SFML/Graphics.hpp>
#include <iostream>
#include "uart.hpp"


#define LOOPBACK_FORMAT "loopback: %s\r\n"
#define LOOPBACK_FORMAT_LEN strlen(LOOPBACK_FORMAT)
#define MAX_LOOPBACK_SIZE MAX_READ_SIZE + LOOPBACK_FORMAT_LEN

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

    /* UART String containers*/
    char ReadData[MAX_READ_SIZE];
	char LoopbackData[MAX_LOOPBACK_SIZE];
	size_t ReadDataLength;

    /* Send some demo data to test uart*/
    UartWriteString(&dev, "Hello UART\r\n");


    
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Hello kettle HMI!");
    sf::CircleShape shape(100.f);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("./fonts/Arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Hello UART!", font, 50);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        { 
            if (event.type == sf::Event::Closed)
                window.close();
        } 
    //UART Reading 
   ReadDataLength = UartRead(&dev, ReadData, MAX_READ_SIZE);
/*
    if(ReadDataLength>0)
    {
        std::cout << "Recived data: " << ReadData << std::endl;
    }
*/ 

    //SFML Window interface
        window.clear();
        window.draw(text);
        window.display();
    }

    /* Close UART*/
    UartStop(&dev);

    return 0;
}