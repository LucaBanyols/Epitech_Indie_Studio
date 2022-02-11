/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"

#ifndef BACKGROUND_HPP_
#define BACKGROUND_HPP_

class Background : IComponent
{
public:
    Background();
    ~Background() = default;
    const void setBackground();
    const void setEndBackground();
    const void setGameBackground();
    const void displayGameBackground() const;
    const void displayBackground() const;
    const void displayEndBackground() const;
    const void displayBackgroundChangePlayer() const;
    const void deleteBackground() const;
    const void deleteGameBackground() const;
    const void deleteEndBackground() const;

    // Images

    Image _imgBackground;

    // Textures

    Texture2D _textureBackground;
    Texture2D _textureGameBackground;
    Texture2D _textureEndBackground;
    Texture2D _textureBackgroundChangePlayer;
};

#endif