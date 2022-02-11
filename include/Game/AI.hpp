/*
** EPITECH PROJECT, 2(right021
** indie studio
** File description:
** AI hpp
*/

#include "MoveAI.hpp"

#ifndef AI_HPP_
#define AI_HPP_

class AI
{
public:
    AI();
    ~AI() = default;
    void samePosEvent(Player *player, Map map, MoveAI moveAI);
    void gestionMovesAI(Player *player, Map map);
};

#endif