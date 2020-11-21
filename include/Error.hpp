/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Error
*/

#ifndef OOP_ARCADE_2019_ERRORS_HPP
#define OOP_ARCADE_2019_ERRORS_HPP

#include <string>
#include <exception>

class Error : public std::exception {
    public:
        Error(std::string const &message);
        const char *what() const noexcept;
    private:
        std::string _message = "Message";
};

class ParameterError : public Error {
    public:
        ParameterError(std::string const &message);
};

class LibraryError : public Error {
    public:
        LibraryError(std::string const &message);
};

class GameError : public Error {
    public:
        GameError(std::string const &message);
};

#endif //OOP_ARCADE_2019_ERRORS_HPP
