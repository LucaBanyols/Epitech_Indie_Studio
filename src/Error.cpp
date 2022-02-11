/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** arcade
*/

#include "../include/Error.hpp"

Error::Error(std::ostream &os, const std::string &message) throw() : _os(os)
{
    this->_message = message;
}

Error::~Error()
{
}

const char *Error::what() const throw()
{
    return (this->_message.c_str());
}