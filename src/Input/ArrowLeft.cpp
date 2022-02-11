/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Input/ArrowLeft.hpp"

ArrowLeft::ArrowLeft()
{
    this->_btnArrowLeftAction = false;
    this->_buttonLeftArrowState = 0;
}

ArrowLeft::~ArrowLeft()
{
}

const void ArrowLeft::setArrowLeft()
{
    try
    {
        this->_textureArrowLeft = this->_texture->getTexture2D("../src/resources/assets/arrow_left.png");
    }
    catch (Texture2D)
    {
        this->_textureArrowLeft = this->_texture->getTexture2D("../../src/resources/assets/arrow_left.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }

    this->_frameArrowLeftHeight = (float)this->_textureArrowLeft.height / 2;
    this->_sourceArrowLeftRec = {0, 0, (float)this->_textureArrowLeft.width, this->_frameArrowLeftHeight};
    this->_btnArrowLeftBounds = {0, 825, (float)this->_textureArrowLeft.width, this->_frameArrowLeftHeight};
}

const void ArrowLeft::gestionArrowLeft(Vector2 mousePoint, Mouse *mouse)
{
    if (mouse->getCollisionPointRec(mousePoint, this->_btnArrowLeftBounds))
    {
        if (mouse->getClickDown(MOUSE_LEFT_BUTTON))
            this->_buttonLeftArrowState = 2;
        else
            this->_buttonLeftArrowState = 1;
        if (mouse->getClickPressed(MOUSE_LEFT_BUTTON))
            this->_btnArrowLeftAction = true;
    }
    else
        this->_buttonLeftArrowState = 0;
    this->_sourceArrowLeftRec.y = this->_buttonLeftArrowState * this->_frameArrowLeftHeight;
}

const void ArrowLeft::displayArrowLeft() const
{
    this->_texture->setDrawTextureRec(this->_textureArrowLeft, this->_sourceArrowLeftRec, this->_btnArrowLeftBounds.x, this->_btnArrowLeftBounds.y);
}

const void ArrowLeft::deleteArrowLeft() const
{
    this->_texture->setUnloadTexture(this->_textureArrowLeft);
}
