/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"

#ifndef Setting_HPP_
#define Setting_HPP_

class Setting : IComponent
{
public:
    Setting();
    ~Setting();
    const void setSettingButton();
    const void gestionSettingButton(Vector2 mousePoint, Mouse *mouse, Sounds *sounds);
    const void displaySettingButton() const;
    const void deleteSettingButton() const;

    Texture2D _textureSetting;
    Rectangle _sourceSettingRec;
    Rectangle _btnSettingBounds;
    bool _btnSettingAction;
    float _frameSettingHeight;
    int _buttonSettingState;
};

#endif