#include <SFML/Graphics.hpp>
#include <iostream>
#include "uart.hpp"

int main()
{
    /* Serial port init */

    

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

        window.clear();
        window.draw(text);
        window.display();
    }
/**/
    return 0;
}