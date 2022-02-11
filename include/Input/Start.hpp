/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"

#ifndef START_HPP_
#define START_HPP_

class Start : IComponent
{
public:
    Start();
    ~Start();
    const void setStartButton();
    const void displayStartButton() const;
    const void gestionStartButton(Vector2 mousePoint, Mouse *mouse, Sounds *sounds);
    const void deleteStartButton() const;

    Texture2D _textureStartButton;
    Rectangle _sourceStartRec;
    Rectangle _btnStartBounds;
    bool _btnStartAction;
    float _frameStartHeight;
    int _buttonStartState;
};

#endif