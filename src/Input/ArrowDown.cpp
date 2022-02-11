/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Input/ArrowDown.hpp"

ArrowDown::ArrowDown()
{
    this->_btnArrowDownAction = false;
    this->_buttonDownArrowState = 0;
}

ArrowDown::~ArrowDown()
{
}

const void ArrowDown::setArrowDown()
{
    try
    {
        this->_textureArrowDown = this->_texture->getTexture2D("../src/resources/assets/arrow_down.png");
    }
    catch (Texture2D)
    {
        this->_textureArrowDown = this->_texture->getTexture2D("../../src/resources/assets/arrow_down.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }

    this->_frameArrowDownHeight = (float)this->_textureArrowDown.height / 2;
    this->_sourceArrowDownRec = {0, 0, (float)this->_textureArrowDown.width, this->_frameArrowDownHeight};
    this->_btnArrowDownBounds = {1540, 955, (float)this->_textureArrowDown.width, this->_frameArrowDownHeight};
}

const void ArrowDown::gestionArrowDown(Vector2 mousePoint, Mouse *mouse)
{
    if (mouse->getCollisionPointRec(mousePoint, this->_btnArrowDownBounds))
    {
        if (mouse->getClickDown(MOUSE_LEFT_BUTTON))
            this->_buttonDownArrowState = 2;
        else
            this->_buttonDownArrowState = 1;
        if (mouse->getClickPressed(MOUSE_LEFT_BUTTON))
            this->_btnArrowDownAction = true;
    }
    else
        this->_buttonDownArrowState = 0;
    this->_sourceArrowDownRec.y = this->_buttonDownArrowState * this->_frameArrowDownHeight;
}

const void ArrowDown::displayArrowDown() const
{
    this->_texture->setDrawTextureRec(this->_textureArrowDown, this->_sourceArrowDownRec, this->_btnArrowDownBounds.x, this->_btnArrowDownBounds.y);
}

const void ArrowDown::deleteArrowDown() const
{
    this->_texture->setUnloadTexture(this->_textureArrowDown);
}
