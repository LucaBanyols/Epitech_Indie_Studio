/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"

#ifndef CHANGESIZEMAP_HPP_
#define CHANGESIZEMAP_HPP_

#define MAX_SIZE 24
#define MIN_SIZE 8

class ChangeSizeMap
{
private:
public:
    ChangeSizeMap();
    ~ChangeSizeMap();
    const int gestionSizeMap(int sizemap, bool actionMinus, bool actionPlus);
};

#endif