/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main.cpp
*/

#include "../include/Error.hpp"
#include "../include/Game/Game.hpp"
#include "raylib.h"

#ifdef _MSC_VER
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main(void)
{
    Game *g = new Game;

    try
    {
        g->startGame();
    }
    catch (const Error &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete (g);
    return (0);
}
