/*
** EPITECH PROJECT, 2021
** indie studio
** File description:
** AI
*/

#include "../../include/Game/AI.hpp"

AI::AI()
{
}

void AI::samePosEvent(Player *player, Map map, MoveAI moveAI)
{
    if (player->getPlayerNumber() == 1) {
        if ((floor(player->getPositionX()) == floor(map.getPositionPlayer(2).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(2).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(3).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(3).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(4).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(4).z))) {
            player->setRotationAxis({1.0f, 0.0f, 0.0f});
            player->setRotationAngle(-90.0f);
        }
    } else if (player->getPlayerNumber() == 2) {
        if ((floor(player->getPositionX()) == floor(map.getPositionPlayer(3).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(3).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(4).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(4).z))) {
            player->setRotationAxis({1.0f, 0.0f, 0.0f});
            player->setRotationAngle(-90.0f);
        }
    } else if (player->getPlayerNumber() == 3) {
        if ((floor(player->getPositionX()) == floor(map.getPositionPlayer(4).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(4).z))) {
            player->setRotationAxis({1.0f, 0.0f, 0.0f});
            player->setRotationAngle(-90.0f);
        }
    }
}

void AI::gestionMovesAI(Player *player, Map map)
{
    static bool up1 = true;
    static bool down1 = true;
    static bool left1 = true;
    static bool right1 = true;
    static bool up2 = true;
    static bool down2 = true;
    static bool left2 = true;
    static bool right2 = true;
    static bool up3 = true;
    static bool down3 = true;
    static bool left3 = true;
    static bool right3 = true;
    static bool up4 = true;
    static bool down4 = true;
    static bool left4 = true;
    static bool right4 = true;
    MoveAI moveAI;

    samePosEvent(player, map, moveAI);
    if (player->getPlayerNumber() == 1) {
        moveAI.moveHandling(player, map, up1, down1, left1, right1);
        up1 = moveAI.getUp();
        down1 = moveAI.getDown();
        left1 = moveAI.getLeft();
        right1 = moveAI.getRight();
        if ((floor(player->getPositionX() + 1.0) == floor(map.getPositionPlayer(2).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(2).z))
        || (floor(player->getPositionX() - 1.0) == floor(map.getPositionPlayer(2).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(2).z))
        || (floor(player->getPositionX() == floor(map.getPositionPlayer(2).x) && floor(player->getPositionZ() + 1.0) == floor(map.getPositionPlayer(2).z)))
        || (floor(player->getPositionX() == floor(map.getPositionPlayer(2).x) && floor(player->getPositionZ() - 1.0) == floor(map.getPositionPlayer(2).z)))

        || (floor(player->getPositionX() + 1.0) == floor(map.getPositionPlayer(3).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(3).z))
        || (floor(player->getPositionX() - 1.0) == floor(map.getPositionPlayer(3).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(3).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(3).x) && floor(player->getPositionZ() + 1.0) == floor(map.getPositionPlayer(3).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(3).x) && floor(player->getPositionZ() - 1.0) == floor(map.getPositionPlayer(3).z))

        || (floor(player->getPositionX() + 1.0) == floor(map.getPositionPlayer(4).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(4).z))
        || (floor(player->getPositionX() - 1.0) == floor(map.getPositionPlayer(4).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(4).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(4).x) && floor(player->getPositionZ() + 1.0) == floor(map.getPositionPlayer(4).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(4).x) && floor(player->getPositionZ() - 1.0) == floor(map.getPositionPlayer(4).z))) {
            moveAI.gestionAIBomb(map, map._bombListP1->getBomb1(), map._bombListP1, player);
        }
    } else if (player->getPlayerNumber() == 2) {
        moveAI.moveHandling(player, map, up2, down2, left2, right2);
        up2 = moveAI.getUp();
        down2 = moveAI.getDown();
        left2 = moveAI.getLeft();
        right2 = moveAI.getRight();
        if ((floor(player->getPositionX() + 1.0) == floor(map.getPositionPlayer(1).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(1).z))
        || (floor(player->getPositionX() - 1.0) == floor(map.getPositionPlayer(1).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(1).z))
        || (floor(player->getPositionX() == floor(map.getPositionPlayer(1).x) && floor(player->getPositionZ() + 1.0) == floor(map.getPositionPlayer(1).z)))
        || (floor(player->getPositionX() == floor(map.getPositionPlayer(1).x) && floor(player->getPositionZ() - 1.0) == floor(map.getPositionPlayer(1).z)))

        || (floor(player->getPositionX() + 1.0) == floor(map.getPositionPlayer(3).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(3).z))
        || (floor(player->getPositionX() - 1.0) == floor(map.getPositionPlayer(3).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(3).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(3).x) && floor(player->getPositionZ() + 1.0) == floor(map.getPositionPlayer(3).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(3).x) && floor(player->getPositionZ() - 1.0) == floor(map.getPositionPlayer(3).z))

        || (floor(player->getPositionX() + 1.0) == floor(map.getPositionPlayer(4).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(4).z))
        || (floor(player->getPositionX() - 1.0) == floor(map.getPositionPlayer(4).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(4).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(4).x) && floor(player->getPositionZ() + 1.0) == floor(map.getPositionPlayer(4).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(4).x) && floor(player->getPositionZ() - 1.0) == floor(map.getPositionPlayer(4).z))) {
            moveAI.gestionAIBomb(map, map._bombListP2->getBomb2(), map._bombListP2, player);
        }
    } else if (player->getPlayerNumber() == 3) {
        moveAI.moveHandling(player, map, up3, down3, left3, right3);
        up3 = moveAI.getUp();
        down3 = moveAI.getDown();
        left3 = moveAI.getLeft();
        right3 = moveAI.getRight();
        if ((floor(player->getPositionX() + 1.0) == floor(map.getPositionPlayer(2).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(2).z))
        || (floor(player->getPositionX() - 1.0) == floor(map.getPositionPlayer(2).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(2).z))
        || (floor(player->getPositionX() == floor(map.getPositionPlayer(2).x) && floor(player->getPositionZ() + 1.0) == floor(map.getPositionPlayer(2).z)))
        || (floor(player->getPositionX() == floor(map.getPositionPlayer(2).x) && floor(player->getPositionZ() - 1.0) == floor(map.getPositionPlayer(2).z)))

        || (floor(player->getPositionX() + 1.0) == floor(map.getPositionPlayer(1).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(1).z))
        || (floor(player->getPositionX() - 1.0) == floor(map.getPositionPlayer(1).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(1).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(1).x) && floor(player->getPositionZ() + 1.0) == floor(map.getPositionPlayer(1).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(1).x) && floor(player->getPositionZ() - 1.0) == floor(map.getPositionPlayer(1).z))

        || (floor(player->getPositionX() + 1.0) == floor(map.getPositionPlayer(4).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(4).z))
        || (floor(player->getPositionX() - 1.0) == floor(map.getPositionPlayer(4).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(4).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(4).x) && floor(player->getPositionZ() + 1.0) == floor(map.getPositionPlayer(4).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(4).x) && floor(player->getPositionZ() - 1.0) == floor(map.getPositionPlayer(4).z))) {
            moveAI.gestionAIBomb(map, map._bombListP3->getBomb3(), map._bombListP3, player);
        }
    } else if (player->getPlayerNumber() == 4) {
        moveAI.moveHandling(player, map, up4, down4, left4, right4);
        up4 = moveAI.getUp();
        down4 = moveAI.getDown();
        left4 = moveAI.getLeft();
        right4 = moveAI.getRight();
        if ((floor(player->getPositionX() + 1.0) == floor(map.getPositionPlayer(2).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(2).z))
        || (floor(player->getPositionX() - 1.0) == floor(map.getPositionPlayer(2).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(2).z))
        || (floor(player->getPositionX() == floor(map.getPositionPlayer(2).x) && floor(player->getPositionZ() + 1.0) == floor(map.getPositionPlayer(2).z)))
        || (floor(player->getPositionX() == floor(map.getPositionPlayer(2).x) && floor(player->getPositionZ() - 1.0) == floor(map.getPositionPlayer(2).z)))

        || (floor(player->getPositionX() + 1.0) == floor(map.getPositionPlayer(3).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(3).z))
        || (floor(player->getPositionX() - 1.0) == floor(map.getPositionPlayer(3).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(3).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(3).x) && floor(player->getPositionZ() + 1.0) == floor(map.getPositionPlayer(3).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(3).x) && floor(player->getPositionZ() - 1.0) == floor(map.getPositionPlayer(3).z))

        || (floor(player->getPositionX() + 1.0) == floor(map.getPositionPlayer(1).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(1).z))
        || (floor(player->getPositionX() - 1.0) == floor(map.getPositionPlayer(1).x) && floor(player->getPositionZ()) == floor(map.getPositionPlayer(1).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(1).x) && floor(player->getPositionZ() + 1.0) == floor(map.getPositionPlayer(1).z))
        || (floor(player->getPositionX()) == floor(map.getPositionPlayer(1).x) && floor(player->getPositionZ() - 1.0) == floor(map.getPositionPlayer(1).z))) {
            moveAI.gestionAIBomb(map, map._bombListP4->getBomb4(), map._bombListP4, player);
        }
    }
    if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == BOMB_WITH_PLAYER && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 0.99)] == VIDE)
    {
        map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() + 1.0)] = BOMB;
    }
    if (map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] == BOMB_WITH_PLAYER && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 0.99)] == VIDE)
    {
        map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() + 1.0)] = BOMB;
    }
    if (map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == BOMB_WITH_PLAYER && map._map[int(floor(player->getPositionX()))][int(player->getPositionZ())] == VIDE)
    {
        map._map[int(floor(player->getPositionX()))][int(player->getPositionZ() - 0.001)] = BOMB;
    }
    if (map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] == BOMB_WITH_PLAYER && map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ())] == VIDE)
    {
        map._map[int(ceil(player->getPositionX()))][int(player->getPositionZ() - 0.001)] = BOMB;
    }
    if (map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] == BOMB_WITH_PLAYER && map._map[int(player->getPositionX() + 0.99)][int(floor(player->getPositionZ()))] == VIDE)
    {
        map._map[int(player->getPositionX() + 1.0)][int(floor(player->getPositionZ()))] = BOMB;
    }
    if (map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] == BOMB_WITH_PLAYER && map._map[int(player->getPositionX() + 0.99)][int(ceil(player->getPositionZ()))] == VIDE)
    {
        map._map[int(player->getPositionX() + 1.0)][int(ceil(player->getPositionZ()))] = BOMB;
    }

    if (map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] == BOMB_WITH_PLAYER && map._map[int(player->getPositionX())][int(floor(player->getPositionZ()))] == VIDE)
    {
        map._map[int(player->getPositionX() - 0.001)][int(floor(player->getPositionZ()))] = BOMB;
    }
    if (map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] == BOMB_WITH_PLAYER && map._map[int(player->getPositionX())][int(ceil(player->getPositionZ()))] == VIDE)
    {
        map._map[int(player->getPositionX() - 0.001)][int(ceil(player->getPositionZ()))] = BOMB;
    }

    if (map._map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] == BONUS_BOM_SUP)
    {
        player->addBomb();
        map._map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] = VIDE;
    }
    if (map._map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] == BONUS_RANGE_SUP)
    {
        //player->addBombRange();
        map._map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] = VIDE;
    }
    if (map._map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] == BONUS_SPEED_SUP)
    {
        player->addSpeed();
        map._map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] = VIDE;
    }
    if (map._map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] == BONUS_EXPLOSION_TRAVERS)
    {
        player->addThroughWall();
        map._map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] = VIDE;
    }
    if (map._map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] == BONUS_WALL_PASS)
    {
        player->addWallPass();
        map._map[int(floor(player->getPositionX() + 0.5))][int(floor(player->getPositionZ() + 0.5))] = VIDE;
    }
    player->fixCoords();
}