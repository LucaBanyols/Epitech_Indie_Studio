/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"

#ifndef ARROWDOWN_HPP_
#define ARROWDOWN_HPP_

class ArrowDown : IComponent
{
public:
    ArrowDown();
    ~ArrowDown();
    const void setArrowDown();
    const void gestionArrowDown(Vector2 mousePoint, Mouse *mouse);
    const void displayArrowDown() const;
    const void deleteArrowDown() const;

    Texture2D _textureArrowDown;
    Rectangle _sourceArrowDownRec;
    Rectangle _btnArrowDownBounds;
    bool _btnArrowDownAction;
    float _frameArrowDownHeight;
    int _buttonDownArrowState;
};

#endif