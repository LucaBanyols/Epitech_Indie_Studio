/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../../include/Input/Plus.hpp"

Plus::Plus()
{
    this->_buttonPlusState = 0;
    this->_btnPlusAction = false;
}

Plus::~Plus()
{
}

const void Plus::setPlusButton()
{
    try
    {
        this->_texturePlusButton = this->_texture->getTexture2D("../src/resources/assets/plus.png");
    }
    catch(Texture2D)
    {
        this->_texturePlusButton = this->_texture->getTexture2D("../../src/resources/assets/plus.png");
    }
    catch(Error &e)
    {
        std::cerr << e.what() << '\n';
    }

    this->_framePlusHeight = (float)this->_texturePlusButton.height / 2;
    this->_sourcePlusRec = {0, 0, (float)this->_texturePlusButton.width, this->_framePlusHeight};
    this->_btnPlusBounds = {1800, 1080 / 2.0f, (float)this->_texturePlusButton.width, this->_framePlusHeight};
}

const void Plus::displayPlusButton() const
{
    this->_texture->setDrawTextureRec(this->_texturePlusButton, this->_sourcePlusRec, this->_btnPlusBounds.x, this->_btnPlusBounds.y);
}

const void Plus::gestionPlusButton(Vector2 mousePoint, Mouse *mouse, Sounds *sounds)
{
    if (mouse->getCollisionPointRec(mousePoint, this->_btnPlusBounds))
    {
        if (mouse->getClickPressed(MOUSE_LEFT_BUTTON))
        {
            this->_buttonPlusState = 2;
            sounds->playSoundClickButton();
        }
        else
            this->_buttonPlusState = 1;
        if (mouse->getClickReleased(MOUSE_LEFT_BUTTON))
        {
            this->_btnPlusAction = true;
        }
    }
    else
        this->_buttonPlusState = 0;
    _sourcePlusRec.y = _buttonPlusState * _framePlusHeight;
}

const void Plus::deletePlusButton() const
{
    this->_texture->setUnloadTexture(this->_texturePlusButton);
}
