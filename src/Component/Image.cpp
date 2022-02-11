/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Component/Image.hpp"

Images::Images()
{
}

const Image Images::getImage(const char *path) const
{
    return (LoadImage(path));
}

const void Images::deleteImage(Image image) const
{
    return (UnloadImage(image));
}