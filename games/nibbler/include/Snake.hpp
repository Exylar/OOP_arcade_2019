/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake.hpp
*/

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include <iostream>
#include "IDisplayModule.hpp"

#define WIDTH_MAP 15
#define HEIGHT_MAP 13

class Snake {
    public:
        enum Direction {
            UP,
            DOWN,
            RIGHT,
            LEFT,
            STOP,
            END,
        };

        Snake();
        ~Snake();
        void reset();
        void update(const IDisplayModule &lib);
        void render(IDisplayModule &lib);
        int getCurrentDirection() const;
        int getScore() const;
    private:
        float _lastDelta;
        void moveHead();
        void moveTail();
        void isEats();
        void setFood();
        void keyPressed(const IDisplayModule &lib);
        void resetBodyValues(int inc);
        void checkNextHead();

        size_t _size;
        int _lastValue;
        std::vector<std::vector<int>> _map;
        std::vector<int> _head;
        std::vector<int> _tail;
        std::vector<std::vector<int>> _food;
        Direction _currentDirection;
        bool KeyPressed = false;
};

#endif