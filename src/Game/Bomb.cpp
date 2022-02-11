/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Game/Bomb.hpp"

Bomb::Bomb(float nb)
{
    this->_bomb = false;
    this->_cdBomb = std::chrono::system_clock::now();
    this->_timerBomb = std::chrono::system_clock::now();
    this->_bombPos = {nb, 0.0f, 0.0f};
    this->_bombLeft = false;
    this->_bombRight = false;
    this->_bombUp = false;
    this->_bombDown = false;
    this->_range = 1;
}

Bomb::~Bomb()
{
}

Bomb *Bomb::gestionBomb(Bomb *bomb, Player *player)
{
    bomb->_bombLeft = false;
    bomb->_bombRight = false;
    bomb->_bombUp = false;
    bomb->_bombDown = false;
    bomb->_timerBomb = std::chrono::system_clock::now() + std::chrono::seconds(5);
    bomb->_cdBomb = std::chrono::system_clock::now() + std::chrono::milliseconds(5000);
    bomb->_bombPos = {((float)floor(player->getPositionX() + 0.5)), player->getPositionY(), ((float)floor(player->getPositionZ() + 0.5))};
    bomb->_bomb = true;
    bomb->_range = player->getBombRange();
    return (bomb);
}

Bomb *Bomb::cooldownBomb(Bomb *bomb)
{
    if (std::chrono::system_clock::now() < bomb->_cdBomb)
        bomb->_bomb = true;
    else
        bomb->_bomb = false;
    return (bomb);
}

void Bomb::explosionPlayerCenter(Player *player1, Player *player2, Player *player3, Player *player4)
{
    if (int(ceil(this->_bombPos.x)) == int(floor(player1->getPositionX() + 0.5)) && int(floor(this->_bombPos.z)) == int(floor(player1->getPositionZ() + 0.5)))
        player1->setAliveFalse();
    if (int(ceil(this->_bombPos.x)) == int(floor(player2->getPositionX() + 0.5)) && int(floor(this->_bombPos.z)) == int(floor(player2->getPositionZ() + 0.5)))
        player2->setAliveFalse();    
    if (int(ceil(this->_bombPos.x)) == int(floor(player3->getPositionX() + 0.5)) && int(floor(this->_bombPos.z)) == int(floor(player3->getPositionZ() + 0.5)))
        player3->setAliveFalse();
    if (int(ceil(this->_bombPos.x)) == int(floor(player4->getPositionX() + 0.5)) && int(floor(this->_bombPos.z)) == int(floor(player4->getPositionZ() + 0.5)))
        player4->setAliveFalse();
}

void Bomb::explosionPlayerLeft(int count, Player *player1, Player *player2, Player *player3, Player *player4)
{
    if (int(ceil(this->_bombPos.x) - (count + 1)) == int(floor(player1->getPositionX() + 0.5)) && int(floor(this->_bombPos.z)) == int(floor(player1->getPositionZ() + 0.5)))
        player1->setAliveFalse();
    if (int(ceil(this->_bombPos.x) - (count + 1)) == int(floor(player2->getPositionX() + 0.5)) && int(floor(this->_bombPos.z)) == int(floor(player2->getPositionZ() + 0.5)))
        player2->setAliveFalse();
    if (int(ceil(this->_bombPos.x) - (count + 1)) == int(floor(player3->getPositionX() + 0.5)) && int(floor(this->_bombPos.z)) == int(floor(player3->getPositionZ() + 0.5)))
        player3->setAliveFalse();
    if (int(ceil(this->_bombPos.x) - (count + 1)) == int(floor(player4->getPositionX() + 0.5)) && int(floor(this->_bombPos.z)) == int(floor(player4->getPositionZ() + 0.5)))
        player4->setAliveFalse();
}

void Bomb::explosionPlayerRight(int count, Player *player1, Player *player2 ,Player *player3, Player *player4)
{
    if (int(ceil(this->_bombPos.x) + (count + 1)) == int(floor(player1->getPositionX() + 0.5)) && int(floor(this->_bombPos.z)) == int(floor(player1->getPositionZ() + 0.5)))
        player1->setAliveFalse();
    if (int(ceil(this->_bombPos.x) + (count + 1)) == int(floor(player2->getPositionX() + 0.5)) && int(floor(this->_bombPos.z)) == int(floor(player2->getPositionZ() + 0.5)))
        player2->setAliveFalse();
    if (int(ceil(this->_bombPos.x) + (count + 1)) == int(floor(player3->getPositionX() + 0.5)) && int(floor(this->_bombPos.z)) == int(floor(player3->getPositionZ() + 0.5)))
        player3->setAliveFalse();
    if (int(ceil(this->_bombPos.x) + (count + 1)) == int(floor(player4->getPositionX() + 0.5)) && int(floor(this->_bombPos.z)) == int(floor(player4->getPositionZ() + 0.5)))
        player4->setAliveFalse();
}

void Bomb::explosionPlayerDown(int count, Player *player1, Player *player2, Player *player3, Player *player4)
{
    if (int(ceil(this->_bombPos.x)) == int(floor(player1->getPositionX() + 0.5)) && int(floor(this->_bombPos.z) + (count + 1)) == int(floor(player1->getPositionZ() + 0.5)))
        player1->setAliveFalse();
    if (int(ceil(this->_bombPos.x)) == int(floor(player2->getPositionX() + 0.5)) && int(floor(this->_bombPos.z) + (count + 1)) == int(floor(player2->getPositionZ() + 0.5)))
        player2->setAliveFalse();
    if (int(ceil(this->_bombPos.x)) == int(floor(player3->getPositionX() + 0.5)) && int(floor(this->_bombPos.z) + (count + 1)) == int(floor(player3->getPositionZ() + 0.5)))
        player3->setAliveFalse();
    if (int(ceil(this->_bombPos.x)) == int(floor(player4->getPositionX() + 0.5)) && int(floor(this->_bombPos.z) + (count + 1)) == int(floor(player4->getPositionZ() + 0.5)))
        player4->setAliveFalse();
}

void Bomb::explosionPlayerUp(int count, Player *player1, Player *player2 ,Player *player3, Player *player4)
{
    if (int(ceil(this->_bombPos.x)) == int(floor(player1->getPositionX() + 0.5)) && int(floor(this->_bombPos.z) - (count + 1)) == int(floor(player1->getPositionZ() + 0.5)))
        player1->setAliveFalse();
    if (int(ceil(this->_bombPos.x)) == int(floor(player2->getPositionX() + 0.5)) && int(floor(this->_bombPos.z) - (count + 1)) == int(floor(player2->getPositionZ() + 0.5)))
        player2->setAliveFalse();
    if (int(ceil(this->_bombPos.x)) == int(floor(player3->getPositionX() + 0.5)) && int(floor(this->_bombPos.z) - (count + 1)) == int(floor(player3->getPositionZ() + 0.5)))
        player3->setAliveFalse();
    if (int(ceil(this->_bombPos.x)) == int(floor(player4->getPositionX() + 0.5)) && int(floor(this->_bombPos.z) - (count + 1)) == int(floor(player4->getPositionZ() + 0.5)))
        player4->setAliveFalse();
}

char **Bomb::dispawn_boxes(char **map, Player *player, Player *player1, Player *player2, Player *player3, Player *player4)
{
    int count_l = 0;
    int count_r = 0;
    int count_d = 0;
    int count_u = 0;

    while (this->_bombLeft == false || this->_bombRight == false || this->_bombDown == false || this->_bombUp == false)
    {
        if (this->_bombLeft == false) {
            if (count_l == this->_range ||
                map[int(ceil(this->_bombPos.x) - (count_l + 1))][int(floor(this->_bombPos.z))] == MUR_INCASSABLE)
                this->_bombLeft = true;
            else if (count_l != this->_range &&
                map[int(ceil(this->_bombPos.x) - (count_l + 1))][int(floor(this->_bombPos.z))] == VIDE) {
                _texture->setDrawSphere({float(ceil(this->_bombPos.x) - (count_l + 1)), 0.0f, float(floor(this->_bombPos.z))}, 0.6, ORANGE);
                _texture->setDrawSphereWires({float(ceil(this->_bombPos.x) - (count_l + 1)), 0.0f, float(floor(this->_bombPos.z))}, 0.6, 16, 16, RED);
                explosionPlayerLeft(count_l, player1, player2, player3, player4);
                count_l += 1;
            } else {
                map[int(ceil(this->_bombPos.x) - (count_l + 1))][int(floor(this->_bombPos.z))] = generateBonus();
                _texture->setDrawSphere({float(ceil(this->_bombPos.x) - (count_l + 1)), 0.0f, float(floor(this->_bombPos.z))}, 0.6, ORANGE);
                _texture->setDrawSphereWires({float(ceil(this->_bombPos.x) - (count_l + 1)), 0.0f, float(floor(this->_bombPos.z))}, 0.6, 16, 16, RED);
                if (player->getThroughWall() == 0)
                    this->_bombLeft = true;
                else
                    count_l += 1;
            }
        }
        if (this->_bombRight == false) {
            if (count_r == this->_range ||
                map[int(ceil(this->_bombPos.x) + (count_r + 1))][int(floor(this->_bombPos.z))] == MUR_INCASSABLE)
                this->_bombRight = true;
            else if (count_r != this->_range &&
                     map[int(ceil(this->_bombPos.x) + (count_r + 1))][int(floor(this->_bombPos.z))] == VIDE) {
                explosionPlayerRight(count_r, player1, player2, player3, player4);
                _texture->setDrawSphere({float(ceil(this->_bombPos.x) + (count_r + 1)), 0.0f, float(floor(this->_bombPos.z))}, 0.6, ORANGE);
                _texture->setDrawSphereWires({float(ceil(this->_bombPos.x) + (count_r + 1)), 0.0f, float(floor(this->_bombPos.z))}, 0.6, 16, 16, RED);
                count_r += 1;
            } else {
                map[int(ceil(this->_bombPos.x) + (count_r + 1))][int(floor(this->_bombPos.z))] = generateBonus();
                _texture->setDrawSphere({float(ceil(this->_bombPos.x) + (count_r + 1)), 0.0f, float(ceil(this->_bombPos.z))}, 0.6, ORANGE);
                _texture->setDrawSphereWires({float(ceil(this->_bombPos.x) + (count_r + 1)), 0.0f, float(ceil(this->_bombPos.z))}, 0.6, 16, 16, RED);
                if (player->getThroughWall() == 0)
                    this->_bombRight = true;
                else
                    count_r += 1;
            }
        }
        if (this->_bombDown == false) {
            if (count_d == this->_range ||
                map[int(ceil(this->_bombPos.x))][int(floor(this->_bombPos.z) + (count_d + 1))] == MUR_INCASSABLE)
                this->_bombDown = true;
            else if (count_d != this->_range &&
                     map[int(ceil(this->_bombPos.x))][int(floor(this->_bombPos.z) + (count_d + 1))] == VIDE) {
                explosionPlayerDown(count_d, player1, player2, player3, player4);
                _texture->setDrawSphere({float(ceil(this->_bombPos.x)), 0.0f, float(ceil(this->_bombPos.z) + (count_d + 1))}, 0.6, ORANGE);
                _texture->setDrawSphereWires({float(ceil(this->_bombPos.x)), 0.0f, float(ceil(this->_bombPos.z) + (count_d + 1))}, 0.6, 16, 16, RED);
                count_d += 1;
            } else {
                map[int(ceil(this->_bombPos.x))][int(floor(this->_bombPos.z) + count_d + 1)] = generateBonus();
                _texture->setDrawSphere({float(ceil(this->_bombPos.x)), 0.0f, float(ceil(this->_bombPos.z) + (count_d + 1))}, 0.6, ORANGE);
                _texture->setDrawSphereWires({float(ceil(this->_bombPos.x)), 0.0f, float(ceil(this->_bombPos.z) + (count_d + 1))}, 0.6, 16, 16, RED);
                if (player->getThroughWall() == 0)
                    this->_bombDown = true;
                else
                    count_d += 1;
            }
        }
        if (this->_bombUp == false) {
            if (count_u == this->_range ||
                map[int(ceil(this->_bombPos.x))][int(floor(this->_bombPos.z) - (count_u + 1))] == MUR_INCASSABLE)
                this->_bombUp = true;
            else if (count_u != this->_range &&
                map[int(ceil(this->_bombPos.x))][int(floor(this->_bombPos.z) - (count_u + 1))] == VIDE) {
                explosionPlayerUp(count_u, player1, player2, player3, player4);
                _texture->setDrawSphere({float(ceil(this->_bombPos.x)), 0.0f, float(floor(this->_bombPos.z) - (count_u + 1))}, 0.6, ORANGE);
                _texture->setDrawSphereWires({float(ceil(this->_bombPos.x)), 0.0f, float(floor(this->_bombPos.z) - (count_u + 1))}, 0.6, 16, 16, RED);
                count_u += 1;
            } else {
                map[int(ceil(this->_bombPos.x))][int(floor(this->_bombPos.z) - count_u - 1)] = generateBonus();
                _texture->setDrawSphere({float(ceil(this->_bombPos.x)), 0.0f, float(floor(this->_bombPos.z) - (count_u + 1))}, 0.6, ORANGE);
                _texture->setDrawSphereWires({float(ceil(this->_bombPos.x)), 0.0f, float(floor(this->_bombPos.z) - (count_u + 1))}, 0.6, 16, 16, RED);
                if (player->getThroughWall() == 0)
                    this->_bombUp = true;
                else
                   count_u += 1; 
            }
        }
        if (this->_bombLeft == true && this->_bombRight == true && this->_bombDown == true && this->_bombUp == true)
        explosionPlayerCenter(player1, player2, player3, player4);
    }
    return map;
}

char Bomb::generateBonus()
{
    int randnb = GetRandomValue(1, 150);

    if (randnb >= 1 && randnb <= 23)
        return (BONUS_SPEED_SUP);
    else if (randnb >= 24 && randnb <= 46)
        return (BONUS_BOM_SUP);
    else if (randnb >= 47 && randnb < 70)
        return (BONUS_RANGE_SUP);
    else if (randnb == 70)
        return (BONUS_EXPLOSION_TRAVERS);
    else if (randnb == 71)
        return (BONUS_WALL_PASS);
    else
        return (VIDE);
}

bool Bomb::getStatus(Bomb *bomb)
{
    return (bomb->_bomb);
}

float Bomb::getBombPosX(Bomb *bomb)
{
    return (bomb->_bombPos.x);
}

float Bomb::getBombPosZ(Bomb *bomb)
{
    return (bomb->_bombPos.z);
}

Vector3 Bomb::getBombPos(Bomb *bomb)
{
    return (bomb->_bombPos);
}

std::chrono::system_clock::time_point Bomb::getTimerBomb()
{
    return (this->_timerBomb);
}