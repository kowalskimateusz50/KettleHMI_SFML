#include "button.hpp"

Button::Button(float iScaleX, float iScaleY, float iPositionX, float iPositionY)
{
    /* Copy inputs sprite parameters to class parameters */
    Button::pScaleX = iScaleX;
    Button::pScaleY = iScaleY;
    Button::pPositionX = iPositionX;
    Button::pPositionY = iPositionY;

    /* Object texture from file */
    if (!Button::ButtonTexture.loadFromFile("images/GreenButton.png"))
    {
        debug("Error during loading image");
    }

    /* Create sprite object with loaded texture */
    Button::ButtonSprite.setTexture(Button::ButtonTexture);

    /* Set sprite attributes */
    /* Set scale */
    Button::ButtonSprite.setScale(Button::pScaleX, Button::pScaleY);

    /* Set position */
    Button::ButtonSprite.setPosition(Button::pPositionX, Button::pPositionY);

}
sf::Sprite Button::DrawButton()
{
    return Button::ButtonSprite;
}