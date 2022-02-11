/*
** EPITECH PROJECT, 2021
** BombMax.cpp
** File description:
** BombMax.cpp
*/

#include "../../include/Game/BombMax.hpp"

BombMax::BombMax()
{
    this->_BombMax = 1;
}

BombMax::~BombMax()
{
}

void BombMax::addBomb()
{
    this->_BombMax++;
}

const int BombMax::getBombMax()
{
    return (this->_BombMax);
}