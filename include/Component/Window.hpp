/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

class Windows
{
protected:
    int _screenWidth;
    int _screenHeight;
    int _fps;
    const char *title;

public:
    Windows();
    ~Windows() = default;
    const void initWindow();
    const void setClearBackground() const;
    const void setFps() const;
    const int getScreenWidth() const;
    const int getScreenHeight() const;
    const void deleteWindow();
    const bool getStatusWindow();
    const void displayFps() const;
};

#endif