#include <SFML/Graphics.hpp>
#include <iostream>
#include "defines.hpp"
class Button
{
    public: 
        Button(float iScaleX, float iScaleY, float iPositionX, float iPositionY, std::string iText);
        sf::Sprite DrawButton();
        sf::Text DrawTextOnButton();

    private:

    /* Sprites parameters */
        float pScaleX;
        float pScaleY;
        float pPositionX;
        float pPositionY;
        std::string pText;

    /* Grapics objects */
        sf::Texture ButtonTexture;
        sf::Sprite ButtonSprite;
        sf::Font arial;
        sf::Text ButtonText;
};