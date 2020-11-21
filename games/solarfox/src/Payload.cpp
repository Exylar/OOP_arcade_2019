/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Payload.cpp
*/

#include "Payload.hpp"

void Payload::draw(IDisplayModule &lib) const {
    if (!_claimed) {
        lib.setColor(IDisplayModule::Colors::CYAN);
        lib.putFillRect(_x, _y, _width, _height);
    }
}