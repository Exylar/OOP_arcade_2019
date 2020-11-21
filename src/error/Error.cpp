/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(std::string const &message)
{
    this->_message = message;
}

const char* Error::what() const noexcept
{
    return _message.c_str();
}

ParameterError::ParameterError(const std::string &message) : Error(message) {}

LibraryError::LibraryError(const std::string &message) : Error(message) {}

GameError::GameError(const std::string &message) : Error(message) {}