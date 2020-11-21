/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** main.cpp
*/

#include <fstream>
#include <iostream>
#include "CoreModule.hpp"
#include "Error.hpp"

void check_extension(std::string const &libraryPath) {
    std::string extension;
    std::string path(libraryPath);

    if (!(std::ifstream(libraryPath)))
        throw ParameterError(libraryPath + ": file not found.");
    extension = path.substr(path.find_last_of("."), 3);
    if (extension != ".so")
        throw ParameterError(libraryPath + ": wrong extension file.");
}

int arcade(std::string const libraryPath) {
    try {
        CoreModule core(libraryPath);
        core.loop();
    } catch (ParameterError &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}

int main(int argc, char **argv) {
    srand(time(NULL));

    if (argc != 2) {
        std::cerr << "Please add library in parameter!" << std::endl;
        return 84;
    }
    try {
        check_extension(argv[1]);
    } catch (ParameterError &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    try {
        return arcade(argv[1]);
    } catch (LibraryError &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}