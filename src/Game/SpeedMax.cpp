/*
** EPITECH PROJECT, 2021
** SpeedMax.cpp
** File description:
** SpeedMax.cpp
*/

#include "../../include/Game/SpeedMax.hpp"

SpeedMax::SpeedMax()
{
    this->_SpeedMax = 1;
}

SpeedMax::~SpeedMax()
{
}

void SpeedMax::addSpeed()
{
    this->_SpeedMax++;
}

const int SpeedMax::getSpeedMax()
{
    return (this->_SpeedMax);
}