/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Component/KeyEvent.hpp"

KeyEvent::KeyEvent()
{
}

const bool KeyEvent::getIsKeyDown(int key) const
{
    return (IsKeyDown(key));
}

const bool KeyEvent::getIsKeyPressed(int key) const
{
    return (IsKeyPressed(key));
}

const void KeyEvent::setQuitKey(int key) const
{
    return (SetExitKey(key));
}

const int KeyEvent::setNewKeyPressed() const
{
    return (GetKeyPressed());
}