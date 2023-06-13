#include <SFML/Graphics.hpp>
#include <iostream>
#include "defines.hpp"
class Button
{
    public: 
        Button(float iScaleX, float iScaleY, float iPositionX, float iPositionY);
        sf::Sprite DrawButton();

    private:

    /* Sprites parameters */
        float pScaleX;
        float pScaleY;
        float pPositionX;
        float pPositionY;

    /* Grapics objects */
        sf::Texture ButtonTexture;
        sf::Sprite ButtonSprite;

};