/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Component/Text.hpp"

Texts::Texts()
{
}

const void Texts::setDrawText(const char *text, int x, int y, int size, Color color) const
{
    return (DrawText(text, x, y, size, color));
}

const void Texts::setDrawTextGradiant(const char *text, int x, int y, int size, int gradiant) const
{
    Color color;

    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = static_cast<unsigned char>(gradiant);
    return (DrawText(text, x, y, size, CLITERAL(color)));
}

const char *Texts::setSubText(const char *text, int position, int length) const
{
    return (TextSubtext(text, position, length));
}