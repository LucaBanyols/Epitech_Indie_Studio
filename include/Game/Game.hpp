/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../Component/IComponent.hpp"
#include "../Input/InputHandler.hpp"
#include "Pause.hpp"
#include "Introduction.hpp"
#include "AI.hpp"

#ifndef GAME_HPP_
#define GAME_HPP_

class Game : IComponent
{
private:
    Camera3D _camera;
    Vector3 _circlePosition;
    Vector3 _rotationAxis;
    Texture2D _ground;
    Texture2D _box;
    Texture2D _wall;
    Texture2D _background;
    Image _imgBackground;
    Music _music;

protected:
    Menu *_menu;
    Pause *_pause;
    Introduction *_intro;
    InputHandler *_inputHandler;
    Vector2 _mousePoint;

public:
    Game();
    ~Game();
    const void setGame();
    const void setComponentGame();
    const bool setPauseGame();
    const void setProcessGame(Map map, AI ai, float nb_test);
    const void setCameraParam(Map map);
    const void setTextures();
    const void setTextureWall();
    const void setTextureGround();
    const void setTextureBox();
    const void setGameMusic();
    const void startGame();
    const void launchGame();
    const void deleteEndProcessGame(Map map) const;
    const void deleteGameMusic() const;
    const void deleteTextures() const;
    const void deleteModel(Model model) const;
    const void deleteGame() const;
};

#endif
