/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "Mouse.hpp"

#ifndef SOUND_HPP_
#define SOUND_HPP_

class Sounds
{
public:
    Sounds();
    ~Sounds() = default;
    const Sound getSound(const char *path) const;
    const void setSound() const;
    const void setSoundButton();
    const void setUnloadSound(Sound sound) const;
    const void setPlaySound(Sound sound) const;
    const void deleteSoundButton() const;
    const void playSoundHoverButton() const;
    const void playSoundClickButton() const;
    const void deleteSound() const;

    Sound _soundClickButton;
    Sound _soundHoverButton;
};

#endif