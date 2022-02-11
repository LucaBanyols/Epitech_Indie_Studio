/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Range Bonus hpp
*/

#include "../ICore.hpp"

#ifndef RANGEMAX_HPP_
#define RANGEMAX_HPP_

class RangeMax
{
private:
    int _rangeMax;
public:
    RangeMax();
    ~RangeMax();
    void addRange();
    const int getRangeMax();
};

#endif