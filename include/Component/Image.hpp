/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"

#ifndef IMAGE_HPP_
#define IMAGE_HPP_

class Images
{
private:
    /* data */
public:
    Images();
    ~Images() = default;
    const Image getImage(const char *path) const;
    const void deleteImage(Image image) const;
};

#endif