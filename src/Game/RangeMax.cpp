/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Range Bonus
*/

#include "../../include/Game/RangeMax.hpp"

RangeMax::RangeMax()
{
    this->_rangeMax = 1;
}

RangeMax::~RangeMax()
{
}

void RangeMax::addRange()
{
    this->_rangeMax++;
}

const int RangeMax::getRangeMax()
{
    return (this->_rangeMax);
}
