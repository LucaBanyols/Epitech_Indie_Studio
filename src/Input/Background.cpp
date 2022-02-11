/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../../include/Input/Background.hpp"

Background::Background()
{
}

// Setter

const void Background::setBackground()
{
    try
    {
        this->_textureBackground = this->_texture->getTexture2D("../src/resources/assets/background_menu.png");
    }
    catch(Texture2D)
    {
        this->_textureBackground = this->_texture->getTexture2D("../../src/resources/assets/background_menu.png");
    }
    catch(Error &e)
    {
        std::cerr << e.what() << '\n';
    }
}

const void Background::setEndBackground()
{
    try
    {
        this->_textureEndBackground = this->_texture->getTexture2D("../src/resources/assets/background_end.png");
    }
    catch (Texture2D)
    {
        this->_textureEndBackground = this->_texture->getTexture2D("../../src/resources/assets/background_end.png");
    }
    catch(Error &e)
    {
        std::cerr << e.what() << '\n';
    }
}

const void Background::setGameBackground()
{
    try
    {
        this->_imgBackground = this->_images->getImage("../src/resources/assets/game_background.png");
    }
    catch (Image)
    {
        this->_imgBackground = this->_images->getImage("../../src/resources/assets/game_background.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }

    this->_textureGameBackground = this->_texture->getTexture2DFromImage(this->_imgBackground);
    this->_images->deleteImage(this->_imgBackground);
}

// Display

const void Background::displayEndBackground() const
{
    this->_texture->setDrawTexture(this->_textureEndBackground, 0, 0);
}

const void Background::displayBackground() const
{
    this->_texture->setDrawTexture(this->_textureBackground, 0, 0);
}

const void Background::displayGameBackground() const
{
    this->_texture->setDrawTexture(this->_textureGameBackground, 0, 0);
}

// Delete

const void Background::deleteBackground() const
{
    this->_texture->setUnloadTexture(this->_textureBackgroundChangePlayer);
}

const void Background::deleteEndBackground() const
{
    this->_texture->setUnloadTexture(this->_textureEndBackground);
}

const void Background::deleteGameBackground() const
{
    this->_texture->setUnloadTexture(this->_textureGameBackground);
}