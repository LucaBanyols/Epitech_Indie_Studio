/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Input/ArrowRight.hpp"

ArrowRight::ArrowRight()
{
    this->_btnArrowRightAction = false;
    this->_buttonRightArrowState = 0;
}

ArrowRight::~ArrowRight()
{
}

const void ArrowRight::setArrowRight()
{
    try
    {
        this->_textureArrowRight = this->_texture->getTexture2D("../src/resources/assets/arrow_right.png");
    }
    catch (Texture2D)
    {
        this->_textureArrowRight = this->_texture->getTexture2D("../../src/resources/assets/arrow_right.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }

    this->_frameArrowRightHeight = (float)this->_textureArrowRight.height / 2;
    this->_sourceArrowRightRec = {0, 0, (float)this->_textureArrowRight.width, this->_frameArrowRightHeight};
    this->_btnArrowRightBounds = {1700, 825, (float)this->_textureArrowRight.width, this->_frameArrowRightHeight};
}

const void ArrowRight::gestionArrowRight(Vector2 mousePoint, Mouse *mouse)
{
    if (mouse->getCollisionPointRec(mousePoint, this->_btnArrowRightBounds))
    {
        if (mouse->getClickDown(MOUSE_LEFT_BUTTON))
            this->_buttonRightArrowState = 2;
        else
            this->_buttonRightArrowState = 1;
        if (mouse->getClickPressed(MOUSE_LEFT_BUTTON))
            this->_btnArrowRightAction = true;
    }
    else
        this->_buttonRightArrowState = 0;
    this->_sourceArrowRightRec.y = this->_buttonRightArrowState * this->_frameArrowRightHeight;
}

const void ArrowRight::displayArrowRight() const
{
    this->_texture->setDrawTextureRec(this->_textureArrowRight, this->_sourceArrowRightRec, this->_btnArrowRightBounds.x, this->_btnArrowRightBounds.y);
}

const void ArrowRight::deleteArrowRight() const
{
    this->_texture->setUnloadTexture(this->_textureArrowRight);
}
