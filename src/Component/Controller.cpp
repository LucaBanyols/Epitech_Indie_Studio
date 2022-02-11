/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-dylan1.faure
** File description:
** Controller
*/

#include "../../include/Component/Controller.hpp"

Controller::Controller()
{
}

Controller::~Controller()
{
}

const float Controller::GetControllerAxisMovement(int gamepad, int axis) const
{
    return (GetGamepadAxisMovement(gamepad, axis));
}

const int Controller::GetControllerButtonPressed() const
{
    return (GetGamepadButtonPressed());
}

const bool Controller::IsControllerAvailable(int gamepad) const
{
    return (IsGamepadAvailable(gamepad));
}

const bool Controller::IsControllerName(int gamepad, const char *name) const
{
    return (IsGamepadName(gamepad,name));
}

const int Controller::GetControllerAxisCount(int gamepad) const
{
    return (GetGamepadAxisCount(gamepad));
}