/*
** EPITECH PROJECT, 2021
** ThroughWall.cpp
** File description:
** ThroughWall.cpp
*/

#include "../../include/Game/ThroughWall.hpp"

ThroughWall::ThroughWall()
{
    this->_ThroughWall = 0;
}

ThroughWall::~ThroughWall()
{
}

void ThroughWall::addThroughWall()
{
    this->_ThroughWall = 1;
}

const int ThroughWall::getThroughWall()
{
    return (this->_ThroughWall);
}