/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Input/ArrowUp.hpp"

ArrowUp::ArrowUp()
{
    this->_btnArrowUpAction = false;
    this->_buttonUpArrowState = 0;
}

ArrowUp::~ArrowUp()
{
}

const void ArrowUp::setArrowUp()
{
    try
    {
        this->_textureArrowUp = this->_texture->getTexture2D("../src/resources/assets/arrow_up.png");
    }
    catch (Texture2D)
    {
        this->_textureArrowUp = this->_texture->getTexture2D("../../src/resources/assets/arrow_up.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }

    this->_frameArrowUpHeight = (float)this->_textureArrowUp.height / 2;
    this->_sourceArrowUpRec = {0, 0, (float)this->_textureArrowUp.width, this->_frameArrowUpHeight};
    this->_btnArrowUpBounds = {1540, 790, (float)this->_textureArrowUp.width, this->_frameArrowUpHeight};
}

const void ArrowUp::gestionArrowUp(Vector2 mousePoint, Mouse *mouse)
{
    if (mouse->getCollisionPointRec(mousePoint, this->_btnArrowUpBounds))
    {
        if (mouse->getClickDown(MOUSE_LEFT_BUTTON))
            this->_buttonUpArrowState = 2;
        else
            this->_buttonUpArrowState = 1;
        if (mouse->getClickPressed(MOUSE_LEFT_BUTTON))
            this->_btnArrowUpAction = true;
    }
    else
        this->_buttonUpArrowState = 0;
    this->_sourceArrowUpRec.y = this->_buttonUpArrowState * this->_frameArrowUpHeight;
}

const void ArrowUp::displayArrowUp() const
{
    this->_texture->setDrawTextureRec(this->_textureArrowUp, this->_sourceArrowUpRec, this->_btnArrowUpBounds.x, this->_btnArrowUpBounds.y);
}

const void ArrowUp::deleteArrowUp() const
{
    this->_texture->setUnloadTexture(this->_textureArrowUp);
}
