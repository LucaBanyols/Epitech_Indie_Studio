/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../Component/IComponent.hpp"

#ifndef INTRODUCTION_HPP_
#define INTRODUCTION_HPP_

class Introduction : IComponent
{
private:
    int _frameCounter;
    Texture2D _textZone;
    Texture2D _backgroundIntro;

public:
    bool _statusIntro;

    Introduction();
    ~Introduction() = default;
    const void setTextZone();
    const void gestionIntro();
    const void gestionSkip(int tmp);
    const void displayIntro();
    const void deleteIntro() const;
};

#endif