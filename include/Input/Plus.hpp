/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"

#ifndef PLUS_HPP_
#define PLUS_HPP_

class Plus : IComponent
{
private:
public:
    Plus();
    ~Plus();
    const void setPlusButton();
    const void displayPlusButton() const;
    const void gestionPlusButton(Vector2 mousePoint, Mouse *mouse, Sounds *sounds);
    const void deletePlusButton() const;

    Texture2D _texturePlusButton;
    Rectangle _sourcePlusRec;
    Rectangle _btnPlusBounds;
    bool _btnPlusAction;
    float _framePlusHeight;
    int _buttonPlusState;
};

#endif
