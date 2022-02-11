/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"

#ifndef HOWTOPLAY_HPP_
#define HOWTOPLAY_HPP_

class HowToPlay : IComponent
{
private:
public:
    HowToPlay();
    ~HowToPlay();
    const void setHtpAction();
    const void setHtpButton();
    const void setHtp();
    const void displayHtpButton() const;
    const void displayHtp() const;
    const void gestionHtpButton(Vector2 mousePoint, Mouse *mouse, Sounds *sounds);
    const void deleteHtpButton() const;
    const void deleteHtp() const;
    const void deleteHtpAction() const;

    Texture2D _textureHtp;

    Texture2D _textureHtpButton;
    Rectangle _sourceHtpRec;
    Rectangle _btnHtpBounds;
    bool _btnHtpAction;
    float _frameHtpHeight;
    int _buttonHtpState;
};

#endif