/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../Component/IComponent.hpp"

#ifndef SPLASHSCREEN_HPP_
#define SPLASHSCREEN_HPP_

class SplashScreen : IComponent
{
private:
    bool _start;
    float _x1;
    float _x2;
    float _x3;
    float _y;
    bool _tmp1;
    bool _tmp2;
    bool _tmp3;
    bool _tmp4;
    int _gradiant;
    int _gradiant2;
    int _next;
    float _y2;
    Texture2D _logoRaylib;
    Texture2D _logoSplashScreen;
    Texture2D _parallaxBackground1;
    Texture2D _parallaxBackground2;
    Texture2D _parallaxBackground3;
    Music _musicSplashScreen;

public:
    SplashScreen();
    ~SplashScreen() = default;
    const void setSplashScreen();
    const void gestionSplashScreen();
    const void displayLogoRaylib();
    const void displayMembers();
    const void displayLogoBouncing();
    const int displaySplashScreen();
    const void deleteSplashScreen() const;
};

#endif