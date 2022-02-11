/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"

#ifndef KEYEVENT_HPP_
#define KEYEVENT_HPP_

class KeyEvent
{
public:
    KeyEvent();
    ~KeyEvent() = default;
    const bool getIsKeyPressed(int key) const;
    const bool getIsKeyDown(int key) const;
    const void setQuitKey(int key) const;
    const int setNewKeyPressed() const;
};

#endif