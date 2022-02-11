/*
** EPITECH PROJECT2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"

#ifndef BORDER_HPP_
#define BORDER_HPP_

class Border : IComponent
{
public:
    Border();
    ~Border();
    const void setBorder();
    const int gestionBorder(int nb, int x, const bool actionArrowLeft, const bool actionArrowRight);
    const void displayBorder(const int x, const int y) const;
    const void deleteBorder() const;

    Texture2D _textureBorder;
};

#endif