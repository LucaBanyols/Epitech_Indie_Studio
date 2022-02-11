/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"

#ifndef TEXT_HPP_
#define TEXT_HPP_

class Texts
{
public:
    Texts();
    ~Texts() = default;
    const void setDrawText(const char *text, int x, int y, int size, Color color) const;
    const void setDrawTextGradiant(const char *text, int x, int y, int size, int gradiant) const;
    const char *setSubText(const char *text, int position, int length) const;
};

#endif