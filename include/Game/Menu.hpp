/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../Input/InputHandler.hpp"
#include "../Component/IComponent.hpp"

#ifndef MENU_HPP_
#define MENU_HPP_

class Menu : IComponent
{
private:
    Music _menuMusic;

protected:
    Vector2 _mousePoint;

    int _isHoverButton;
    int *_arrayHoverButton;

    InputHandler *_inputHandler;

public:
    Menu();
    ~Menu();

    // Setter

    const void setMusicMenu();
    const void setAllMenu(Key *k);

    // Getter

    const Music getMusicMenu() const;

    // Process

    const void playSoundHoverButton();
    const void playSoundClickButton();

    const void allGestion(Key *k);
    const void allDisplay();

    // Display

    const int displayMenu(Key *k);

    // Delete

    const void deleteMusicMenu() const;
    const void unloadMenuTexture();

    // Public Variables

    int _mapSize;
    int _screenWidth;
    int _screenHeight;
};

#endif
