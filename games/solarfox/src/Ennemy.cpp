/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Ennemy.cpp
*/

#include "Ennemy.hpp"

void Ennemy::draw(IDisplayModule &lib) const {
    if (isAlive()) {
        IDisplayModule::Colors color = _lives == 3 ? IDisplayModule::Colors::GREEN :
                                       _lives == 2 ? IDisplayModule::Colors::YELLOW :
                                       _lives == 1 ? IDisplayModule::Colors::RED :
                                       IDisplayModule::Colors::BLACK;
        lib.setColor(color);
        lib.putFillRect(_x, _y, 16, 16);
    }
}

void Ennemy::update() {
    if (isAlive()) {
        if (getX() >= 640) {
            setX(639);
            setDirection(Entity::Direction::LEFT);
        }
        if (getX() < 0) {
            setX(1);
            setDirection(Entity::Direction::RIGHT);
        }
        if (getY() >= 560) {
            setY(559);
            setDirection(Entity::Direction::UP);
        }
        if (getY() < 0) {
            setY(1);
            setDirection(Entity::Direction::DOWN);
        }
        move();
        _counter--;
    }
}