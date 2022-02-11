/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <chrono>
#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <raylib.h>
#include "Error.hpp"

// Define pour les éléments du tableau de la map

#define VIDE '0'
#define MUR_CASSABLE '1'
#define MUR_INCASSABLE '2'

#define BOMB 'B'
#define BONUS_BOM_SUP '+'
#define BONUS_RANGE_SUP 'R'
#define BONUS_SPEED_SUP 'S'
#define BONUS_EXPLOSION_TRAVERS 'T'
#define BONUS_WALL_PASS 'W'

#define NB_PLAYER '4'
#define PLAYER_1 '6'
#define PLAYER_2 '7'
#define PLAYER_3 '8'
#define PLAYER_4 '9'

#define BOMB_WITH_PLAYER '5'

#define TAB_KEY_UP 0
#define TAB_KEY_DOWN 1
#define TAB_KEY_LEFT 2
#define TAB_KEY_RIGHT 3
#define TAB_KEY_DROP 4

#define KEY_PLAYER_ONE 0
#define KEY_PLAYER_TWO 1
#define KEY_PLAYER_THREE 2
#define KEY_PLAYER_FOUR 3

#ifndef ICORE_HPP_
#define ICORE_HPP_

class ICore
{
public:
    ICore() {};
    virtual ~ICore() = default;
};

#endif