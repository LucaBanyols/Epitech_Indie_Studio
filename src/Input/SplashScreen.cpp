/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../../include/Input/SplashScreen.hpp"

SplashScreen::SplashScreen()
{
    this->_start = false;
    this->_tmp1 = false;
    this->_tmp2 = false;
    this->_tmp3 = false;
    this->_tmp4 = false;
    this->_x1 = 0;
    this->_x2 = 0;
    this->_x3 = 0;
    this->_y = 0;
    this->_gradiant = 0;
    this->_gradiant2 = 0;
    this->_next = 0;
    this->_y2 = 0.0;
}

const void SplashScreen::setSplashScreen()
{
    try
    {
        this->_logoSplashScreen = this->_texture->getTexture2D("../src/resources/assets/logo_splashscreen.png");
        this->_logoRaylib = this->_texture->getTexture2D("../src/resources/assets/logo_raylib.png");
        this->_parallaxBackground1 = this->_texture->getTexture2D("../src/resources/assets/parallax_1.png");
        this->_parallaxBackground2 = this->_texture->getTexture2D("../src/resources/assets/parallax_2.png");
        this->_parallaxBackground3 = this->_texture->getTexture2D("../src/resources/assets/parallax_3.png");
        this->_musicSplashScreen = this->_musics->getMusicStream("../src/resources/sounds/splashscreen.ogg");
    }
    catch (Texture2D)
    {
        this->_logoSplashScreen = this->_texture->getTexture2D("../../src/resources/assets/logo_splashscreen.png");
        this->_logoRaylib = this->_texture->getTexture2D("../../src/resources/assets/logo_raylib.png");
        this->_parallaxBackground1 = this->_texture->getTexture2D("../../src/resources/assets/parallax_1.png");
        this->_parallaxBackground2 = this->_texture->getTexture2D("../../src/resources/assets/parallax_2.png");
        this->_parallaxBackground3 = this->_texture->getTexture2D("../../src/resources/assets/parallax_3.png");
        this->_musicSplashScreen = this->_musics->getMusicStream("../../src/resources/sounds/splashscreen.ogg");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
    this->_musics->setPlayStream(this->_musicSplashScreen);
}

const void SplashScreen::gestionSplashScreen()
{
    this->_x1 -= 0.2f;
    this->_x2 -= 0.7f;
    this->_x3 -= 1.2f;

    this->_musics->setUpdateMusicStream(this->_musicSplashScreen);
    if (this->_x1 >= this->_parallaxBackground1.width * 2)
        this->_x1 = 0;
    if (this->_x2 >= this->_parallaxBackground2.width * 2)
        this->_x2 = 0;
    if (this->_x3 >= this->_parallaxBackground3.width * 2)
        this->_x3 = 0;
    if (this->_y <= (this->_window->getScreenHeight() / 2 - this->_logoSplashScreen.height / 2))
    {
        this->_y++;
    }
    if (this->_keyEvent->getIsKeyPressed(KEY_ENTER))
    {
        this->_start = true;
    }
}

const void SplashScreen::displayLogoRaylib()
{
    if (this->_keyEvent->getIsKeyPressed(KEY_ENTER))
    {
        this->_tmp1 = true;
    }
    if (this->_tmp1 == false && this->_gradiant <= 300)
    {
        this->_gradiant += 2;
        if (this->_gradiant >= 100)
        {
            this->_tmp1 = true;
        }
    }
    if (this->_tmp2 == false && this->_gradiant >= 0)
    {
        this->_gradiant--;
    }
    if (this->_gradiant >= 0 && this->_gradiant <= 100)
    {
        this->_texture->setDrawTextureGradiant(this->_logoRaylib, this->_window->getScreenWidth() / 2 - this->_logoRaylib.width / 2, this->_window->getScreenHeight() / 3 - this->_logoRaylib.height, this->_gradiant);
    }
    else
    {
        this->_next = 1;
    }
}

const void SplashScreen::displayMembers()
{
    if (this->_keyEvent->getIsKeyPressed(KEY_ENTER))
    {
        this->_tmp3 = true;
    }
    if (this->_tmp3 == false && this->_gradiant2 <= 300)
    {
        this->_gradiant2 += 2;
        if (this->_gradiant2 >= 100)
        {
            this->_tmp3 = true;
        }
    }
    if (this->_tmp4 == false && this->_gradiant2 >= 0)
    {
        this->_gradiant2--;
    }
    if (this->_gradiant2 >= 0 && this->_gradiant2 <= 100)
    {
        this->_y2 += 2.5;
        this->_texts->setDrawTextGradiant("AUTHORS", this->_window->getScreenWidth() / 2 - 150, 150 + this->_y2, 50, this->_gradiant2);
        this->_texts->setDrawTextGradiant("Gameplay", 260, 600 - this->_y2, 60,  this->_gradiant2);
        this->_texts->setDrawTextGradiant("Interface", 1200, 600 - this->_y2, 60, this->_gradiant2);
        this->_texts->setDrawTextGradiant("Luca Banyols (Bomb, IA)", 200, 700 - this->_y2, 37, this->_gradiant2);
        this->_texts->setDrawTextGradiant("Dylan Faure (Player, Map)", 200, 780 - this->_y2, 37, this->_gradiant2);
        this->_texts->setDrawTextGradiant("Zyad El Idrissi (Gamepad, SFX)", 200, 860 - this->_y2, 37, this->_gradiant2);
        this->_texts->setDrawTextGradiant("Vincent Pichot (Animation)", 200, 940 - this->_y2, 37, this->_gradiant2);
        this->_texts->setDrawTextGradiant("Austin-William Lo", 1250 - 50, 700 - this->_y2, 37, this->_gradiant2);
    }
    else
    {
        this->_next == 2;
    }
}

const void SplashScreen::displayLogoBouncing()
{
    int tmp = 0;
    bool bouncing = true;

    if (this->_y <= 200 && tmp == 0)
    {
        this->_y += 10;
        if (tmp >= 200)
            tmp = 1;
    }
    else
    {
        this->_y--;
    }
    this->_texture->setDrawTexture(this->_logoSplashScreen, this->_window->getScreenWidth() / 2 - this->_logoSplashScreen.width / 2, this->_y);
}

const int SplashScreen::displaySplashScreen()
{
    int frame = 0;

    this->_keyEvent->setQuitKey(0);
    setSplashScreen();
    while (!(this->_window->getStatusWindow()))
    {
        if (this->_start == true)
        {
            return (1);
            break;
        }
        this->_texture->setBeginDrawing();
        this->_window->setClearBackground();
        if (this->_next == 0)
        {
            displayLogoRaylib();
        }
        if (this->_next == 1)
        {
            displayMembers();
        }
        if (this->_next == 1 && this->_gradiant2 <= 0)
        {
            gestionSplashScreen();
            this->_texture->setDrawTexture(this->_parallaxBackground1, this->_x1, 0);
            this->_texture->setDrawTexture(this->_parallaxBackground2, this->_x2, 0);
            this->_texture->setDrawTexture(this->_parallaxBackground3, this->_x3, 0);
            displayLogoBouncing();
            frame += 2;
            if (frame >= 100)
                frame = 0;
            if ((frame / 10 % 2) == 0)
                this->_texts->setDrawText("Press enter", this->_window->getScreenHeight() / 2 - 200, 800, 60, WHITE);
        }
        this->_texture->setEndDrawing();
    }
    deleteSplashScreen();
    return (0);
}

const void SplashScreen::deleteSplashScreen() const
{
    this->_texture->setUnloadTexture(this->_logoSplashScreen);
    this->_texture->setUnloadTexture(this->_parallaxBackground1);
    this->_texture->setUnloadTexture(this->_parallaxBackground2);
    this->_texture->setUnloadTexture(this->_parallaxBackground3);
    this->_texture->setUnloadTexture(this->_logoRaylib);
    this->_musics->deleteMusicStream(this->_musicSplashScreen);
}