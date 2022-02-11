/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"

#ifndef PAUSE_HPP_
#define PAUSE_HPP_

class Pause : IComponent
{
public:
    Pause();
    ~Pause() = default;

    Vector2 _mousePoint;

    Texture2D _pauseBackground;

    Texture2D _textureResume;
    Rectangle _sourceResumeRec;
    Rectangle _btnResumeBounds;
    bool _btnResumeAction;
    float _frameResumeHeight;
    int _buttonResumeState;

    Texture2D _textureRestart;
    Rectangle _sourceRestartRec;
    Rectangle _btnRestartBounds;
    bool _btnRestartAction;
    float _frameRestartHeight;
    int _buttonRestartState;

    Texture2D _textureSave;
    Rectangle _sourceSaveRec;
    Rectangle _btnSaveBounds;
    bool _btnSaveAction;
    float _frameSaveHeight;
    int _buttonSaveState;

    Texture2D _textureQuit;
    Rectangle _sourceQuitRec;
    Rectangle _btnQuitBounds;
    bool _btnQuitAction;
    float _frameQuitHeight;
    int _buttonQuitState;

    const void setPause();
    const void setResume();
    const void setRestart();
    const void setSave();
    const void setQuit();
    const void setBackground();

    const void gestionDisplayPause();
    const void gestionPause();
    const void gestionResume();
    const void gestionRestart();
    const void gestionSave();
    const void gestionQuit();
    const void createSave();

    const void displayPause();
    const void displayResume() const;
    const void displayRestart() const;
    const void displaySave() const;
    const void displayQuit() const;

    const void deletePause() const;
    const void deleteResume() const;
    const void deleteRestart() const;
    const void deleteSave() const;
    const void deleteQuit() const;
};

#endif