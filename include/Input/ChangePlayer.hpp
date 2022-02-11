/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"
#include "ArrowLeft.hpp"
#include "ArrowRight.hpp"
#include "ArrowDown.hpp"
#include "ArrowUp.hpp"
#include "Border.hpp"

#ifndef CHANGEPLAYER_HPP_
#define CHANGEPLAYER_HPP_

class ChangePlayer : IComponent
{
public:
    ChangePlayer();
    ~ChangePlayer();
    const void setTexturePlayers();
    const void setChangePlayer();
    const void gestionStatePlayerIa(Vector2 &mousePoint, Mouse *mouse);
    const void gestionChangePlayer(Vector2 &mousePoint, Mouse *mouse);
    const void displayTexturePlayers() const;
    const void displayPlayerStatus() const;
    const void displayAllPlayerStatus() const;
    const void displayChangePlayer() const;
    const void deleteTexturePlayers() const;
    const void deleteChangePlayer() const;
    const bool getIsPlayerOne() const;
    const bool getIsPlayerTwo() const;
    const bool getIsPlayerThree() const;
    const bool getIsPlayerFour() const;
    
    ArrowLeft * _arrowLeftButton;
    ArrowRight *_arrowRightButton;
    ArrowUp *_arrowUpButton;
    ArrowDown *_arrowDownButton;
    Border *_border;

    int _x;
    int _y;
    int _selectionNb;

    Texture2D _texturePicturePlayer1;
    Texture2D _texturePicturePlayer2;
    Texture2D _texturePicturePlayer3;
    Texture2D _texturePicturePlayer4;

    int _currentPlayer;
    bool _isPlayerOne;
    bool _isPlayerTwo;
    bool _isPlayerThree;
    bool _isPlayerFour;
};

#endif