/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Input/Key.hpp"
#include "../Game/Player.hpp"

#ifndef BOMB_HPP_
#define BOMB_HPP_

class Bomb
{
private:
    bool _bomb;
    std::chrono::system_clock::time_point _cdBomb;
    std::chrono::system_clock::time_point _timerBomb;
    Vector3 _bombPos;
    bool _bombLeft;
    bool _bombRight;
    bool _bombUp;
    bool _bombDown;
    int _range;
    Textures *_texture;
//    bool *_arrayBombUsed;
public:
    Bomb(float nb);
    ~Bomb();
    Bomb *gestionBomb(Bomb *bomb, Player *player);
    Bomb *cooldownBomb(Bomb *bomb);
    char **dispawn_boxes(char **map,  Player *player, Player *player1, Player *player2, Player *player3, Player *player4);
    void explosionPlayerCenter(Player *player1, Player *player2, Player *player3, Player *player4);
    void explosionPlayerLeft(int count, Player *player1, Player *player2, Player *player3, Player *player4);
    void explosionPlayerRight(int count, Player *player1, Player *player2, Player *player3, Player *player4);
    void explosionPlayerDown(int count, Player *player1, Player *player2, Player *player3, Player *player4);
    void explosionPlayerUp(int count, Player *player1, Player *player2, Player *player3, Player *player4);
    void explosionAnimation(char **map);
    char generateBonus();
    bool getStatus(Bomb *bomb);
    float getBombPosX(Bomb *bomb);
    float getBombPosZ(Bomb *bomb);
    Vector3 getBombPos(Bomb *bomb);
    std::chrono::system_clock::time_point getTimerBomb();
};

#endif
