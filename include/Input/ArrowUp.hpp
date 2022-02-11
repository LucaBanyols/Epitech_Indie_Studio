/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"

#ifndef ARROWUP_HPP_
#define ARROWUP_HPP_

class ArrowUp : IComponent
{
public:
    ArrowUp();
    ~ArrowUp();
    const void setArrowUp();
    const void gestionArrowUp(Vector2 mousePoint, Mouse *mouse);
    const void displayArrowUp() const;
    const void deleteArrowUp() const;

    Texture2D _textureArrowUp;
    Rectangle _sourceArrowUpRec;
    Rectangle _btnArrowUpBounds;
    bool _btnArrowUpAction;
    float _frameArrowUpHeight;
    int _buttonUpArrowState;
};

#endif