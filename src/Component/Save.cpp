/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Component/Save.hpp"

Saves::Saves()
{
}

const bool Saves::setSaveStorageValue(unsigned int storagePosition, int value) const
{
    return (SaveStorageValue(storagePosition, value));
}

const int Saves::getSavedValueInStorage(unsigned int storagePosition) const 
{
    return (LoadStorageValue(storagePosition));
}