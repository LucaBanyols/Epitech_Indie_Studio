/*
** EPITECH PROJECT, 2021
** indie studio
** File description:
** Move AI hpp
*/

#include "Map.hpp"

#ifndef MOVEAI_HPP_
#define MOVEAI_HPP_

class MoveAI
{
public:
    bool _up;
    bool _down;
    bool _left;
    bool _right;

    MoveAI();
    ~MoveAI() = default;
    bool getUp();
    bool getDown();
    bool getLeft();
    bool getRight();
    void moveHandling(Player *player, Map map, bool up, bool down, bool left, bool right);
    int getRange(Player *player, char pos1, char pos2);
    void gestionAIBomb(Map map, Bomb *bomb, BombList *bombList, Player *player);
};

#endif