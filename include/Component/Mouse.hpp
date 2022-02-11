/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"

#ifndef MOUSE_HPP_
#define MOUSE_HPP_

class Mouse
{
public:
    Mouse();
    ~Mouse() = default;
    const Vector2 getMousePos() const;
    const bool getClickPressed(int button) const;
    const bool getClickDown(int button) const;
    const bool getClickReleased(int button) const;
    const bool getCollisionPointRec(Vector2 vector, Rectangle rectangle) const;
};

#endif