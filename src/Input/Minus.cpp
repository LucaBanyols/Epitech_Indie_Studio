/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../../include/Input/Minus.hpp"

Minus::Minus()
{
    this->_buttonMinusState = 0;
    this->_btnMinusAction = false;
}

Minus::~Minus()
{
}

const void Minus::setMinusButton()
{
    try
    {
        this->_textureMinusButton = this->_texture->getTexture2D("../src/resources/assets/minus.png");
    }
    catch(Texture2D)
    {
        this->_textureMinusButton = this->_texture->getTexture2D("../../src/resources/assets/minus.png");
    }
    catch(Error &e)
    {
        std::cerr << e.what() << '\n';
    }

    this->_frameMinusHeight = (float)this->_textureMinusButton.height / 2;
    this->_sourceMinusRec = {0, 0, (float)this->_textureMinusButton.width, this->_frameMinusHeight};
    this->_btnMinusBounds = {1800, 1080 / 2.0f - this->_textureMinusButton.height, (float)this->_textureMinusButton.width, this->_frameMinusHeight};
}

const void Minus::displayMinusButton() const
{
    this->_texture->setDrawTextureRec(this->_textureMinusButton, this->_sourceMinusRec, this->_btnMinusBounds.x, this->_btnMinusBounds.y);
}

const void Minus::gestionMinusButton(Vector2 mousePoint, Mouse *mouse, Sounds *sounds)
{
    if (mouse->getCollisionPointRec(mousePoint, this->_btnMinusBounds))
    {
        if (mouse->getClickPressed(MOUSE_LEFT_BUTTON))
        {
            this->_buttonMinusState = 2;
            sounds->playSoundClickButton();
        }
        else
            this->_buttonMinusState = 1;
        if (mouse->getClickReleased(MOUSE_LEFT_BUTTON))
        {
            this->_btnMinusAction = true;
        }
    }
    else
        this->_buttonMinusState = 0;
    _sourceMinusRec.y = _buttonMinusState * _frameMinusHeight;
}

const void Minus::deleteMinusButton() const
{
    this->_texture->setUnloadTexture(this->_textureMinusButton);
}
