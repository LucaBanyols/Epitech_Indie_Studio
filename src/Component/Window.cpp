/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Component/Window.hpp"

Windows::Windows()
{
    this->_screenHeight = 1080;
    this->_screenWidth = 1920;
    this->_fps = 60;
    this->title = "Bomberman";
}

// Setter

const void Windows::setClearBackground() const
{
    return (ClearBackground(BLANK));
}

const void Windows::setFps() const
{
    return (SetTargetFPS(this->_fps));
}

// Getter
const bool Windows::getStatusWindow()
{
    return (WindowShouldClose());
}

const int Windows::getScreenHeight() const
{
    return (this->_screenWidth);
}

const int Windows::getScreenWidth() const
{
    return (this->_screenWidth);
}

// Process

const void Windows::displayFps() const
{
    return (DrawFPS(0, 0));
}

const void Windows::initWindow()
{
    setFps();
    return (InitWindow(this->_screenWidth, this->_screenHeight, this->title));
}

// Delete

const void Windows::deleteWindow()
{
    return (CloseWindow());
}