/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../../include/Input/ChangeSizeMap.hpp"

ChangeSizeMap::ChangeSizeMap()
{
}

ChangeSizeMap::~ChangeSizeMap()
{
}

const int ChangeSizeMap::gestionSizeMap(int sizemap, bool actionMinus, bool actionPlus)
{
    if (actionMinus == true && sizemap > MIN_SIZE) {
        sizemap--;
    }
    else if (actionPlus == true && sizemap < MAX_SIZE) {
        sizemap++;
    }
    return (sizemap);
}
