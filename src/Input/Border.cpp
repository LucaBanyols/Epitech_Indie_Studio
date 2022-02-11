/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../../include/Input/Border.hpp"

Border::Border()
{
}

Border::~Border()
{
}

const void Border::setBorder()
{
    try
    {
        this->_textureBorder = this->_texture->getTexture2D("../src/resources/assets/border.png");
    }
    catch(Texture2D)
    {
        this->_textureBorder = this->_texture->getTexture2D("../../src/resources/assets/border.png");
    }
    catch(Error &e)
    {
        std::cerr << e.what() << '\n';
    }
}

const void Border::displayBorder(const int x, const int y) const
{
    this->_texture->setDrawTexture(this->_textureBorder, x, y);
}

const void Border::deleteBorder() const
{
    this->_texture->setUnloadTexture(this->_textureBorder);
}
