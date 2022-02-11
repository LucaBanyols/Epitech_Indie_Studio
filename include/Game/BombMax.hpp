/*
** EPITECH PROJECT, 2021
** BombMax.hpp
** File description:
** BombMax.hpp
*/

#include "../ICore.hpp"

#ifndef BOMBMAX_HPP_
#define BOMBMAX_HPP_

class BombMax
{
private:
    int _BombMax;
public:
    BombMax();
    ~BombMax();
    void addBomb();
    const int getBombMax();
};

#endif