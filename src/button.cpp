#include "button.hpp"

Button::Button(float iScaleX, float iScaleY, float iPositionX, float iPositionY, std::string iText)
{
    /* Copy inputs sprite parameters to class parameters */
    Button::pScaleX = iScaleX;
    Button::pScaleY = iScaleY;
    Button::pPositionX = iPositionX;
    Button::pPositionY = iPositionY;
    Button::pText = iText;

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

    /* Load font */
    if (!Button::arial.loadFromFile("fonts/arial.ttf"))
    {
        debug("Error during loading font");
    }

    /* Declare and parametrize text on button */
    Button::ButtonText.setFont(Button::arial);
    Button::ButtonText.setPosition(Button::pPositionX+60, Button::pPositionY+10);
    Button::ButtonText.setString(Button::pText);
    Button::ButtonText.setCharacterSize((int)400*Button::pScaleY);
    Button::ButtonText.setColor(sf::Color::Blue);
}
sf::Sprite Button::DrawButton()
{
    return Button::ButtonSprite;
}

sf::Text Button::DrawTextOnButton()
{
    return Button::ButtonText;
}