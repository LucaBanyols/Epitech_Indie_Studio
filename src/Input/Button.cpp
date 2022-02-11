/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../../include/Input/Button.hpp"

Button::Button()
{
    this->_isHoverButton = 0;
    this->_arrayHoverButton = new int[2];
    this->_arrayHoverButton[0] = 0;
    this->_arrayHoverButton[1] = 0;
}

Button::~Button()
{
}

const void Button::setButtons()
{
    this->_startButton = new Start;
    this->_quitButton = new Quit;
    this->_minusButton = new Minus;
    this->_plusButton = new Plus;
    this->_settingButton = new Setting;
    this->_howtoplay = new HowToPlay;

    this->_startButton->setStartButton();
    this->_quitButton->setQuitButton();
    this->_minusButton->setMinusButton();
    this->_plusButton->setPlusButton();
    this->_settingButton->setSettingButton();
    this->_howtoplay->setHtpAction();
}

const void Button::displayButton() const
{
    this->_startButton->displayStartButton();
    this->_quitButton->displayQuitButton();
    this->_howtoplay->displayHtpButton();
    this->_minusButton->displayMinusButton();
    this->_plusButton->displayPlusButton();
    this->_settingButton->displaySettingButton();
    if (this->_howtoplay->_btnHtpAction == true)
        this->_howtoplay->displayHtp();
}

const void Button::gestionButton(Vector2 &mousePoint, Mouse *mouse, Sounds *sounds)
{
    this->_startButton->gestionStartButton(mousePoint, mouse, sounds);
    this->_quitButton->gestionQuitButton(mousePoint, mouse, sounds);
    this->_minusButton->gestionMinusButton(mousePoint, mouse, sounds);
    this->_plusButton->gestionPlusButton(mousePoint, mouse, sounds);
    this->_howtoplay->gestionHtpButton(mousePoint, mouse, sounds);
    this->_settingButton->gestionSettingButton(mousePoint, mouse, sounds);
    if (!(mouse->getCollisionPointRec(mouse->getMousePos(), this->_startButton->_btnStartBounds))
        && !(mouse->getCollisionPointRec(mouse->getMousePos(), this->_quitButton->_btnQuitBounds))
        && !(mouse->getCollisionPointRec(mouse->getMousePos(), this->_howtoplay->_btnHtpBounds))
        && !(mouse->getCollisionPointRec(mouse->getMousePos(), this->_plusButton->_btnPlusBounds))
        && !(mouse->getCollisionPointRec(mouse->getMousePos(), this->_minusButton->_btnMinusBounds))
        && !(mouse->getCollisionPointRec(mouse->getMousePos(), this->_settingButton->_btnSettingBounds)))
        this->_isHoverButton = 0;
    else
        this->_isHoverButton = 1;
    this->_arrayHoverButton[0] = this->_arrayHoverButton[1];
    this->_arrayHoverButton[1] = this->_isHoverButton;
    if (this->_arrayHoverButton[0] == 0 && this->_arrayHoverButton[1] == 1)
        sounds->playSoundHoverButton();
}

const void Button::deleteButtons() const
{
    this->_startButton->deleteStartButton();
    this->_quitButton->deleteQuitButton();
    this->_howtoplay->deleteHtpAction();
    this->_minusButton->deleteMinusButton();
    this->_plusButton->deletePlusButton();
    this->_settingButton->deleteSettingButton();

    delete (this->_startButton);
    delete (this->_quitButton);
    delete (this->_minusButton);
    delete (this->_plusButton);
    delete (this->_howtoplay);
    delete (this->_settingButton);
}
