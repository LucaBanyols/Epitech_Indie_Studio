/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-dylan1.faure
** File description:
** Controller
*/

#include "../ICore.hpp"

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

class Controller {
    public:
        Controller();
        ~Controller();
        const float GetControllerAxisMovement(int gamepad, int axis) const;
        const int GetControllerButtonPressed() const;
        const bool IsControllerAvailable(int gamepad) const;
        const bool IsControllerName(int gamepad, const char *name) const;
        const int GetControllerAxisCount(int gamepad) const;
    protected:
    private:

};

#endif /* !CONTROLLER_HPP_ */
