/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../../include/Input/Start.hpp"

Start::Start()
{
    this->_buttonStartState = 0;
    this->_btnStartAction = false;
}

Start::~Start()
{
}

const void Start::setStartButton()
{
    try
    {
        this->_textureStartButton = this->_texture->getTexture2D("../src/resources/assets/start_button.png");
    }
    catch(Texture2D)
    {
        this->_textureStartButton = this->_texture->getTexture2D("../../src/resources/assets/start_button.png");
    }
    catch(Error &e)
    {
        std::cerr << e.what() << '\n';
    }

    this->_frameStartHeight = (float)this->_textureStartButton.height / 2;
    this->_sourceStartRec = {0, 0, (float)this->_textureStartButton.width, this->_frameStartHeight};
    this->_btnStartBounds = {1920 / 2.0f - this->_textureStartButton.width / 2, 1080 / 2.0f - this->_textureStartButton.height / 2 / 2.0f, (float)this->_textureStartButton.width, this->_frameStartHeight};
}

const void Start::displayStartButton() const
{
    this->_texture->setDrawTextureRec(this->_textureStartButton, this->_sourceStartRec, this->_btnStartBounds.x, this->_btnStartBounds.y);
}

const void Start::gestionStartButton(Vector2 mousePoint, Mouse *mouse, Sounds *sounds)
{
    if (mouse->getCollisionPointRec(mousePoint, this->_btnStartBounds))
    {
        if (mouse->getClickPressed(MOUSE_LEFT_BUTTON))
        {
            this->_buttonStartState = 2;
            sounds->playSoundClickButton();
        }
        else
            this->_buttonStartState = 1;
        if (mouse->getClickReleased(MOUSE_LEFT_BUTTON))
        {
            this->_btnStartAction = true;
        }
    }
    else
        this->_buttonStartState = 0;
    _sourceStartRec.y = _buttonStartState * _frameStartHeight;
}

const void Start::deleteStartButton() const
{
    this->_texture->setUnloadTexture(this->_textureStartButton);
}
