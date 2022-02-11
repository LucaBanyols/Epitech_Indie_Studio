/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "Background.hpp"
#include "Button.hpp"
#include "ChangePlayer.hpp"
#include "Key.hpp"
#include "ChangeSizeMap.hpp"
#include "SplashScreen.hpp"

#ifndef INPUTHANDLER_HPP_
#define INPUTHANDLER_HPP_

class InputHandler
{
public:
    Background *_background = new Background;
    Button *_button = new Button;
    ChangePlayer *_changePlayer = new ChangePlayer;
    Key *_key = new Key;
    SplashScreen *_splashScreen = new SplashScreen;
    ChangeSizeMap *_changeSizeMap = new ChangeSizeMap;
    Controller *_controller1 = new Controller();
    Controller *_controller2 = new Controller();
    Controller *_controller3 = new Controller();
    Controller *_controller4 = new Controller();


    InputHandler() {};
    virtual ~InputHandler()
    {
        delete (this->_background);
        delete (this->_button);
        delete (this->_changePlayer);
        delete (this->_changeSizeMap);
        delete (this->_key);
        delete (this->_splashScreen);
    };
};

#endif