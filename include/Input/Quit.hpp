/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"

#ifndef QUIT_HPP_
#define QUIT_HPP_

class Quit : IComponent
{
public:
    Quit();
    ~Quit();
    const void setQuitButton();
    const void displayQuitButton() const;
    const void gestionQuitButton(Vector2 mousePoint, Mouse *mouse, Sounds *sounds);
    const void deleteQuitButton() const;

    Texture2D _textureQuitButton;
    Rectangle _sourceQuitRec;
    Rectangle _btnQuitBounds;
    bool _btnQuitAction;
    float _frameQuitHeight;
    int _buttonQuitState;
};

#endif