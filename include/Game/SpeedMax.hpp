/*
** EPITECH PROJECT, 2021
** SpeedMax.hpp
** File description:
** SpeedMax.hpp
*/

#include "../ICore.hpp"

#ifndef SPEEDMAX_HPP_
#define SPEEDMAX_HPP_

class SpeedMax
{
private:
    int _SpeedMax;
public:
    SpeedMax();
    ~SpeedMax();
    void addSpeed();
    const int getSpeedMax();
};

#endif