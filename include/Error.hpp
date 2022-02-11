/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include <exception>
#include <string>
#include <iostream>

#ifndef ERROR_HPP_
#define ERROR_HPP_

class Error : std::exception
{
private:
    std::string _message;
    std::ostream &_os;

public:
    Error(std::ostream &os, const std::string &message) throw();
    virtual ~Error() throw();
    const char *what() const throw();
};

#endif