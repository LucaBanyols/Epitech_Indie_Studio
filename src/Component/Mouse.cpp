/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Component/Mouse.hpp"

Mouse::Mouse()
{
}

const Vector2 Mouse::getMousePos() const
{
    return (GetMousePosition());
}

const bool Mouse::getClickDown(int button) const
{
    return (IsMouseButtonDown(button));
}

const bool Mouse::getClickPressed(int button) const
{
    return (IsMouseButtonPressed(button));
}

const bool Mouse::getClickReleased(int button) const
{
    return (IsMouseButtonReleased(button));
}

const bool Mouse::getCollisionPointRec(Vector2 vector, Rectangle rectangle) const
{
    return (CheckCollisionPointRec(vector, rectangle));
}