/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"

#ifndef ARROWRIGHT_HPP_
#define ARROWRIGHT_HPP_

class ArrowRight : IComponent
{
public:
    ArrowRight();
    ~ArrowRight();
    const void setArrowRight();
    const void gestionArrowRight(Vector2 mousePoint, Mouse *mouse);
    const void displayArrowRight() const;
    const void deleteArrowRight() const;

    Texture2D _textureArrowRight;
    Rectangle _sourceArrowRightRec;
    Rectangle _btnArrowRightBounds;
    bool _btnArrowRightAction;
    float _frameArrowRightHeight;
    int _buttonRightArrowState;
};

#endif