#include <SFML/Graphics.hpp>
#include <iostream>
#include "uart.hpp"
#include "defines.hpp"
#include "button.hpp"

int main()
{
#ifndef DISABLE_UART
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
#endif

    /*Window definition  */
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Kettle HMI");

    /* Loading and displaying background  */
    sf::Texture Background;
    Background.loadFromFile("images/Background.png");
    sf::Sprite s(Background);

    /*Loading font*/
    sf::Font arial;
    if (!arial.loadFromFile("fonts/arial.ttf"))
    {
        debug("Error during loading font");
    }
    /* Declare and parametrize some test text*/
    
	sf::Text koniec("Game Over", arial, 12);
	koniec.setPosition(140, 160);
	koniec.setColor(sf::Color::Red);
    

    //Button object declare
    Button GreenButton(0.1,0.1,50,100,"Hello");


#ifndef DISABLE_UART
    debug("Uart port sucessfully initialized"); 

    /* UART String containers*/
    char ReadData[MAX_READ_SIZE];
	char LoopbackData[MAX_LOOPBACK_SIZE];
	size_t ReadDataLength;
#endif

    while (window.isOpen())
    {
        
#ifndef DISABLE_UART
        ReadDataLength = UartRead(&dev, ReadData, MAX_READ_SIZE);

        if (ReadDataLength > 0)
        {
            debug("Read:" << ReadData);
        }
#endif
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    

        window.clear();


        
        
        
        window.draw(s);
        window.draw(koniec);
        //window.draw(Butt);
        window.draw(GreenButton.DrawButton());
        window.draw(GreenButton.DrawTextOnButton());

        window.display();
        
    }

#ifndef DISABLE_UART
    /* Close UART*/
    UartStop(&dev);
#endif
    return 0;
}