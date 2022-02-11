/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"

#ifndef MINUS_HPP_
#define MINUS_HPP_

class Minus : IComponent
{
private:
public:
    Minus();
    ~Minus();
    const void setMinusButton();
    const void displayMinusButton() const;
    const void gestionMinusButton(Vector2 mousePoint, Mouse *mouse, Sounds *sounds);
    const void deleteMinusButton() const;

    Texture2D _textureMinusButton;
    Rectangle _sourceMinusRec;
    Rectangle _btnMinusBounds;
    bool _btnMinusAction;
    float _frameMinusHeight;
    int _buttonMinusState;
};

#endif