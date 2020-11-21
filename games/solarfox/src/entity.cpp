/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** entity.cpp
*/

#include "Entity.hpp"

void Entity::move() {
    switch (_dir) {
        case Direction::UP: _y -= _v; break;
        case Direction::DOWN: _y += _v; break;
        case Direction::LEFT: _x -= _v; break;
        case Direction::RIGHT: _x += _v; break;
        default: break;
    }
}

bool Entity::isCollide(const Entity &other) const {
    if (other.getX() >= getX() + getWidth() ||
        other.getX() + other.getWidth() <= getX() ||
        other.getY() >= getY() + getHeight() ||
        other.getY() + other.getHeight() <= getY())
        return (false);
    return (true);
}