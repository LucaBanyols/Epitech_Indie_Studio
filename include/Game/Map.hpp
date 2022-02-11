/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "Menu.hpp"
#include "BombList.hpp"
#include "../Component/KeyEvent.hpp"
#include "../Component/Controller.hpp"

#ifndef MAP_HPP_
#define MAP_HPP_

class Map
{
public:
    char **_map;
    float _sizemapxy;
    Player *_playerOne;
    BombList *_bombListP1;
    Player *_playerTwo;
    BombList *_bombListP2;
    Player *_playerThree;
    BombList *_bombListP3;
    Player *_playerFour;
    BombList *_bombListP4;
    Textures *_textures;
    MakeModel *_model;
    KeyEvent *_keyEvent;
    Controller *_controller1;
    Controller *_controller2;
    Controller *_controller3;
    Controller *_controller4;
    InputHandler *_inputhandler;
    int _isHoverButton;
    int *_arrayHoverButton;
    std::vector<int> _playerOneKey;
    std::vector<int> _playerTwoKey;
    std::vector<int> _playerThreeKey;
    std::vector<int> _playerFourKey;

    Map(Menu *m, std::vector<int> playerOneKey, std::vector<int> playerTwoKey, std::vector<int> playerThreeKey, std::vector<int> playerFourKey);
    Map();
    ~Map() = default;
    char **generateMap();
    void gestionMovesPlayer(Player *player);
    const void drawWall(Texture2D ground, Texture2D box);
    const void drawGround(Texture2D ground);
    const void DrawTheModel(Model player, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 size, Color color);

    char generateBlock();
    char generateVide();
    const int getRandom() const;
    int getSizeMap();
    char **getMap();
    bool getStatusPlayer(int nb);
    Model getModelPlayer(int nb);
    ModelAnimation *getAnimPlayer();

    Texture2D getTexturePlayer(int nb);
    Vector3 getPositionPlayer(int nb);
    Player *getPlayer(int nb);
    void gestionAllBomb(Key *k, Controller* controller1, Controller* controller2, Controller* controller3, Controller* controller4);
    void makeGestionMapBomb(Key *k, BombList *bombList, Player *player);
    void gestionMapBomb(Key *k, Bomb *bomb, BombList *bombList, Player *player);
    void gestionMapBombGamepad(Controller *controller, Bomb *bomb, BombList *bombList, Player *player);
    void gestionMapManyBombsExplosion(Bomb *bomb, BombList *bombList, Player *player);
    void manyBombsExplosion(Bomb *bomb, BombList *bombList, Player *player);
    void cooldownBombMap(Bomb *bomb, BombList *bombList);
    Vector3 getPlayerRotationAxis(int nb);
    float getPlayerRotationAngle(int nb);
    const int getNbLeftPlayerAlive();
};

#endif
