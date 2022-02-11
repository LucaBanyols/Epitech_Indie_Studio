/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"

#ifndef ARROWLEFT_HPP_
#define ARROWLEFT_HPP_

class ArrowLeft : IComponent
{
public:
    ArrowLeft();
    ~ArrowLeft();
    const void setArrowLeft();
    const void gestionArrowLeft(Vector2 mousePoint, Mouse *mouse);
    const void displayArrowLeft() const;
    const void deleteArrowLeft() const;

    Texture2D _textureArrowLeft;
    Rectangle _sourceArrowLeftRec;
    Rectangle _btnArrowLeftBounds;
    bool _btnArrowLeftAction;
    float _frameArrowLeftHeight;
    int _buttonLeftArrowState;
};

#endif