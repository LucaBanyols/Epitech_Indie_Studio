/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Game/Player.hpp"


Player::Player(int playerNumber, Vector3 playerPos, std::vector<int> playerKey, const char *path)
{
    this->_playerNumber = playerNumber;
    this->_alive = true;
    this->_bombMax = new BombMax();
    this->_rangeMax = new RangeMax();
    this->_speedMax = new SpeedMax();
    this->_throughWall = 0;
    this->_wallPass = 0;
    this->_playerPos = playerPos;
    this->_playerTexture = this->_texture->getTexture2D(path);
    this->_playerKey = playerKey;
    SetMaterialTexture(&this->getplayerModel().materials[0], MAP_DIFFUSE, this->_playerTexture);
    this->_rotationAxis = { 1.0f, 0.0f, 0.0f };
    this->_rotationAngle = -90.0f;
}

Player::~Player()
{
}

const Model Player::getplayerModel() const
{
    return this->_playerModel.getModel();
}

const ModelAnimation *Player::getplayerAnim(bool Standing) const
{
    return this->_playerModel.getAnimModel(Standing);
}

const int Player::getplayerFrame() const
{
    return this->_playerModel.getAnimFrameCounter();
}

void Player::modifplayerFrame(bool Standing)
{
    _playerModel.setAnimFrameCounter(Standing);
}

Vector3 Player::getRotationAxis()
{
    return (this->_rotationAxis);
}

void Player::setRotationAxis(Vector3 rotationAxis)
{
    this->_rotationAxis = rotationAxis;
}

void Player::setRotationAngle(float rotationAngle)
{
    this->_rotationAngle = rotationAngle;
}

float Player::getRotationAngle()
{
    return (this->_rotationAngle);
}

const float Player::getPositionX() const
{
    return (this->_playerPos.x);
}

const float Player::getPositionY() const
{
    return (this->_playerPos.y);
}

const float Player::getPositionZ() const
{
    return (this->_playerPos.z);
}

const Vector3 Player::getPosition() const
{
    return (this->_playerPos);
}

const Texture2D Player::getTexture() const
{
    return (this->_playerTexture);
}

void Player::movePlayerUP()
{
    this->_playerPos.z -= 0.01;
}

void Player::movePlayerDOWN()
{
    this->_playerPos.z += 0.01;
}

void Player::movePlayerLEFT()
{
    this->_playerPos.x -= 0.01;
}

void Player::movePlayerRIGHT()
{
    this->_playerPos.x += 0.01;
}

void Player::addBomb()
{
    if (this->_bombMax->getBombMax() < 10)
        this->_bombMax->addBomb();
}

void Player::addBombRange()
{
    this->_rangeMax->addRange();
}

void Player::addSpeed()
{
    this->_speedMax->addSpeed();
}

void Player::addThroughWall()
{
    this->_throughWall = 1;
}

void Player::addWallPass()
{
    this->_wallPass = 1;
}

void Player::fixCoords()
{
    this->_playerPos.x = (float)floor(this->_playerPos.x * 100 + 0.05) / 100;
    this->_playerPos.z = (float)floor(this->_playerPos.z * 100 + 0.05) / 100;
}

const int Player::getBombMax()
{
    return (this->_bombMax->getBombMax());
}

const int Player::getBombRange()
{
    return (this->_rangeMax->getRangeMax());
}

const int Player::getSpeedMax()
{
    return (this->_speedMax->getSpeedMax());
}

const int Player::getThroughWall()
{
    return (this->_throughWall);
}

const int Player::getWallPass()
{
    return (this->_wallPass);
}

const int Player::getRandom() const
{
    return (GetRandomValue(1, 8));
}

const Sound Player::getSound(const char *path) const
{
    return (LoadSound(path));
}

const int Player::getKey() const
{
    return (0);
}

int Player::getPlayerNumber()
{
    return (this->_playerNumber);
}

int Player::getKeyUp()
{
    return (this->_playerKey[0]);
}

int Player::getKeyDown()
{
    return (this->_playerKey[1]);
}

int Player::getKeyLeft()
{
    return (this->_playerKey[2]);
}

int Player::getKeyRight()
{
    return (this->_playerKey[3]);
}

int Player::getKeyDrop()
{
    return (this->_playerKey[4]);
}

bool Player::getAlive()
{
    return (this->_alive);
}

bool Player::setAliveFalse()
{
    return (this->_alive = false);
}