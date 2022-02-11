/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Component/Camera.hpp"

Cameras::Cameras()
{
}

const void Cameras::setBeginMode3D(Camera3D camera) const
{
    BeginMode3D(camera);
}

const void Cameras::setCameraAllMode(Camera3D camera, int mode) const
{
    SetCameraMode(camera, mode);
}

const void Cameras::setEndMode3D() const
{
    EndMode3D();
}

const void Cameras::setUpdateCamera(Camera *camera) const
{
    UpdateCamera(camera);
}