/*
** EPITECH PROJECT, 2021
** WallPass.cpp
** File description:
** WallPass.cpp
*/

#include "../../include/Game/WallPass.hpp"

WallPass::WallPass()
{
    this->_WallPass = 0;
}

WallPass::~WallPass()
{
}

void WallPass::addWallPass()
{
    this->_WallPass = 1;
}

const int WallPass::getWallPass()
{
    return (this->_WallPass);
}