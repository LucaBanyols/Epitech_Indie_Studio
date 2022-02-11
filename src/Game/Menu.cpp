/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Game/Menu.hpp"

Menu::Menu()
{
    this->_inputHandler = new InputHandler;

    this->_screenWidth = 1920;
    this->_screenHeight = 1080;

    this->_mapSize = 12;
    this->_isHoverButton = 0;
    this->_arrayHoverButton = new int[2];
    this->_arrayHoverButton[0] = 0;
    this->_arrayHoverButton[1] = 0;

    this->_mousePoint = {0.0f, 0.0f};
}

Menu::~Menu()
{
}

// Setter

const void Menu::setMusicMenu()
{
    try
    {
        this->_menuMusic = this->_musics->getMusicStream("../src/resources/sounds/menu_theme.ogg");
    }
    catch (Music)
    {
        this->_menuMusic = this->_musics->getMusicStream("../../src/resources/sounds/menu_theme.ogg");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
}

const void Menu::setAllMenu(Key *k)
{
    k->setAllKeys();
    this->_inputHandler->_background->setBackground();
    this->_inputHandler->_button->setButtons();
    this->_sound->setSoundButton();
    this->setMusicMenu();
    this->_musics->setPlayStream(getMusicMenu());
}

// Getter

const Music Menu::getMusicMenu() const
{
    return (this->_menuMusic);
}

// Process

const void Menu::allGestion(Key *k)
{
    this->_inputHandler->_button->gestionButton(this->_mousePoint, this->_mouse, this->_sound);
    this->_mapSize = this->_inputHandler->_changeSizeMap->gestionSizeMap(this->_mapSize, this->_inputHandler->_button->_minusButton->_btnMinusAction, this->_inputHandler->_button->_plusButton->_btnPlusAction);
    this->_inputHandler->_button->_minusButton->_btnMinusAction = false;
    this->_inputHandler->_button->_plusButton->_btnPlusAction = false;
}

// Display

const void Menu::allDisplay()
{
    std::string tmp = std::to_string(this->_mapSize);
    const char *tmp_size = tmp.c_str();

    this->_inputHandler->_background->displayBackground();
    this->_inputHandler->_button->displayButton();
    this->_texts->setDrawText(tmp_size, 1830, 435, 80, ORANGE);
}

const int Menu::displayMenu(Key *k)
{
    setAllMenu(k);
    while (!this->_window->getStatusWindow())
    {
        this->_musics->setUpdateMusicStream(getMusicMenu());
        this->_mousePoint = this->_mouse->getMousePos();
        allGestion(k);
        if (this->_inputHandler->_button->_settingButton->_btnSettingAction == true)
        {
            k->startKeys();
            this->_texture->setEndDrawing();
            k->deleteKeys();
        }
        this->_inputHandler->_button->_settingButton->_btnSettingAction = false;
        if (this->_inputHandler->_button->_startButton->_btnStartAction == true)
        {
            return (1);
            break;
        }
        else if (this->_inputHandler->_button->_quitButton->_btnQuitAction == true)
        {
            break;
        }
        this->_texture->setBeginDrawing();
        this->_window->setClearBackground();
        allDisplay();
        this->_texture->setEndDrawing();
    }
    unloadMenuTexture();
    this->_window->deleteWindow();
    return (0);
}

// Delete

const void Menu::deleteMusicMenu() const
{
    this->_musics->deleteMusicStream(this->_menuMusic);
}

const void Menu::unloadMenuTexture()
{
    this->_inputHandler->_button->deleteButtons();
    this->_sound->deleteSoundButton();
    this->deleteMusicMenu();
}