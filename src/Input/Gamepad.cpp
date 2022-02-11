/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-dylan1.faure
** File description:
** Gamepad
*/

#include "Gamepad.hpp"
#define XBOX360_LEGACY_NAME_ID  "Xbox Controller"
#if defined(PLATFORM_RPI)
    #define XBOX360_NAME_ID     "Microsoft X-Box 360 pad"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#else
    #define XBOX360_NAME_ID     "Xbox 360 Controller"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#endif

Gamepad::Gamepad()
{
}

Gamepad::~Gamepad()
{
}

const void Gamepad::setGamepad()
{
    if (IsGamepadAvailable(0)) {
        if (IsGamepadName(0, XBOX360_NAME_ID) || IsGamepadName(0, XBOX360_LEGACY_NAME_ID)) {
            std::cout << "xbox controller detected" << std::endl;
        }
        else if (IsGamepadName(0, PS3_NAME_ID))
        {
            std::cout << "ps3 controller detected" << std::endl;
        }
        else {
            std::cout << "generic controller detected" << std::endl;
        }
        std::cout << "DETECTED AXIS [" << GetGamepadAxisCount(0) << "]" << std::endl;
        for (int i = 0; i < GetGamepadAxisCount(0); i++)
        {
            //std::cout << "AXIS %i: %.02f", i, GetGamepadAxisMovement(0, i)), 20, 70 + 20*i, 10, DARKGRAY);
            std::cout << "AXIS " << i << ": " << GetGamepadAxisMovement(0,i) << std::endl;
        }
        if (GetGamepadButtonPressed() != -1) {
            std::cout << "DETECTED BUTTON: " << GetGamepadButtonPressed() << std::endl;
        } 
    }
    else {
        std::cout << "GP1: NOT DETECTED" << std::endl;
    }
            
}