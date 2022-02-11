/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"
#include "BombMax.hpp"
#include "SpeedMax.hpp"
#include "RangeMax.hpp"

class Player : IComponent
{
private:
    int _playerNumber;
    bool _alive;
    SpeedMax *_speedMax;
    BombMax *_bombMax;
    RangeMax *_rangeMax;
    int _throughWall;
    int _wallPass;
    Vector3 _playerPos;
    Texture2D _playerTexture;
    Textures *_texture;
    std::vector<int> _playerKey;

    MakeModel _playerModel;
    Vector3 _rotationAxis;
    float _rotationAngle;

public:
    Player(int playerNumber, Vector3 playerPos, std::vector<int> playerKey, const char *path);
    ~Player();
    const Model getplayerModel() const;
    const ModelAnimation *getplayerAnim(bool Standing) const;
    const int getplayerFrame() const;
    void modifplayerFrame(bool Standing);
    
    Vector3 getRotationAxis();
    float getRotationAngle();

    void setRotationAxis(Vector3 rotationAxis);
    void setRotationAngle(float rotationAngle);

    const float getPositionX() const;
    const float getPositionY() const;
    const float getPositionZ() const;
    const Vector3 getPosition() const;

    void movePlayerUP();
    void movePlayerDOWN();
    void movePlayerLEFT();
    void movePlayerRIGHT();

    void addBomb();
    void addSpeed();
    void addThroughWall();
    void addWallPass();
    void addBombRange();

    const int getBombMax();
    const int getSpeedMax();
    const int getThroughWall();
    const int getWallPass();
    const int getBombRange();

    void fixCoords();

    const Texture2D getTexture() const;
    const int getRandom() const;
    const Sound getSound(const char *path) const;
    const int getKey() const;

    int getPlayerNumber();
    bool getAlive();
    bool setAliveFalse();

    int getKeyUp();
    int getKeyDown();
    int getKeyLeft();
    int getKeyRight();
    int getKeyDrop();
};
