/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Game/Map.hpp"

Map::Map(Menu *m, std::vector<int> playerOneKey, std::vector<int> playerTwoKey, std::vector<int> playerThreeKey, std::vector<int> playerFourKey)
{
    this->_sizemapxy = m->_mapSize;
    this->_map = new char *[(int)this->_sizemapxy];
    this->_map = generateMap();
    this->_playerOneKey.push_back(playerOneKey[0]);
    this->_playerOneKey.push_back(playerOneKey[1]);
    this->_playerOneKey.push_back(playerOneKey[2]);
    this->_playerOneKey.push_back(playerOneKey[3]);
    this->_playerOneKey.push_back(playerOneKey[4]);
    this->_playerOne = new Player(1, {1.0f, 0.5f, 1.0f}, this->_playerOneKey, "../src/resources/assets/red.png");
    this->_bombListP1 = new BombList();
    this->_playerTwoKey.push_back(playerTwoKey[0]);
    this->_playerTwoKey.push_back(playerTwoKey[1]);
    this->_playerTwoKey.push_back(playerTwoKey[2]);
    this->_playerTwoKey.push_back(playerTwoKey[3]);
    this->_playerTwoKey.push_back(playerTwoKey[4]);
    this->_playerTwo = new Player(2, {this->_sizemapxy - 2.0f, 0.5f, 1.0f}, this->_playerTwoKey, "../src/resources/assets/blue.png");
    this->_bombListP2 = new BombList();
    this->_playerThreeKey.push_back(playerThreeKey[0]);
    this->_playerThreeKey.push_back(playerThreeKey[1]);
    this->_playerThreeKey.push_back(playerThreeKey[2]);
    this->_playerThreeKey.push_back(playerThreeKey[3]);
    this->_playerThreeKey.push_back(playerThreeKey[4]);
    this->_playerThree = new Player(3, {1.0f, 0.5f, this->_sizemapxy - 2.0f}, this->_playerThreeKey, "../src/resources/assets/green.png");
    this->_bombListP3 = new BombList();
    this->_playerFourKey.push_back(playerFourKey[0]);
    this->_playerFourKey.push_back(playerFourKey[1]);
    this->_playerFourKey.push_back(playerFourKey[2]);
    this->_playerFourKey.push_back(playerFourKey[3]);
    this->_playerFourKey.push_back(playerFourKey[4]);
    this->_playerFour = new Player(4, {this->_sizemapxy - 2.0f, 0.5f, this->_sizemapxy - 2.0f}, this->_playerFourKey, "../src/resources/assets/pink.png");
    this->_bombListP4 = new BombList();
    this->_keyEvent = new KeyEvent;
    this->_controller1 = new Controller;
    this->_controller2 = new Controller;
    this->_controller3 = new Controller;
    this->_controller4 = new Controller;
    this->_inputhandler = new InputHandler;
}

Map::Map()
{
}

char **Map::generateMap()
{
    for (int h = 0; h < this->_sizemapxy; h++)
        this->_map[h] = new char[(int)this->_sizemapxy];
    for (int a = 0; a < this->_sizemapxy; a++)
    {
        for (int b = 0; b < this->_sizemapxy; b++)
        {
            this->_map[a][b] = VIDE;
        }
    }
    for (int x = 0; x < this->_sizemapxy; x++)
    {
        for (int y = 0; y < this->_sizemapxy; y++)
        {
            if (x == 0 || y == 0 || x == this->_sizemapxy - 1 || y == this->_sizemapxy - 1 || (x == 2 && y == 2) || (x == this->_sizemapxy - 3 && y == this->_sizemapxy - 3) || (x == 2 && y == this->_sizemapxy - 3) || (x == this->_sizemapxy - 3 && y == 2))
                this->_map[x][y] = MUR_INCASSABLE;
            else if ((x == 1 && y < 3) || (x == 1 && y > this->_sizemapxy - 4) || (y == 1 && x < 3) || (y == 1 && x > this->_sizemapxy - 4) || (x == this->_sizemapxy - 2 && y < 3) || (x == this->_sizemapxy - 2 && y > this->_sizemapxy - 4) || (y == this->_sizemapxy - 2 && x < 3) || (y == this->_sizemapxy - 2 && x > this->_sizemapxy - 4))
                this->_map[x][y] = VIDE;
            else if ((y == 1 && x >= 4 && x <= this->_sizemapxy - 5 && this->_map[x + 1][y] != MUR_INCASSABLE && this->_map[x - 1][y] != MUR_INCASSABLE && this->_map[x + 1][y + 1] != MUR_INCASSABLE && this->_map[x][y + 1] != MUR_INCASSABLE && this->_map[x - 1][y + 1] != MUR_INCASSABLE) || (x == 1 && y >= 4 && y <= this->_sizemapxy - 5 && this->_map[x][y - 1] != MUR_INCASSABLE && this->_map[x][y + 1] != MUR_INCASSABLE && this->_map[x + 1][y - 1] != MUR_INCASSABLE && this->_map[x + 1][y] != MUR_INCASSABLE && this->_map[x + 1][y + 1] != MUR_INCASSABLE) || (y == this->_sizemapxy - 2 && x >= 4 && x <= this->_sizemapxy - 5 && this->_map[x - 1][y] != MUR_INCASSABLE && this->_map[x + 1][y] != MUR_INCASSABLE && this->_map[x - 1][y - 1] != MUR_INCASSABLE && this->_map[x][y - 1] != MUR_INCASSABLE && this->_map[x + 1][y - 1] != MUR_INCASSABLE) || (x == this->_sizemapxy - 2 && y >= 4 && y <= this->_sizemapxy - 5 && this->_map[x][y - 1] != MUR_INCASSABLE && this->_map[x - 1][y - 1] != MUR_INCASSABLE && this->_map[x - 1][y] != MUR_INCASSABLE && this->_map[x - 1][y + 1] != MUR_INCASSABLE && this->_map[x][y + 1] != MUR_INCASSABLE) || (this->_map[x - 1][y - 1] != MUR_INCASSABLE && this->_map[x][y - 1] != MUR_INCASSABLE && this->_map[x + 1][y - 1] != MUR_INCASSABLE && this->_map[x - 1][y] != MUR_INCASSABLE && this->_map[x + 1][y] != MUR_INCASSABLE && this->_map[x - 1][y + 1] != MUR_INCASSABLE && this->_map[x][y + 1] != MUR_INCASSABLE && this->_map[x + 1][y + 1] != MUR_INCASSABLE))
                this->_map[x][y] = generateBlock();
            else
                this->_map[x][y] = generateVide();
        }
    }
    return (this->_map);
}

void Map::gestionMovesPlayer(Player *player)
{
    // player->modifplayerFrame(true);
    // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(true)[0], player->getplayerFrame());
    if (player->getWallPass() == 1)
    {
        if (this->_keyEvent->getIsKeyDown(player->getKeyUp()))
        {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {

                if (this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE)
                {
                    player->movePlayerUP();
                    player->setRotationAxis({0.0f, 1.0f, 1.0f});
                    player->setRotationAngle(180.0f);
                }
            }
        }
        else if (this->_controller1->IsControllerAvailable(0) && this->_controller1->GetControllerButtonPressed() == 1) {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {

                if (this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE)
                {
                    player->movePlayerUP();
                    player->setRotationAxis({0.0f, 1.0f, 1.0f});
                    player->setRotationAngle(180.0f);
                }
            }
        }
        if (this->_keyEvent->getIsKeyDown(player->getKeyDown()))
        {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {
                if (this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE)
                {
                    player->movePlayerDOWN();
                    player->setRotationAxis({1.0f, 0.0f, 0.0f});
                    player->setRotationAngle(-90.0f);
                }
            }
        }
        else if (this->_controller1->IsControllerAvailable(0) && this->_controller1->GetControllerButtonPressed() == 3) {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {

                if (this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE)
                {
                    player->movePlayerDOWN();
                    player->setRotationAxis({1.0f, 0.0f, 0.0f});
                    player->setRotationAngle(-90.0f);
                }
            }
        }
        if (this->_keyEvent->getIsKeyDown(player->getKeyLeft()))
        {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {

                if (this->_map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && this->_map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE)
                {
                    player->movePlayerLEFT();
                    player->setRotationAxis({1.0f, 1.0f, 1.0f});
                    player->setRotationAngle(240.0f);
                }
            }
        }
        else if (this->_controller1->IsControllerAvailable(0) && this->_controller1->GetControllerButtonPressed() == 4) {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {


                if (this->_map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && this->_map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE)
                {
                    player->movePlayerLEFT();
                    player->setRotationAxis({1.0f, 1.0f, 1.0f});
                    player->setRotationAngle(240.0f);
                }
            }
        }
        if (this->_keyEvent->getIsKeyDown(player->getKeyRight()))
        {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {

                if (this->_map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && this->_map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE)
                {
                    player->movePlayerRIGHT();
                    player->setRotationAxis({1.0f, -1.0f, -1.0f});
                    player->setRotationAngle(240.0f);
                }
            }
        }
        else if (this->_controller1->IsControllerAvailable(0) && this->_controller1->GetControllerButtonPressed() == 2) {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {

                if (this->_map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && this->_map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE)
                {
                    player->movePlayerRIGHT();
                    player->setRotationAxis({1.0f, -1.0f, -1.0f});
                    player->setRotationAngle(240.0f);
                }
            }
        }
    }
    else
    {
        if (this->_keyEvent->getIsKeyDown(player->getKeyUp()))
        {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {

                if (this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_CASSABLE && this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_CASSABLE && this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != BOMB && this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != BOMB)
                {
                    player->movePlayerUP();
                    player->setRotationAxis({0.0f, 1.0f, 1.0f});
                    player->setRotationAngle(180.0f);
                }
            }
        }
        else if (this->_controller1->IsControllerAvailable(0) && this->_controller1->GetControllerButtonPressed() == 1) {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {

                if (this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE && this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] != MUR_INCASSABLE)
                {
                    player->movePlayerUP();
                    player->setRotationAxis({0.0f, 1.0f, 1.0f});
                    player->setRotationAngle(180.0f);
                }
            }
        }
        
        if (this->_keyEvent->getIsKeyDown(player->getKeyDown()))
        {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {

                if (this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_CASSABLE && this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_CASSABLE && this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != BOMB && this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != BOMB)
                {
                    player->movePlayerDOWN();
                    player->setRotationAxis({1.0f, 0.0f, 0.0f});
                    player->setRotationAngle(-90.0f);
                }
            }
        }
        else if (this->_controller1->IsControllerAvailable(0) && this->_controller1->GetControllerButtonPressed() == 3) {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {

                if (this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE && this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] != MUR_INCASSABLE)
                {
                    player->movePlayerDOWN();
                    player->setRotationAxis({1.0f, 0.0f, 0.0f});
                    player->setRotationAngle(-90.0f);
                }
            }
        }
        if (this->_keyEvent->getIsKeyDown(player->getKeyLeft()))
        {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {

                if (this->_map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && this->_map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_CASSABLE && this->_map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE && this->_map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_CASSABLE && this->_map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != BOMB && this->_map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != BOMB)
                {
                    player->movePlayerLEFT();
                    player->setRotationAxis({1.0f, 1.0f, 1.0f});
                    player->setRotationAngle(240.0f);
                }
            }
        }
        else if (this->_controller1->IsControllerAvailable(0) && this->_controller1->GetControllerButtonPressed() == 4) {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {

                if (this->_map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && this->_map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE)
                {
                    player->movePlayerLEFT();
                    player->setRotationAxis({1.0f, 1.0f, 1.0f});
                    player->setRotationAngle(240.0f);
                }
            }
        }
        if (this->_keyEvent->getIsKeyDown(player->getKeyRight()))
        {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {

                if (this->_map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && this->_map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_CASSABLE && this->_map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE && this->_map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_CASSABLE && this->_map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != BOMB && this->_map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != BOMB)
                {
                    player->movePlayerRIGHT();
                    player->setRotationAxis({1.0f, -1.0f, -1.0f});
                    player->setRotationAngle(240.0f);
                }
            }
        }
        else if (this->_controller1->IsControllerAvailable(0) && this->_controller1->GetControllerButtonPressed() == 2) {
            // player->modifplayerFrame(false);
            // this->_model->setUpdateModelAnimation(player->getplayerModel(), player->getplayerAnim(false)[0], player->getplayerFrame());
            for (int i = 0; i < player->getSpeedMax(); i++) {

                if (this->_map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] != MUR_INCASSABLE && this->_map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] != MUR_INCASSABLE)
                {
                    player->movePlayerRIGHT();
                    player->setRotationAxis({1.0f, -1.0f, -1.0f});
                    player->setRotationAngle(240.0f);
                }
            }
        }
    }
    if (this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == BOMB_WITH_PLAYER && this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 0.99)] == VIDE)
    {
        this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] = BOMB;
    }
    if (this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == BOMB_WITH_PLAYER && this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 0.99)] == VIDE)
    {
        this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] = BOMB;
    }
    if (this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == BOMB_WITH_PLAYER && this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ())] == VIDE)
    {
        this->_map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] = BOMB;
    }
    if (this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == BOMB_WITH_PLAYER && this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ())] == VIDE)
    {
        this->_map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] = BOMB;
    }
    if (this->_map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] == BOMB_WITH_PLAYER && this->_map[int(player->getPositionX() + 0.99)][int(floor(player->getPositionZ()))] == VIDE)
    {
        this->_map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] = BOMB;
    }
    if (this->_map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] == BOMB_WITH_PLAYER && this->_map[int(player->getPositionX() + 0.99)][int(ceil(player->getPositionZ()))] == VIDE)
    {
        this->_map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] = BOMB;
    }

    if (this->_map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] == BOMB_WITH_PLAYER && this->_map[int(player->getPositionX())][int(floor(player->getPositionZ()))] == VIDE)
    {
        this->_map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] = BOMB;
    }
    if (this->_map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] == BOMB_WITH_PLAYER && this->_map[int(player->getPositionX())][int(ceil(player->getPositionZ()))] == VIDE)
    {
        this->_map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] = BOMB;
    }

    if (this->_map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] == BONUS_BOM_SUP)
    {
        player->addBomb();
        this->_map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] = VIDE;
    }
    if (this->_map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] == BONUS_RANGE_SUP)
    {
        player->addBombRange();
        this->_map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] = VIDE;
    }
    if (this->_map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] == BONUS_SPEED_SUP)
    {
        player->addSpeed();
        this->_map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] = VIDE;
    }
    if (this->_map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] == BONUS_EXPLOSION_TRAVERS)
    {
        player->addThroughWall();
        this->_map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] = VIDE;
    }
    if (this->_map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] == BONUS_WALL_PASS)
    {
        player->addWallPass();
        this->_map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] = VIDE;
    }
    player->fixCoords();
}

const void Map::drawWall(Texture2D ground, Texture2D box)
{
    Vector3 cubePosition = {-0.5f, 0.0f, 0.0f};
    float k = 0.0f;
    float l = 0.0f;

    for (int i = 0; i < this->_sizemapxy; i++)
    {
        for (int j = 0; j < this->_sizemapxy; j++)
        {
            cubePosition = {(float)i, 0.5f, (float)j};
            if (this->_map[i][j] == MUR_INCASSABLE)
            {
                this->_textures->setDrawCubeTexture(ground, cubePosition, 1.0, 1.0f, 1.0f, WHITE);
            }
            else if (this->_map[i][j] == MUR_CASSABLE)
            {
                this->_textures->setDrawCubeTexture(box, cubePosition, 1.0, 1.0f, 1.0f, WHITE);
            }
            else if (this->_map[i][j] == BONUS_BOM_SUP)
            {
                this->_textures->setDrawSphere(cubePosition, 0.3f, BLACK);
            }
            else if (this->_map[i][j] == BONUS_RANGE_SUP)
            {
                this->_textures->setDrawSphere(cubePosition, 0.3f, GREEN);
            }
            else if (this->_map[i][j] == BONUS_SPEED_SUP)
            {
                this->_textures->setDrawSphere(cubePosition, 0.3f, YELLOW);
            }
            else if (this->_map[i][j] == BONUS_EXPLOSION_TRAVERS)
            {
                this->_textures->setDrawSphere(cubePosition, 0.3f, RED);
            }
            else if (this->_map[i][j] == BONUS_WALL_PASS)
            {
                this->_textures->setDrawSphere(cubePosition, 0.3f, PURPLE);
            }
        }
        l = 0.0f;
    }
}

const void Map::drawGround(Texture2D ground)
{
    Vector3 cubePosition = {-0.5f, 0.0f, 0.0f};

    for (float i = 0; i < this->_sizemapxy; i += 1)
    {
        for (float j = 0; j < this->_sizemapxy; j += 1)
        {
            cubePosition = {i, 0.0f, j};
            DrawCubeTexture(ground, cubePosition, 1.0f, 0.0f, 1.0f, WHITE);
        }
    }
}

const void Map::DrawTheModel(Model player, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 size, Color color)
{
    return (DrawModelEx(player, position, rotationAxis, rotationAngle, size, color));
}

char Map::generateBlock()
{
    int randnb = getRandom();

    if (randnb == 1 || randnb == 2)
        return (MUR_INCASSABLE);
    return (MUR_CASSABLE);
}

char Map::generateVide()
{
    int randnb = getRandom();

    if (randnb == 1 || randnb == 2)
        return (VIDE);
    return (MUR_CASSABLE);
}

const int Map::getRandom() const
{
    return (GetRandomValue(1, 8));
}

int Map::getSizeMap()
{
    return (this->_sizemapxy);
}

char **Map::getMap()
{
    return (this->_map);
}

Model Map::getModelPlayer(int nb)
{
    if (nb == 1)
        return this->_playerOne->getplayerModel();
    else if (nb == 2)
        return this->_playerTwo->getplayerModel();
    else if (nb == 3)
        return this->_playerThree->getplayerModel();
    else
        return this->_playerFour->getplayerModel();
}

// ModelAnimation *Map::getAnimPlayer()
// {
//     return this->_playerOne->getplayerAnim();
// }

Texture2D Map::getTexturePlayer(int nb)
{
    if (nb == 1)
        return (this->_playerOne->getTexture());
    else if (nb == 2)
        return (this->_playerTwo->getTexture());
    else if (nb == 3)
        return (this->_playerThree->getTexture());
    else
        return (this->_playerFour->getTexture());
}

Vector3 Map::getPositionPlayer(int nb)
{
    if (nb == 1)
        return (this->_playerOne->getPosition());
    else if (nb == 2)
        return (this->_playerTwo->getPosition());
    else if (nb == 3)
        return (this->_playerThree->getPosition());
    else
        return (this->_playerFour->getPosition());
}

Player *Map::getPlayer(int nb)
{
    if (nb == 1)
        return (this->_playerOne);
    else if (nb == 2)
        return (this->_playerTwo);
    else if (nb == 3)
        return (this->_playerThree);
    else
        return (this->_playerFour);
}

bool Map::getStatusPlayer(int nb)
{
    if (nb == 1)
        return (this->_playerOne->getAlive());
    else if (nb == 2)
        return (this->_playerTwo->getAlive());
    else if (nb == 3)
        return (this->_playerThree->getAlive());
    else
        return (this->_playerFour->getAlive());
}

void Map::gestionAllBomb(Key *k, Controller *controller1, Controller *controller2, Controller *controller3, Controller *controller4)
{
    if (this->getStatusPlayer(1) == true)
    {
        makeGestionMapBomb(k, this->_bombListP1, this->_playerOne);
        gestionMapBombGamepad(this->_controller1, this->_bombListP1->getBomb1(), this->_bombListP1, this->_playerOne);
        gestionMapBombGamepad(this->_controller1, this->_bombListP1->getBomb2(), this->_bombListP1, this->_playerOne);
        gestionMapBombGamepad(this->_controller1, this->_bombListP1->getBomb3(), this->_bombListP1, this->_playerOne);
        gestionMapBombGamepad(this->_controller1, this->_bombListP1->getBomb4(), this->_bombListP1, this->_playerOne);
        gestionMapBombGamepad(this->_controller1, this->_bombListP1->getBomb5(), this->_bombListP1, this->_playerOne);
        gestionMapBombGamepad(this->_controller1, this->_bombListP1->getBomb6(), this->_bombListP1, this->_playerOne);
        gestionMapBombGamepad(this->_controller1, this->_bombListP1->getBomb7(), this->_bombListP1, this->_playerOne);
        gestionMapBombGamepad(this->_controller1, this->_bombListP1->getBomb8(), this->_bombListP1, this->_playerOne);
        gestionMapBombGamepad(this->_controller1, this->_bombListP1->getBomb9(), this->_bombListP1, this->_playerOne);
        gestionMapBombGamepad(this->_controller1, this->_bombListP1->getBomb10(), this->_bombListP1, this->_playerOne);
    }
    if (this->getStatusPlayer(2) == true)
    {
        makeGestionMapBomb(k, this->_bombListP2, this->_playerTwo);
    }
    if (this->getStatusPlayer(3) == true)
    {
        makeGestionMapBomb(k, this->_bombListP3, this->_playerThree);
    }
    if (this->getStatusPlayer(4) == true)
    {
        makeGestionMapBomb(k, this->_bombListP4, this->_playerFour);
    }
}

void Map::makeGestionMapBomb(Key *k, BombList *bombList, Player *player)
{
    gestionMapBomb(k, bombList->getBomb1(), bombList, player);
    gestionMapBomb(k, bombList->getBomb2(), bombList, player);
    gestionMapBomb(k, bombList->getBomb3(), bombList, player);
    gestionMapBomb(k, bombList->getBomb4(), bombList, player);
    gestionMapBomb(k, bombList->getBomb5(), bombList, player);
    gestionMapBomb(k, bombList->getBomb6(), bombList, player);
    gestionMapBomb(k, bombList->getBomb7(), bombList, player);
    gestionMapBomb(k, bombList->getBomb8(), bombList, player);
    gestionMapBomb(k, bombList->getBomb9(), bombList, player);
    gestionMapBomb(k, bombList->getBomb10(), bombList, player);
}

void Map::gestionMapBombGamepad(Controller* controller, Bomb *bomb, BombList *bombList, Player *player)
{
    if (controller->IsControllerAvailable(0) && controller->GetControllerButtonPressed() == 7) {
        std::cout << "Button pressed : " << controller->GetControllerButtonPressed() << std::endl;
        if (((bomb->getStatus(bomb) == false) 
        && ((float)floor(player->getPositionX() + 0.5)) != bomb->getBombPosX(bomb)) 
        || (((float)floor(player->getPositionX() + 0.5)) != bomb->getBombPosZ(bomb))
        && (this->_map[(int)(floor(player->getPositionX() + 0.5))][(int)(floor(player->getPositionZ() + 0.5))] == VIDE)
        && (bombList->getCurrentBomb() < player->getBombMax())) {
            bomb->gestionBomb(bomb, player);
            this->_map[(int)bomb->getBombPosX(bomb)][(int)bomb->getBombPosZ(bomb)] = BOMB_WITH_PLAYER;
            bombList->addCurrentBomb(bombList);
        }
        gestionMapManyBombsExplosion(bomb, bombList, player);
        cooldownBombMap(bomb, bombList);
    }
}

void Map::gestionMapBomb(Key *k, Bomb *bomb, BombList *bombList, Player *player)
{
    if (((this->_keyEvent->getIsKeyPressed(player->getKeyDrop()))) && (bomb->getStatus(bomb) == false) 
    && ((((float)floor(player->getPositionX() + 0.5)) != bomb->getBombPosX(bomb)) 
    || (((float)floor(player->getPositionX() + 0.5)) != bomb->getBombPosZ(bomb))) 
    && (this->_map[(int)(floor(player->getPositionX() + 0.5))][(int)(floor(player->getPositionZ() + 0.5))] == VIDE) 
    && (bombList->getCurrentBomb() < player->getBombMax()))
    {
        //std::cout << this->_controller1->GetControllerButtonPressed() << std::endl;
        bomb->gestionBomb(bomb, player);
        this->_map[(int)bomb->getBombPosX(bomb)][(int)bomb->getBombPosZ(bomb)] = BOMB_WITH_PLAYER;
        bombList->addCurrentBomb(bombList);
    }
    gestionMapManyBombsExplosion(bomb, bombList, player);
    cooldownBombMap(bomb, bombList);
}

void Map::gestionMapManyBombsExplosion(Bomb *bomb, BombList *bombList, Player *player)
{
    if (bomb->getStatus(bomb) == true)
        manyBombsExplosion(bomb, bombList, player);
}

void Map::manyBombsExplosion(Bomb *bomb, BombList *bombList, Player *player)
{
    if (std::chrono::system_clock::now() < bomb->getTimerBomb())
    {
        this->_textures->setDrawSphere(bomb->getBombPos(bomb), 0.3f, BLUE);
        if (std::chrono::system_clock::now() + std::chrono::milliseconds(500) > bomb->getTimerBomb())
        {
            this->_textures->setDrawSphere(bomb->getBombPos(bomb), 0.3f, GRAY);
            this->_map = bomb->dispawn_boxes(this->_map, player, this->_playerOne, this->_playerTwo, this->_playerThree, this->_playerFour);
            this->_map[(int)bomb->getBombPosX(bomb)][(int)bomb->getBombPosZ(bomb)] = VIDE;
        }
    }
}

void Map::cooldownBombMap(Bomb *bomb, BombList *bombList)
{
    if (bomb->getStatus(bomb) == true)
    {
        bomb->cooldownBomb(bomb);
        if (bomb->getStatus(bomb) == false)
            bombList->subCurrentBomb(bombList);
    }
}

Vector3 Map::getPlayerRotationAxis(int nb)
{
    if (nb == 1)
        return (this->_playerOne->getRotationAxis());
    else if (nb == 2)
        return (this->_playerTwo->getRotationAxis());
    else if (nb == 3)
        return (this->_playerThree->getRotationAxis());
    else
        return (this->_playerFour->getRotationAxis());
}

float Map::getPlayerRotationAngle(int nb)
{
    if (nb == 1)
        return (this->_playerOne->getRotationAngle());
    else if (nb == 2)
        return (this->_playerTwo->getRotationAngle());
    else if (nb == 3)
        return (this->_playerThree->getRotationAngle());
    else
        return (this->_playerFour->getRotationAngle());
}

const int Map::getNbLeftPlayerAlive()
{
    int nbPlayerAlive = 0;

    if (this->_playerOne->getAlive() == true)
        nbPlayerAlive++;
    if (this->_playerTwo->getAlive() == true)
        nbPlayerAlive++;
    if (this->_playerThree->getAlive() == true)
        nbPlayerAlive++;
    if (this->_playerFour->getAlive() == true)
        nbPlayerAlive++;
    return (nbPlayerAlive);
}