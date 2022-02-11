/*
** EPITECH PROJECT, 2021
** ThroughWall.hpp
** File description:
** ThroughWall.hpp
*/

#include "../ICore.hpp"

#ifndef THROUGHWALL_HPP_
#define THROUGHWALL_HPP_

class ThroughWall
{
private:
    int _ThroughWall;
public:
    ThroughWall();
    ~ThroughWall();
    void addThroughWall();
    const int getThroughWall();
};

#endif