/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Game/BombList.hpp"

BombList::BombList()
{
    this->_bomb1 = new Bomb(1);
    this->_bomb2 = new Bomb(2);
    this->_bomb3 = new Bomb(3);
    this->_bomb4 = new Bomb(4);
    this->_bomb5 = new Bomb(5);
    this->_bomb6 = new Bomb(6);
    this->_bomb7 = new Bomb(7);
    this->_bomb8 = new Bomb(8);
    this->_bomb9 = new Bomb(9);
    this->_bomb10 = new Bomb(10);
    this->_currentBomb = 0;
}

BombList::~BombList()
{
}

Bomb *BombList::getBomb1()
{
    return (this->_bomb1);
}

Bomb *BombList::getBomb2()
{
    return (this->_bomb2);
}

Bomb *BombList::getBomb3()
{
    return (this->_bomb3);
}

Bomb *BombList::getBomb4()
{
    return (this->_bomb4);
}

Bomb *BombList::getBomb5()
{
    return (this->_bomb5);
}

Bomb *BombList::getBomb6()
{
    return (this->_bomb6);
}

Bomb *BombList::getBomb7()
{
    return (this->_bomb7);
}

Bomb *BombList::getBomb8()
{
    return (this->_bomb8);
}

Bomb *BombList::getBomb9()
{
    return (this->_bomb9);
}

Bomb *BombList::getBomb10()
{
    return (this->_bomb10);
}

int BombList::getCurrentBomb()
{
    return (this->_currentBomb);
}

void BombList::addCurrentBomb(BombList *bombList)
{
    bombList->_currentBomb++;
}

void BombList::subCurrentBomb(BombList *bombList)
{
    bombList->_currentBomb--;
}