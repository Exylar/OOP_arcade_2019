/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** shoot.cpp
*/

#include "shoot.hpp"

void Shoot::update(const IDisplayModule &win) {
    if (isAlive())
        move();
}

void Shoot::draw(IDisplayModule &win) const {
    if (isAlive()) {
        win.setColor(IDisplayModule::Colors::LIGHT_RED);
        win.putFillRect(_x, _y, 8, 16);
    }
}