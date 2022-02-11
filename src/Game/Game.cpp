/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Game/Game.hpp"

Game::Game()
{
    this->_menu = new Menu;
    this->_pause = new Pause;
    this->_intro = new Introduction;
    this->_inputHandler = new InputHandler;

    this->_camera = {0};
    this->_circlePosition = {0.5f, 0.0f, 0.0f};
    this->_rotationAxis = {10.0f, 10.0f, 10.0f};
}

Game::~Game()
{
    delete (this->_menu);
    delete (this->_pause);
    delete (this->_intro);
    delete (this->_inputHandler);
}

// Setter

const void Game::setCameraParam(Map map)
{
    Vector3 v1;
    Vector3 v2;
    Vector3 v3;
    v1.x = map.getSizeMap() / 2;
    v1.y = map.getSizeMap() * 1.25f;
    v1.z = map.getSizeMap() * 1.2f;
    this->_camera.position = v1;
    v2.x = map.getSizeMap() / 2;
    v2.y = 0.0f;
    v2.z = map.getSizeMap() / 2;
    this->_camera.target = v2;
    v3.x = 0.0f;
    v3.y = 1.0f;
    v3.z = 0.0f;
    this->_camera.up = v3;
    this->_camera.fovy = 45.0f;
    this->_camera.projection = CAMERA_PERSPECTIVE;
    this->_cameras->setCameraAllMode(this->_camera, CAMERA_FREE);
}

const void Game::setTextureBox()
{
    try
    {
        this->_box = this->_texture->getTexture2D("../src/resources/assets/brique.png");
    }
    catch (Texture2D)
    {
        this->_box = this->_texture->getTexture2D("../../src/resources/assets/brique.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
}

const void Game::setTextureGround()
{
    try
    {
        this->_ground = this->_texture->getTexture2D("../src/resources/assets/ground.png");
    }
    catch (Texture2D)
    {
        this->_ground = this->_texture->getTexture2D("../../src/resources/assets/ground.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
}

const void Game::setTextureWall()
{
    try
    {
        this->_wall = this->_texture->getTexture2D("../src/resources/assets/wall.png");
    }
    catch (Texture2D)
    {
        this->_wall = this->_texture->getTexture2D("../../src/resources/assets/wall.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
}

const void Game::setTextures()
{
    setTextureWall();
    setTextureGround();
    setTextureBox();
    this->_inputHandler->_background->setGameBackground();
}

const void Game::setGameMusic()
{
    try
    {
        this->_music = this->_musics->getMusicStream("../src/resources/sounds/game_theme.ogg");
    }
    catch (Music)
    {
        this->_music = this->_musics->getMusicStream("../../src/resources/sounds/game_theme.ogg");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
    this->_musics->setPlayStream(this->_music);
}

// Process

const void Game::setGame()
{

    this->_keyEvent->setQuitKey(0);
    this->_window->initWindow();
    this->_sound->setSound();
    this->_pause->setPause();
    this->_inputHandler->_background->setEndBackground();
}

const void Game::setComponentGame()
{
    this->_mousePoint = this->_mouse->getMousePos();
    this->_musics->setUpdateMusicStream(this->_music);
    this->_musics->setNewMusicVolume(this->_music, 0.2f);
    this->_cameras->setUpdateCamera(&this->_camera);
    this->_pause->gestionDisplayPause();
    this->_texture->setBeginDrawing();
}

const bool Game::setPauseGame()
{
    if (this->_pause->_btnResumeAction == true)
    {
        this->_pause->displayPause();
    }
    else if (this->_pause->_btnRestartAction == true)
    {
        return (true);
    }
    this->_pause->_btnResumeAction = false;
    return (false);
}

const void Game::setProcessGame(Map map, AI ai, float nb_test)
{

    Vector3 size = {0.01f, 0.01f, 0.01f};
    this->_window->setClearBackground();
    this->_inputHandler->_background->displayGameBackground();
    this->_cameras->setBeginMode3D(this->_camera);
    map.drawGround(this->_ground);
    map.drawWall(this->_wall, this->_box);
    if (this->_pause->_btnResumeAction == false || map.getNbLeftPlayerAlive() <= 1)
    {
        this->_musics->setResumeMusicStream(this->_music);
        if (map.getStatusPlayer(1) == true)
        {
            map.DrawTheModel(map.getModelPlayer(1),
                             map.getPositionPlayer(1),
                             map.getPlayerRotationAxis(1),
                             map.getPlayerRotationAngle(1), size, RED);
            if (this->_inputHandler->_key->_changePlayer->_isPlayerOne == true)
                map.gestionMovesPlayer(map.getPlayer(1));
            else
                ai.gestionMovesAI(map.getPlayer(1), map);
        }
        if (map.getStatusPlayer(2) == true)
        {
            map.DrawTheModel(map.getModelPlayer(2),
                             map.getPositionPlayer(2),
                             map.getPlayerRotationAxis(2),
                             map.getPlayerRotationAngle(2), size, BLUE);
            if (this->_inputHandler->_key->_changePlayer->_isPlayerTwo == true)
                map.gestionMovesPlayer(map.getPlayer(2));
            else
                ai.gestionMovesAI(map.getPlayer(2), map);
        }
        if (map.getStatusPlayer(3) == true)
        {
            map.DrawTheModel(map.getModelPlayer(3),
                             map.getPositionPlayer(3),
                             map.getPlayerRotationAxis(3),
                             map.getPlayerRotationAngle(3), size, GREEN);
            if (this->_inputHandler->_key->_changePlayer->_isPlayerThree == true)
                map.gestionMovesPlayer(map.getPlayer(3));
            else
                ai.gestionMovesAI(map.getPlayer(3), map);
        }
        if (map.getStatusPlayer(4) == true)
        {
            map.DrawTheModel(map.getModelPlayer(4),
                             map.getPositionPlayer(4),
                             map.getPlayerRotationAxis(4),
                             map.getPlayerRotationAngle(4), size, PINK);
            if (this->_inputHandler->_key->_changePlayer->_isPlayerFour == true)
                map.gestionMovesPlayer(map.getPlayer(4));
            else
                ai.gestionMovesAI(map.getPlayer(4), map);
        }
        nb_test += 1.0f;
        map.gestionAllBomb(this->_inputHandler->_key, this->_inputHandler->_controller1, this->_inputHandler->_controller2,this->_inputHandler->_controller3, this->_inputHandler->_controller4);
    }
    else
    {
        this->_musics->setPauseMusicStream(this->_music);
    }
    this->_cameras->setEndMode3D();
    if (map.getNbLeftPlayerAlive() <= 1)
    {
        this->_inputHandler->_background->displayEndBackground();
        if (map.getStatusPlayer(1) == true)
            this->_texts->setDrawText("PLAYER 1 (RED)\nWINS", 300, 1080 / 2 - 90, 90, BLACK);
        else if (map.getStatusPlayer(2) == true)
            this->_texts->setDrawText("PLAYER 2 (BLUE)\nWINS", 300, 1080 / 2 - 90, 90, BLACK);
        else if (map.getStatusPlayer(3) == true)
            this->_texts->setDrawText("PLAYER 3 (GREEN)\nWINS", 300, 1080 / 2 - 90, 90, BLACK);
        else if (map.getStatusPlayer(4) == true)
            this->_texts->setDrawText("PLAYER 4 (PINK)\nWINS", 300, 1080 / 2 - 90, 90, BLACK);
        else if ((map.getNbLeftPlayerAlive() == 0))
            this->_texts->setDrawText("EVERYONE IS DEAD,\nNO WINNER", 300, 1080 / 2 - 90, 90, BLACK);
        this->_texts->setDrawText("CLICK TO RESTART", 300, 1080 / 2 + 300, 80, BLACK);
        if (IsMouseButtonPressed(0) == true)
            this->_pause->_btnRestartAction = true;
    }
    this->_window->displayFps();
    this->_texture->setEndDrawing();
}

const void Game::launchGame()
{
    Map map(this->_menu, this->_inputHandler->_key->_playerOneKey, this->_inputHandler->_key->_playerTwoKey, this->_inputHandler->_key->_playerThreeKey, this->_inputHandler->_key->_playerFourKey);
    AI ai;
    float nb_test = 1.0f;

    setCameraParam(map);
    setTextures();
    this->_pause->setPause();
    setGameMusic();
    while (!this->_window->getStatusWindow())
    {
        setComponentGame();
        if (setPauseGame() == true)
            break;
        if (this->_pause->_btnQuitAction == true)
        {
            break;
        }
        setProcessGame(map, ai, nb_test);
    }
    deleteEndProcessGame(map);
    if (this->_pause->_btnRestartAction == true)
    {
        this->_pause->_btnRestartAction = false;
        launchGame();
    }
    deleteGame();
}

const void Game::startGame()
{
    setGame();
    if (this->_inputHandler->_splashScreen->displaySplashScreen() == 1)
    {
        if (this->_menu->displayMenu(this->_inputHandler->_key) == 1)
        {
            this->_intro->displayIntro();
            if (this->_intro->_statusIntro == true)
            {
                this->_intro->deleteIntro();
                launchGame();
            }
        }
    }
}

// Delete

const void Game::deleteEndProcessGame(Map map) const
{
    for (int a = 0; a < map.getSizeMap(); a++)
        delete (map.getMap()[a]);
    deleteModel(map.getModelPlayer(1));
    deleteModel(map.getModelPlayer(2));
    deleteModel(map.getModelPlayer(3));
    deleteModel(map.getModelPlayer(4));
}

const void Game::deleteGameMusic() const
{
    this->_musics->deleteMusicStream(this->_music);
}

const void Game::deleteGame() const
{
    deleteTextures();
    this->_pause->deletePause();
}

const void Game::deleteModel(Model model) const
{
    UnloadModel(model);
}

const void Game::deleteTextures() const
{
    this->_inputHandler->_background->deleteEndBackground();
    this->_inputHandler->_background->deleteGameBackground();
    this->_texture->setUnloadTexture(this->_ground);
    this->_texture->setUnloadTexture(this->_wall);
    this->_texture->setUnloadTexture(this->_box);
}