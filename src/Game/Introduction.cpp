/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Game/Introduction.hpp"

Introduction::Introduction()
{
    this->_frameCounter = 0;
    this->_statusIntro = false;
}

const void Introduction::setTextZone()
{
    try
    {
        this->_textZone = this->_texture->getTexture2D("../src/resources/assets/dialog.png");
        this->_backgroundIntro = this->_texture->getTexture2D("../src/resources/assets/background_intro.png");
    }
    catch (Texture2D)
    {
        this->_textZone = this->_texture->getTexture2D("../../src/resources/assets/dialog.png");
        this->_backgroundIntro = this->_texture->getTexture2D("../../src/resources/assets/background_intro.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
}

const void Introduction::gestionIntro()
{
    if (this->_mouse->getClickPressed(MOUSE_LEFT_BUTTON))
    {
        this->_statusIntro = true;
    }
}

const void Introduction::gestionSkip(int tmp)
{
    if (this->_keyEvent->getIsKeyPressed(KEY_SPACE) && tmp != 1)
    {
        this->_frameCounter = 540;
    }
}

const void Introduction::displayIntro()
{
    int tmp = 0;

    this->_keyEvent->setQuitKey(KEY_BACKSPACE);
    setTextZone();
    while (!this->_window->getStatusWindow() && this->_statusIntro == false)
    {
        gestionIntro();
        gestionSkip(tmp);
        this->_frameCounter++;
        if (this->_frameCounter >= 540) 
        {
            tmp = 1;
            this->_frameCounter = 0;
        }
        this->_texture->setBeginDrawing();
        this->_window->setClearBackground();
        this->_texture->setDrawTexture(this->_backgroundIntro, 0, 0);
        this->_texture->setDrawTexture(this->_textZone, 0, 780);
        this->_texts->setDrawText("Press space to skip", 1680, 930, 20, WHITE);
        if (tmp == 0)
            this->_texts->setDrawText(this->_texts->setSubText("The King of the Bombs captured you to send you to an arena to distract\nhis citizens, he gives you a chance at freedom if you can win this match. \nWin this match and your freedom.", 0, this->_frameCounter / 3), 30, 810, 23, WHITE);
        if (tmp == 1) {
            this->_texts->setDrawText("The King of the Bombs captured you to send you to an arena to distract\nhis citizens, he gives you a chance at freedom if you can win this match. \nWin this match and your freedom.", 30, 810, 23, WHITE);
            if (((this->_frameCounter / 20) % 2) == 0)
                this->_texts->setDrawText(this->_texts->setSubText("Click to continue...", 0, this->_frameCounter / 2), 1920 / 2 - 107, 100, 20, BLACK);
        }
        this->_texture->setEndDrawing();
    }
    deleteIntro();
}

const void Introduction::deleteIntro() const
{
    this->_texture->setUnloadTexture(this->_textZone);
    this->_texture->setUnloadTexture(this->_backgroundIntro);
}