/*
** EPITECH PROJECT, 2021
** indie
** File description:
** gestion moves AI
*/

#include "../../include/Game/MoveAI.hpp"

MoveAI::MoveAI()
{
}

int MoveAI::getRange(Player *player, char pos1, char pos2)
{
    int range = 0;

    for (bool end = false; end != true;) {
        if (range == player->getBombRange())
            end = true;
        else if (pos1 + range != MUR_INCASSABLE && pos2 + range != MUR_INCASSABLE)
            range += 1;
        else if (pos1 + range == MUR_INCASSABLE || pos2 + range == MUR_INCASSABLE)
            end = true;
        else
            end = true;
    }
    return range + 1;
}

void MoveAI::gestionAIBomb(Map map, Bomb *bomb, BombList *bombList, Player *player)
{
    if (bomb->getStatus(bomb) == false) {
        bomb->gestionBomb(bomb, player);
        map._map[(int)bomb->getBombPosX(bomb)][(int)bomb->getBombPosZ(bomb)] = BOMB_WITH_PLAYER;
        bombList->addCurrentBomb(bombList);
        map.gestionMapManyBombsExplosion(bomb, bombList, player);
        map.cooldownBombMap(bomb, bombList);
    }
}

bool MoveAI::getUp()
{
    return this->_up;
}

bool MoveAI::getDown()
{
    return this->_down;
}

bool MoveAI::getLeft()
{
    return this->_left;
}

bool MoveAI::getRight()
{
    return this->_right;
}

void MoveAI::moveHandling(Player *player, Map map, bool up, bool down, bool left, bool right)
{
    if (up == false && down == false && left == false && right == false) {
        up = true;
        down = true;
        left = true;
        right = true;
    }
    this->_up = up;
    this->_down = down;
    this->_left = left;
    this->_right = right;
    int range_up = this->getRange(player, map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)], map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)]);
    int range_down = this->getRange(player, map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)], map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)]);
    int range_left = this->getRange(player, map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))], map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))]);
    int range_right = this->getRange(player, map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))], map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))]);

    if (player->getWallPass() == 1)
    {
        if ((map._map[int(player->getPositionX() - 1.0)][int(player->getPositionZ() + 1.8)] == BOMB && map._map[int(player->getPositionX() - 1.0)][int(player->getPositionZ() + 1.8)] == BOMB)
        || (map._map[int(player->getPositionX() - 1.0)][int(player->getPositionZ() - 1.0)] == BOMB && map._map[int(player->getPositionX() - 1.0)][int(player->getPositionZ() - 1.0)] == BOMB)
        || (map._map[int(player->getPositionX() + 1.8)][int(player->getPositionZ() + 1.8)] == BOMB && map._map[int(player->getPositionX() + 1.8)][int(player->getPositionZ() + 1.8)] == BOMB)
        || (map._map[int(player->getPositionX() + 1.8)][int(player->getPositionZ() - 1.0)] == BOMB && map._map[int(player->getPositionX() + 1.8)][int(player->getPositionZ() - 1.0)] == BOMB)) {
            player->setRotationAxis({1.0f, 0.0f, 0.0f});
            player->setRotationAngle(-90.0f);
        } else if ((map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - range_up)] == BOMB && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - range_up)] == BOMB)
         || (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + range_down + 0.5)] == BOMB && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + range_down + 0.5)] == BOMB)
         || (map._map[int(player->getPositionX() - range_left)][int(floor(player->getPositionZ()))] == BOMB && map._map[int(player->getPositionX() - range_left)][int(ceil(player->getPositionZ()))] == BOMB)) {
            player->setRotationAxis({1.0f, 0.0f, 0.0f});
            player->setRotationAngle(-90.0f);
        } else if (this->_down == true) {
            for (int i = 0; i < player->getSpeedMax(); i++) {
                if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE)
                {
                    player->movePlayerDOWN();
                    player->setRotationAxis({1.0f, 0.0f, 0.0f});
                    player->setRotationAngle(-90.0f);
                } else {
                    this->_down = false;
                    if (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE)
                        this->_right = true;
                    else
                        this->_right = false;
                    if (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE)
                        this->_left = true;
                    else
                        this->_left = false;
                    if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && this->_left == false && this->_right == false)
                        this->_up = true;
                    else
                        this->_up = false;
                    if (((map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE))
                    && (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ())] != MUR_CASSABLE || map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ())] != MUR_CASSABLE))
                        if (player->getPlayerNumber() == 1)
                            this->gestionAIBomb(map, map._bombListP1->getBomb1(), map._bombListP1, player);
                        else if (player->getPlayerNumber() == 2)
                            this->gestionAIBomb(map, map._bombListP2->getBomb2(), map._bombListP2, player);
                        else if (player->getPlayerNumber() == 3)
                            this->gestionAIBomb(map, map._bombListP3->getBomb3(), map._bombListP3, player);
                        else if (player->getPlayerNumber() == 4)
                            this->gestionAIBomb(map, map._bombListP4->getBomb4(), map._bombListP4, player);
                }
            }
        } else if (this->_right == true) {
            for (int i = 0; i < player->getSpeedMax(); i++) {
                if (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE)
                {
                    player->movePlayerRIGHT();
                    player->setRotationAxis({1.0f, -1.0f, -1.0f});
                    player->setRotationAngle(240.0f);
                } else {
                    this->_right = false;
                    if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE)
                        this->_down = true;
                    else
                        this->_down = false;
                    if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE)
                        this->_up = true;
                    else
                        this->_up = false;
                    if (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE && this->_up == false && this->_down == false)
                        this->_left = true;
                    else
                        this->_left = false;
                    if (((map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE))
                    && (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ())] != MUR_CASSABLE || map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ())] != MUR_CASSABLE))
                        if (player->getPlayerNumber() == 1)
                            this->gestionAIBomb(map, map._bombListP1->getBomb1(), map._bombListP1, player);
                        else if (player->getPlayerNumber() == 2)
                            this->gestionAIBomb(map, map._bombListP2->getBomb2(), map._bombListP2, player);
                        else if (player->getPlayerNumber() == 3)
                            this->gestionAIBomb(map, map._bombListP3->getBomb3(), map._bombListP3, player);
                        else if (player->getPlayerNumber() == 4)
                            this->gestionAIBomb(map, map._bombListP4->getBomb4(), map._bombListP4, player);
                }
            }
        } else if (this->_up == true) {
            for (int i = 0; i < player->getSpeedMax(); i++)
                if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE)
                {
                    player->movePlayerUP();
                    player->setRotationAxis({0.0f, 1.0f, 1.0f});
                    player->setRotationAngle(180.0f);
                } else {
                    this->_up = false;
                    if (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE)
                        this->_right = true;
                    else
                        this->_right = false;
                    if (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE)
                        this->_left = true;
                    else
                        this->_left = false;
                    if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && this->_left == false && this->_right == false)
                        this->_down = true;
                    else
                        this->_down = false;
                    if (((map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE))
                    && (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ())] != MUR_CASSABLE || map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ())] != MUR_CASSABLE))
                        if (player->getPlayerNumber() == 1)
                            this->gestionAIBomb(map, map._bombListP1->getBomb1(), map._bombListP1, player);
                        else if (player->getPlayerNumber() == 2)
                            this->gestionAIBomb(map, map._bombListP2->getBomb2(), map._bombListP2, player);
                        else if (player->getPlayerNumber() == 3)
                            this->gestionAIBomb(map, map._bombListP3->getBomb3(), map._bombListP3, player);
                        else if (player->getPlayerNumber() == 4)
                            this->gestionAIBomb(map, map._bombListP4->getBomb4(), map._bombListP4, player);
                }
        } else if (this->_left == true) {
            for (int i = 0; i < player->getSpeedMax(); i++) {
                if (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE)
                {
                    player->movePlayerLEFT();
                    player->setRotationAxis({1.0f, 1.0f, 1.0f});
                    player->setRotationAngle(240.0f);
                } else {
                    this->_left = false;
                    if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE)
                        this->_down = true;
                    else
                        this->_down = false;
                    if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE)
                        this->_up = true;
                    else
                        this->_up = false;
                    if (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE && this->_up == false && this->_down == false)
                        this->_right = true;
                    else
                        this->_right = false;
                    if (((map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE))
                    && (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ())] != MUR_CASSABLE || map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ())] != MUR_CASSABLE))
                        if (player->getPlayerNumber() == 1)
                            this->gestionAIBomb(map, map._bombListP1->getBomb1(), map._bombListP1, player);
                        else if (player->getPlayerNumber() == 2)
                            this->gestionAIBomb(map, map._bombListP2->getBomb2(), map._bombListP2, player);
                        else if (player->getPlayerNumber() == 3)
                            this->gestionAIBomb(map, map._bombListP3->getBomb3(), map._bombListP3, player);
                        else if (player->getPlayerNumber() == 4)
                            this->gestionAIBomb(map, map._bombListP4->getBomb4(), map._bombListP4, player);
                }
            }
        }
        } else {
        if ((map._map[int(player->getPositionX() - 1.0)][int(player->getPositionZ() + 1.8)] == BOMB && map._map[int(player->getPositionX() - 1.0)][int(player->getPositionZ() + 1.8)] == BOMB)
        || (map._map[int(player->getPositionX() - 1.0)][int(player->getPositionZ() - 1.0)] == BOMB && map._map[int(player->getPositionX() - 1.0)][int(player->getPositionZ() - 1.0)] == BOMB)
        || (map._map[int(player->getPositionX() + 1.8)][int(player->getPositionZ() + 1.8)] == BOMB && map._map[int(player->getPositionX() + 1.8)][int(player->getPositionZ() + 1.8)] == BOMB)
        || (map._map[int(player->getPositionX() + 1.8)][int(player->getPositionZ() - 1.0)] == BOMB && map._map[int(player->getPositionX() + 1.8)][int(player->getPositionZ() - 1.0)] == BOMB)) {
            player->setRotationAxis({1.0f, 0.0f, 0.0f});
            player->setRotationAngle(-90.0f);
        } else if ((map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - range_up)] == BOMB && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - range_up)] == BOMB)
         || (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + range_down + 0.5)] == BOMB && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + range_down + 0.5)] == BOMB)
         || (map._map[int(player->getPositionX() - range_left)][int(floor(player->getPositionZ()))] == BOMB && map._map[int(player->getPositionX() - range_left)][int(ceil(player->getPositionZ()))] == BOMB)) {
            player->setRotationAxis({1.0f, 0.0f, 0.0f});
            player->setRotationAngle(-90.0f);
        } else if (this->_down == true) {
            for (int i = 0; i < player->getSpeedMax(); i++) {
                if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_CASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != BOMB && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != BOMB)
                {
                    player->movePlayerDOWN();
                    player->setRotationAxis({1.0f, 0.0f, 0.0f});
                    player->setRotationAngle(-90.0f);
                } else {
                    this->_down = false;
                    if (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != BOMB && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != BOMB)
                        this->_right = true;
                    else
                        this->_right = false;
                    if (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != BOMB && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != BOMB)
                        this->_left = true;
                    else
                        this->_left = false;
                    if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_CASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != BOMB && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != BOMB && this->_left == false && this->_right == false)
                        this->_up = true;
                    else
                        this->_up = false;
                    if ((map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE))
                        if (player->getPlayerNumber() == 1)
                            this->gestionAIBomb(map, map._bombListP1->getBomb1(), map._bombListP1, player);
                        else if (player->getPlayerNumber() == 2)
                            this->gestionAIBomb(map, map._bombListP2->getBomb2(), map._bombListP2, player);
                        else if (player->getPlayerNumber() == 3)
                            this->gestionAIBomb(map, map._bombListP3->getBomb3(), map._bombListP3, player);
                        else if (player->getPlayerNumber() == 4)
                            this->gestionAIBomb(map, map._bombListP4->getBomb4(), map._bombListP4, player);
                }
            }
        } else if (this->_right == true) {
            for (int i = 0; i < player->getSpeedMax(); i++) {
                if (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != BOMB && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != BOMB)
                {
                    player->movePlayerRIGHT();
                    player->setRotationAxis({1.0f, -1.0f, -1.0f});
                    player->setRotationAngle(240.0f);
                } else {
                    this->_right = false;
                    if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_CASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != BOMB && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != BOMB)
                        this->_down = true;
                    else
                        this->_down = false;
                    if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_CASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != BOMB && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != BOMB)
                        this->_up = true;
                    else
                        this->_up = false;
                    if (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != BOMB && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != BOMB && this->_up == false && this->_down == false)
                        this->_left = true;
                    else
                        this->_left = false;
                    if ((map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE))
                        if (player->getPlayerNumber() == 1)
                            this->gestionAIBomb(map, map._bombListP1->getBomb1(), map._bombListP1, player);
                        else if (player->getPlayerNumber() == 2)
                            this->gestionAIBomb(map, map._bombListP2->getBomb2(), map._bombListP2, player);
                        else if (player->getPlayerNumber() == 3)
                            this->gestionAIBomb(map, map._bombListP3->getBomb3(), map._bombListP3, player);
                        else if (player->getPlayerNumber() == 4)
                            this->gestionAIBomb(map, map._bombListP4->getBomb4(), map._bombListP4, player);
                }
            }
        } else if (this->_up == true) {
            for (int i = 0; i < player->getSpeedMax(); i++)
                if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_CASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != BOMB && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != BOMB)
                {
                    player->movePlayerUP();
                    player->setRotationAxis({0.0f, 1.0f, 1.0f});
                    player->setRotationAngle(180.0f);
                } else {
                    this->_up = false;
                    if (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != BOMB && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != BOMB)
                        this->_right = true;
                    else
                        this->_right = false;
                    if (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != BOMB && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != BOMB)
                        this->_left = true;
                    else
                        this->_left = false;
                    if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_CASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != BOMB && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != BOMB && this->_left == false && this->_right == false)
                        this->_down = true;
                    else
                        this->_down = false;
                    if ((map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE))
                        if (player->getPlayerNumber() == 1)
                            this->gestionAIBomb(map, map._bombListP1->getBomb1(), map._bombListP1, player);
                        else if (player->getPlayerNumber() == 2)
                            this->gestionAIBomb(map, map._bombListP2->getBomb2(), map._bombListP2, player);
                        else if (player->getPlayerNumber() == 3)
                            this->gestionAIBomb(map, map._bombListP3->getBomb3(), map._bombListP3, player);
                        else if (player->getPlayerNumber() == 4)
                            this->gestionAIBomb(map, map._bombListP4->getBomb4(), map._bombListP4, player);
                }
        } else if (this->_left == true) {
            for (int i = 0; i < player->getSpeedMax(); i++) {
                if (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != BOMB && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != BOMB)
                {
                    player->movePlayerLEFT();
                    player->setRotationAxis({1.0f, 1.0f, 1.0f});
                    player->setRotationAngle(240.0f);
                } else {
                    this->_left = false;
                    if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_CASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != BOMB && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != BOMB)
                        this->_down = true;
                    else
                        this->_down = false;
                    if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_CASSABLE && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != BOMB && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != BOMB)
                        this->_up = true;
                    else
                        this->_up = false;
                    if (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != BOMB && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != BOMB && this->_up == false && this->_down == false)
                        this->_right = true;
                    else
                        this->_right = false;
                    if ((map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] == MUR_CASSABLE && map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] == MUR_CASSABLE)
                    || (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == MUR_CASSABLE))
                        if (player->getPlayerNumber() == 1)
                            this->gestionAIBomb(map, map._bombListP1->getBomb1(), map._bombListP1, player);
                        else if (player->getPlayerNumber() == 2)
                            this->gestionAIBomb(map, map._bombListP2->getBomb2(), map._bombListP2, player);
                        else if (player->getPlayerNumber() == 3)
                            this->gestionAIBomb(map, map._bombListP3->getBomb3(), map._bombListP3, player);
                        else if (player->getPlayerNumber() == 4)
                            this->gestionAIBomb(map, map._bombListP4->getBomb4(), map._bombListP4, player);
                }
            }
        }
    }
}