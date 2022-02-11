/*
** EPITECH PROJECT, 2021
** WallPass.hpp
** File description:
** WallPass.hpp
*/

#include "../ICore.hpp"

#ifndef WALLPASS_HPP_
#define WALLPASS_HPP_

class WallPass
{
private:
    int _WallPass;
public:
    WallPass();
    ~WallPass();
    void addWallPass();
    const int getWallPass();
};

#endif