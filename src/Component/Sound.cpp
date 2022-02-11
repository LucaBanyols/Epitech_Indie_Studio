/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../../include/Component/Sound.hpp"

Sounds::Sounds()
{
}

const void Sounds::setSound() const
{
    return (InitAudioDevice());
}

const Sound Sounds::getSound(const char *path) const
{
    return (LoadSound(path));
}

const void Sounds::setSoundButton()
{
    this->_soundClickButton = getSound("../src/resources/sounds/select_play_sound.wav");
    this->_soundHoverButton = getSound("../src/resources/sounds/hover_button.wav");
}

const void Sounds::setPlaySound(Sound sound) const
{
    return (PlaySound(sound));
}

const void Sounds::playSoundClickButton() const
{
    return (setPlaySound(this->_soundClickButton));
}

const void Sounds::playSoundHoverButton() const
{
    return (setPlaySound(this->_soundHoverButton));
}

const void Sounds::setUnloadSound(Sound sound) const
{
    return (UnloadSound(sound));
}

const void Sounds::deleteSoundButton() const
{
    setUnloadSound(this->_soundClickButton);
    setUnloadSound(this->_soundHoverButton);
}

const void Sounds::deleteSound() const
{
    return(CloseAudioDevice());
}