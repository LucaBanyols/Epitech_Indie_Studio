/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../../include/Input/Setting.hpp"

Setting::Setting()
{
    this->_buttonSettingState = 0;
    this->_btnSettingAction = false;
}

Setting::~Setting()
{
}

const void Setting::setSettingButton()
{
    try
    {
        this->_textureSetting = this->_texture->getTexture2D("../src/resources/assets/setting.png");
    }
    catch(Texture2D)
    {
        this->_textureSetting = this->_texture->getTexture2D("../../src/resources/assets/setting.png");
    }
    catch(Error &e)
    {
        std::cerr << e.what() << '\n';
    }

    this->_frameSettingHeight = (float)this->_textureSetting.height / 2;
    this->_sourceSettingRec = {0, 0, (float)this->_textureSetting.width, this->_frameSettingHeight};
    this->_btnSettingBounds = {1700, 20, (float)this->_textureSetting.width, this->_frameSettingHeight};
}

const void Setting::gestionSettingButton(Vector2 mousePoint, Mouse *mouse, Sounds *sounds)
{
    if (mouse->getCollisionPointRec(mousePoint, this->_btnSettingBounds))
    {
        if (mouse->getClickPressed(MOUSE_LEFT_BUTTON))
        {
            this->_buttonSettingState = 2;
            sounds->playSoundClickButton();
        }
        else
            this->_buttonSettingState = 1;
        if (mouse->getClickPressed(MOUSE_LEFT_BUTTON))
        {
            this->_btnSettingAction = true;
        }
    }
    else
        this->_buttonSettingState = 0;
    this->_sourceSettingRec.y = this->_buttonSettingState * this->_frameSettingHeight;
}

const void Setting::displaySettingButton() const
{
    this->_texture->setDrawTextureRec(this->_textureSetting, this->_sourceSettingRec, this->_btnSettingBounds.x, this->_btnSettingBounds.y);
}

const void Setting::deleteSettingButton() const
{
    this->_texture->setUnloadTexture(this->_textureSetting);
}
