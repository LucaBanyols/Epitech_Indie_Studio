/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Game/Pause.hpp"

Pause::Pause()
{
    this->_buttonResumeState = 0;
    this->_btnResumeAction = false;

    this->_buttonRestartState = 0;
    this->_btnRestartAction = false;

    this->_buttonSaveState = 0;
    this->_btnSaveAction = false;

    this->_buttonQuitState = 0;
    this->_btnQuitAction = false;

    this->_mousePoint = {0.0f, 0.0f};
}

// Setter

const void Pause::setPause()
{
    setResume();
    setRestart();
    setSave();
    setQuit();
    setBackground();
}

const void Pause::setResume()
{
    try
    {
        this->_textureResume = this->_texture->getTexture2D("../src/resources/assets/resume.png");
    }
    catch (Texture2D)
    {
        this->_textureResume = this->_texture->getTexture2D("../../src/resources/assets/resume.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
    // this->_sound->setSoundButton();
    this->_frameResumeHeight = (float)this->_textureResume.height / 2;
    this->_sourceResumeRec = {0, 0, (float)this->_textureResume.width, this->_frameResumeHeight};
    this->_btnResumeBounds = {1920 / 2.0f - this->_textureResume.width / 2, 1080 / 2.0f - this->_textureResume.height, (float)this->_textureResume.width, this->_frameResumeHeight};
}

const void Pause::setRestart()
{
    try
    {
        this->_textureRestart = this->_texture->getTexture2D("../src/resources/assets/restart.png");
    }
    catch (Texture2D)
    {
        this->_textureRestart = this->_texture->getTexture2D("../../src/resources/assets/restart.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
    // this->_sound->setSoundButton();
    this->_frameRestartHeight = (float)this->_textureRestart.height / 2;
    this->_sourceRestartRec = {0, 0, (float)this->_textureRestart.width, this->_frameRestartHeight};
    this->_btnRestartBounds = {1920 / 2.0f - this->_textureRestart.width / 2, 550, (float)this->_textureRestart.width, this->_frameRestartHeight};
}

const void Pause::setSave()
{
    try
    {
        this->_textureSave = this->_texture->getTexture2D("../src/resources/assets/save.png");
    }
    catch (Texture2D)
    {
        this->_textureSave = this->_texture->getTexture2D("../../src/resources/assets/save.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
    // this->_sound->setSoundButton();
    this->_frameSaveHeight = (float)this->_textureSave.height / 2;
    this->_sourceSaveRec = {0, 0, (float)this->_textureSave.width, this->_frameSaveHeight};
    this->_btnSaveBounds = {1920 / 3.0f - this->_textureSave.width, 650, (float)this->_textureSave.width, this->_frameSaveHeight};
}

const void Pause::setQuit()
{
    try
    {
        this->_textureQuit = this->_texture->getTexture2D("../src/resources/assets/exit.png");
    }
    catch (Texture2D)
    {
        this->_textureQuit = this->_texture->getTexture2D("../../src/resources/assets/exit.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
    // this->_sound->setSoundButton();
    this->_frameQuitHeight = (float)this->_textureQuit.height / 2;
    this->_sourceQuitRec = {0, 0, (float)this->_textureQuit.width, this->_frameQuitHeight};
    this->_btnQuitBounds = {1920 / 2.0f - this->_textureQuit.width / 2, 750, (float)this->_textureQuit.width, this->_frameQuitHeight};
}

const void Pause::setBackground()
{
    try
    {
        this->_pauseBackground = this->_texture->getTexture2D("../src/resources/assets/background_pause.png");
    }
    catch (Texture2D)
    {
        this->_pauseBackground = this->_texture->getTexture2D("../../src/resources/assets/background_pause.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
}

// Gestion

const void Pause::gestionPause()
{
    gestionResume();
    gestionRestart();
    gestionSave();
    gestionQuit();
}

const void Pause::gestionResume()
{
    if (this->_mouse->getCollisionPointRec(this->_mousePoint, this->_btnResumeBounds))
    {
        if (this->_mouse->getClickPressed(MOUSE_LEFT_BUTTON))
        {
            this->_buttonResumeState = 2;
            this->_sound->playSoundClickButton();
        }
        else
            this->_buttonResumeState = 1;
        if (this->_mouse->getClickReleased(MOUSE_LEFT_BUTTON))
        {
            this->_btnResumeAction = !this->_btnResumeAction;
        }
    }
    else
        this->_buttonResumeState = 0;
    this->_sourceResumeRec.y = this->_buttonResumeState * this->_frameResumeHeight;
}

const void Pause::gestionRestart()
{
    if (this->_mouse->getCollisionPointRec(this->_mousePoint, this->_btnRestartBounds))
    {
        if (this->_mouse->getClickPressed(MOUSE_LEFT_BUTTON))
        {
            this->_buttonRestartState = 2;
            this->_sound->playSoundClickButton();
        }
        else
            this->_buttonRestartState = 1;
        if (this->_mouse->getClickReleased(MOUSE_LEFT_BUTTON))
        {
            this->_btnRestartAction = true;
        }
    }
    else
        this->_buttonRestartState = 0;
    this->_sourceRestartRec.y = this->_buttonRestartState * this->_frameRestartHeight;
}

const void Pause::gestionSave()
{
    if (this->_mouse->getCollisionPointRec(this->_mousePoint, this->_btnSaveBounds))
    {
        if (this->_mouse->getClickPressed(MOUSE_LEFT_BUTTON))
        {
            this->_buttonSaveState = 2;
            this->_sound->playSoundClickButton();
        }
        else
            this->_buttonSaveState = 1;
        if (this->_mouse->getClickReleased(MOUSE_LEFT_BUTTON))
        {
            this->_btnSaveAction = true;
        }
    }
    else
        this->_buttonSaveState = 0;
    this->_sourceSaveRec.y = this->_buttonSaveState * this->_frameSaveHeight;
}

const void Pause::gestionQuit()
{
    if (this->_mouse->getCollisionPointRec(this->_mousePoint, this->_btnQuitBounds))
    {
        if (this->_mouse->getClickPressed(MOUSE_LEFT_BUTTON))
        {
            this->_buttonQuitState = 2;
            this->_sound->playSoundClickButton();
        }
        else
            this->_buttonQuitState = 1;
        if (this->_mouse->getClickReleased(MOUSE_LEFT_BUTTON))
        {
            this->_btnQuitAction = true;
        }
    }
    else
        this->_buttonQuitState = 0;
    this->_sourceQuitRec.y = this->_buttonQuitState * this->_frameQuitHeight;
}

const void Pause::gestionDisplayPause()
{
    if (this->_keyEvent->getIsKeyPressed(KEY_ESCAPE))
    {
        this->_btnResumeAction = !this->_btnResumeAction;
    }
}

// Display

const void Pause::displayResume() const
{
    this->_texture->setDrawTextureRec(this->_textureResume, this->_sourceResumeRec, this->_btnResumeBounds.x, this->_btnResumeBounds.y);
}

const void Pause::displayRestart() const
{
    this->_texture->setDrawTextureRec(this->_textureRestart, this->_sourceRestartRec, this->_btnRestartBounds.x, this->_btnRestartBounds.y);
}

const void Pause::displaySave() const
{
    this->_texture->setDrawTextureRec(this->_textureSave, this->_sourceSaveRec, this->_btnSaveBounds.x, this->_btnSaveBounds.y);
}

const void Pause::displayQuit() const
{
    this->_texture->setDrawTextureRec(this->_textureQuit, this->_sourceQuitRec, this->_btnQuitBounds.x, this->_btnQuitBounds.y);
}

const void Pause::displayPause()
{
    bool displayStatusSaveText = false;

    this->_sound->setSoundButton();
    while (!this->_window->getStatusWindow())
    {
        this->_mousePoint = this->_mouse->getMousePos();
        gestionDisplayPause();
        gestionPause();
        if (this->_btnResumeAction == true)
            break;
        else if (this->_btnRestartAction == true)
        {
            break;
        }
        else if (this->_btnSaveAction == true)
        {
            this->_texts->setDrawText("Saved", 1920 / 2 - 60, 1000, 40, WHITE);
        }
        if (this->_btnQuitAction == true)
        {
            deletePause();
            break;
        }
        this->_texture->setBeginDrawing();
        this->_window->setClearBackground();
        this->_texts->setDrawText("PAUSE", 1920 / 2 - 140, 175, 80, WHITE);
        this->_texture->setDrawTexture(this->_pauseBackground, 0, 0);
        displayResume();
        displayRestart();
        displaySave();
        displayQuit();
        this->_texture->setEndDrawing();
    }
    this->_sound->deleteSoundButton();
}

// Delete

const void Pause::deletePause() const
{
    deleteResume();
    deleteRestart();
    deleteSave();
    deleteQuit();
    this->_texture->setUnloadTexture(this->_pauseBackground);
}

const void Pause::deleteResume() const
{
    this->_texture->setUnloadTexture(this->_textureResume);
    // this->_sound->deleteSoundButton();
}

const void Pause::deleteRestart() const
{
    this->_texture->setUnloadTexture(this->_textureRestart);
    // this->_sound->deleteSoundButton();
}

const void Pause::deleteSave() const
{
    this->_texture->setUnloadTexture(this->_textureSave);
    // this->_sound->deleteSoundButton();
}

const void Pause::deleteQuit() const
{
    this->_texture->setUnloadTexture(this->_textureQuit);
    // this->_sound->deleteSoundButton();
}