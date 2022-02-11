/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

class Cameras
{
public:
    Cameras();
    ~Cameras() = default;
    const void setCameraAllMode(Camera3D camera, int mode) const;
    const void setUpdateCamera(Camera *camera) const;
    const void setBeginMode3D(Camera3D camera) const;
    const void setEndMode3D() const;
};

#endif