/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../../include/Input/HowToPlay.hpp"

HowToPlay::HowToPlay()
{
    this->_buttonHtpState = 0;
    this->_btnHtpAction = false;
}

HowToPlay::~HowToPlay()
{
}

const void HowToPlay::setHtpButton()
{
    try
    {
        this->_textureHtpButton = this->_texture->getTexture2D("../src/resources/assets/how_to_play_but.png");
    }
    catch(Texture2D)
    {
        this->_textureHtpButton = this->_texture->getTexture2D("../../src/resources/assets/how_to_play_but.png");
    }
    catch(Error &e)
    {
        std::cerr << e.what() << '\n';
    }

    this->_frameHtpHeight = (float)this->_textureHtpButton.height / 2;
    this->_sourceHtpRec = {0, 0, (float)this->_textureHtpButton.width, this->_frameHtpHeight};
    this->_btnHtpBounds = {1850, 900, (float)this->_textureHtpButton.width, this->_frameHtpHeight};
}

const void HowToPlay::setHtp()
{
    try
    {
        this->_textureHtp = this->_texture->getTexture2D("../src/resources/assets/how_to_play_txt2.png");
    }
    catch(Texture2D)
    {
        this->_textureHtp = this->_texture->getTexture2D("../../src/resources/assets/how_to_play_txt2.png");
    }
    catch(Error &e)
    {
        std::cerr << e.what() << '\n';
    }
}

const void HowToPlay::setHtpAction()
{
    setHtp();
    setHtpButton();
}

const void HowToPlay::displayHtpButton() const
{
    this->_texture->setDrawTextureRec(this->_textureHtpButton, this->_sourceHtpRec, this->_btnHtpBounds.x, this->_btnHtpBounds.y);
}

const void HowToPlay::displayHtp() const
{
    if (this->_btnHtpAction == true)
        this->_texture->setDrawTexture(this->_textureHtp, 1190, 660);
}

const void HowToPlay::gestionHtpButton(Vector2 mousePoint, Mouse *mouse, Sounds *sounds)
{
    if (mouse->getCollisionPointRec(mousePoint, this->_btnHtpBounds))
    {
        if (mouse->getClickPressed(MOUSE_LEFT_BUTTON))
        {
            this->_buttonHtpState = 2;
            sounds->playSoundClickButton();
        }
        else
            this->_buttonHtpState = 1;
        if (mouse->getClickReleased(MOUSE_LEFT_BUTTON))
        {
            this->_btnHtpAction = !this->_btnHtpAction;
        }
    }
    else
        this->_buttonHtpState = 0;
    _sourceHtpRec.y = _buttonHtpState * _frameHtpHeight;
}

const void HowToPlay::deleteHtpButton() const
{
    this->_texture->setUnloadTexture(this->_textureHtpButton);
}

const void HowToPlay::deleteHtp() const
{
    this->_texture->setUnloadTexture(this->_textureHtp);
}

const void HowToPlay::deleteHtpAction() const
{
    deleteHtp();
    deleteHtpButton();
}
