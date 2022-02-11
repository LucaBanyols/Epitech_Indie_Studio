/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "Textures.hpp"
#include "Window.hpp"
#include "Mouse.hpp"
#include "Sound.hpp"
#include "Image.hpp"
#include "Model.hpp"
#include "KeyEvent.hpp"
#include "Camera.hpp"
#include "Text.hpp"
#include "Music.hpp"
#include "Controller.hpp"

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

class IComponent
{
public:
    IComponent(){};
    virtual ~IComponent()
    {
        delete (this->_window);
        delete (this->_sound);
        delete (this->_texture);
        delete (this->_cameras);
        delete (this->_keyEvent);
        delete (this->_mouse);
        delete (this->_musics);
        delete (this->_texts);
    };
    Textures *_texture = new Textures;
    Windows *_window = new Windows;
    Sounds *_sound = new Sounds;
    Cameras *_cameras = new Cameras;
    KeyEvent *_keyEvent = new KeyEvent;
    Images *_images = new Images;
    Mouse *_mouse = new Mouse;
    Musics *_musics = new Musics;
    Texts *_texts = new Texts;
    Controller *_controller = new Controller;
};

#endif