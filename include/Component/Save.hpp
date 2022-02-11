/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"

#ifndef SAVES_HPP_
#define SAVES_HPP_

typedef enum {
    STORAGE_KEYS = 0,
    STORAGE_POS_PLAYER = 1
} StorageData;

class Saves
{
public:
    Saves();
    ~Saves() = default;
    const bool setSaveStorageValue(unsigned int storagePosition, int value) const;
    const int getSavedValueInStorage(unsigned int storagePosition) const;
};

#endif