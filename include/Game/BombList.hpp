/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Game/Bomb.hpp"

#ifndef BOMBLIST_HPP_
#define BOMBLIST_HPP_

class BombList
{
private:
    Bomb *_bomb1;
    Bomb *_bomb2;
    Bomb *_bomb3;
    Bomb *_bomb4;
    Bomb *_bomb5;
    Bomb *_bomb6;
    Bomb *_bomb7;
    Bomb *_bomb8;
    Bomb *_bomb9;
    Bomb *_bomb10;
    int _currentBomb;
public:
    BombList();
    ~BombList();
    Bomb *getBomb1();
    Bomb *getBomb2();
    Bomb *getBomb3();
    Bomb *getBomb4();
    Bomb *getBomb5();
    Bomb *getBomb6();
    Bomb *getBomb7();
    Bomb *getBomb8();
    Bomb *getBomb9();
    Bomb *getBomb10();
    int getCurrentBomb();
    void addCurrentBomb(BombList *bombList);
    void subCurrentBomb(BombList *bombList);
};

#endif
