/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "Start.hpp"
#include "Quit.hpp"
#include "Minus.hpp"
#include "Plus.hpp"
#include "Setting.hpp"
#include "HowToPlay.hpp"

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

class Button
{  
public:
    Button();
    ~Button();
    const void setButtons();
    const void displayButton() const;
    const void gestionButton(Vector2 &mousePoint, Mouse *mouse, Sounds *sounds);
    const void deleteButtons() const;

    // Start button
    Start *_startButton;

    // Quit button
    Quit *_quitButton;

    // Minus
    Minus *_minusButton;

    // Plus
    Plus *_plusButton;

    // HowToPlay
    HowToPlay *_howtoplay;

    // Setting
    Setting *_settingButton;

    int _isHoverButton;
    int *_arrayHoverButton;
};

#endif