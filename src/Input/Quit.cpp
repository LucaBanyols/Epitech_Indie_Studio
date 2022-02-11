/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../../include/Input/Quit.hpp"

Quit::Quit()
{
    this->_buttonQuitState = 0;
    this->_btnQuitAction = false;
}

Quit::~Quit()
{
}

const void Quit::setQuitButton()
{
    try
    {
        this->_textureQuitButton = this->_texture->getTexture2D("../src/resources/assets/quit_button.png");
    }
    catch(Texture2D)
    {
        this->_textureQuitButton = this->_texture->getTexture2D("../../src/resources/assets/quit_button.png");
    }
    catch(Error &e)
    {
        std::cerr << e.what() << '\n';
    }

    this->_frameQuitHeight = (float)this->_textureQuitButton.height / 2;
    this->_sourceQuitRec = {0, 0, (float)this->_textureQuitButton.width, this->_frameQuitHeight};
    this->_btnQuitBounds = {10, 10, (float)this->_textureQuitButton.width, this->_frameQuitHeight};
}

const void Quit::displayQuitButton() const
{
    this->_texture->setDrawTextureRec(this->_textureQuitButton, this->_sourceQuitRec, this->_btnQuitBounds.x, this->_btnQuitBounds.y);
}

const void Quit::gestionQuitButton(Vector2 mousePoint, Mouse *mouse, Sounds *sounds)
{
    if (mouse->getCollisionPointRec(mousePoint, this->_btnQuitBounds))
    {
        if (mouse->getClickPressed(MOUSE_LEFT_BUTTON))
        {
            this->_buttonQuitState = 2;
            sounds->playSoundClickButton();
        }
        else
            this->_buttonQuitState = 1;
        if (mouse->getClickReleased(MOUSE_LEFT_BUTTON))
        {
            this->_btnQuitAction = true;
        }
    }
    else
        this->_buttonQuitState = 0;
    _sourceQuitRec.y = _buttonQuitState * _frameQuitHeight;
}

const void Quit::deleteQuitButton() const
{
    this->_texture->setUnloadTexture(this->_textureQuitButton);
}
