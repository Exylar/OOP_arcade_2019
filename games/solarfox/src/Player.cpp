/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Player.cpp
*/

#include "Player.hpp"

void Player::draw(IDisplayModule &win) const {
    win.setColor(IDisplayModule::Colors::LIGHT_BLUE);
    switch (_dir) {
        case Direction::LEFT:
            win.putFillRect(_x - 8, _y, 8, 32);
            break;
        case Direction::RIGHT:
            win.putFillRect(_x + 32, _y, 8, 32);
            break;
        case Direction::UP:
            win.putFillRect(_x, _y - 8, 32, 16);
            break;
        case Direction::DOWN:
            win.putFillRect(_x, _y + 24, 32, 16);
            break;
        default: break;
    }
    win.setColor(IDisplayModule::Colors::WHITE);
    win.putFillRect(_x, _y, 32, 32);
}

void Player::update( const IDisplayModule &win) {
    if (win.isKeyPressed(IDisplayModule::Keys::UP) || win.isKeyPressed(IDisplayModule::Keys::Z))
        _dir = Direction::UP;
    if (win.isKeyPressed(IDisplayModule::Keys::DOWN) || win.isKeyPressed(IDisplayModule::Keys::S))
        _dir = Direction::DOWN;
    if (win.isKeyPressed(IDisplayModule::Keys::LEFT) || win.isKeyPressed(IDisplayModule::Keys::Q))
        _dir = Direction::LEFT;
    if (win.isKeyPressed(IDisplayModule::Keys::RIGHT) || win.isKeyPressed(IDisplayModule::Keys::D))
        _dir = Direction::RIGHT;
    move();
}

