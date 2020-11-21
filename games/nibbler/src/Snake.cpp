/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake.cpp
*/

#include "Snake.hpp"

Snake::Snake() {
    for (size_t i = 0; i < HEIGHT_MAP + 2; i++) {
        if (i == 0 || i == HEIGHT_MAP + 1)
            _map.push_back({-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1});
        else
            _map.push_back({-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1});
    }
    _food.push_back({8, 14});
}

Snake::~Snake() {}

void Snake::reset() {
    for (size_t i = 1; i < HEIGHT_MAP + 1; i++) {
        for (size_t j = 1; j < WIDTH_MAP + 1; j++) {
            _map[i][j] = 0;
        }
    }
    for (size_t top = 0; top < WIDTH_MAP + 2; top++)
        _map[0][top] = -1;
    for (size_t bottom = 0; bottom < WIDTH_MAP + 2; bottom++)
        _map[14][bottom] = -1;
    for (size_t left = 0; left < HEIGHT_MAP + 2; left++)
        _map[left][0] = -1;
    for (size_t right = 0; right < HEIGHT_MAP + 2; right++)
        _map[right][16] = -1;
    _map[8][4] = 1;
    _map[8][3] = 2;
    _map[8][2] = 3;
    _head = {8, 4};
    _tail = {8, 2};
    _size = 3;
    _food[0][1] = 12;
    _food[0][0] = 8;
    _map[_food[0][0]][_food[0][1]] = -2;
    _currentDirection = STOP;
    _lastDelta = 0;
    KeyPressed = false;
}

void Snake::update(const IDisplayModule &lib) {
    if (_currentDirection == END || _head[0] < 1 || _head[0] > 13 || _head[1] < 1 || _head[1] > 15) {
        _currentDirection = END; 
        return;
    }
    _lastDelta += lib.getDelta();
    if (KeyPressed != true)
        keyPressed(lib);
    if (_currentDirection == STOP)
        return;
    if (_lastDelta >= 6) {
        _lastDelta = 0;
        KeyPressed = false;
        setFood();
        checkNextHead();
        moveHead();
        if (_head[0] == _food[0][0] && _head[1] == _food[0][1]) {
            isEats();
            resetBodyValues(1);
        }
        else {
            moveTail();
            resetBodyValues(0);
        }
    }
}

int Snake::getCurrentDirection() const {
    return _currentDirection;
}

int Snake::getScore() const {
    return _size;
}

void Snake::checkNextHead() {
    if (_currentDirection == UP) {
        if (_map[_head[0] - 1][_head[1]] > 0)
            _currentDirection = END;
    }
    else if (_currentDirection == DOWN) {
        if (_map[_head[0] + 1][_head[1]] > 0)
            _currentDirection = END;
    }
    else if (_currentDirection == RIGHT) {
        if (_map[_head[0]][_head[1] + 1] > 0)
            _currentDirection = END;
    }
    else if (_currentDirection == LEFT) {
        if (_map[_head[0]][_head[1] - 1] > 0)
            _currentDirection = END;
    }
}

void Snake::keyPressed(const IDisplayModule &lib) {
    if (lib.isKeyPressed(IDisplayModule::Keys::UP) && (_currentDirection != DOWN)) {
        _currentDirection = UP;
        KeyPressed = true;
    }
    else if (lib.isKeyPressed(IDisplayModule::Keys::DOWN) && (_currentDirection != UP)) {
        _currentDirection = DOWN;
        KeyPressed = true;
    }
    else if (lib.isKeyPressed(IDisplayModule::Keys::RIGHT) && (_currentDirection != LEFT)) {
        _currentDirection = RIGHT;
        KeyPressed = true;
    }
    else if (lib.isKeyPressed(IDisplayModule::Keys::LEFT) && (_currentDirection != RIGHT) && (_currentDirection != STOP)) {
        _currentDirection = LEFT;
        KeyPressed = true;
    }
}

void Snake::moveHead() {
    _map[_head[0]][_head[1]] = 1;
    if (_currentDirection == UP)
        _head = {_head[0] - 1, _head[1]};
    else if (_currentDirection == DOWN)
        _head = {_head[0] + 1, _head[1]};
    else if (_currentDirection == RIGHT)
        _head = {_head[0], _head[1] + 1};
    else if (_currentDirection == LEFT)
        _head = {_head[0], _head[1] - 1};
    _map[_head[0]][_head[1]] = 1;
}

void Snake::moveTail() {
    _lastValue = _map[_tail[0]][_tail[1]];

    _map[_tail[0]][_tail[1]] = 0;
    if (_map[_tail[0] + 1][_tail[1]] == _lastValue - 1)
        _tail[0] += 1;
    else if (_map[_tail[0] - 1][_tail[1]] == _lastValue - 1)
        _tail[0] -= 1;
    else if (_map[_tail[0]][_tail[1] + 1] == _lastValue - 1)
        _tail[1] += 1;
    else if (_map[_tail[0]][_tail[1] - 1] == _lastValue - 1)
        _tail[1] -= 1;
}

void Snake::resetBodyValues(int inc) {
    for (size_t loop = _lastValue - 1 + inc; loop >= 1; loop--) {
        for (size_t i = 0; i < HEIGHT_MAP + 2; i++) {
            for (size_t j = 0; j < WIDTH_MAP + 2; j++) {
                if (_map[i][j] == loop && !(i == _head[0] && j == _head[1]))
                     _map[i][j] = loop + 1;
            }
        }
    }
}

void Snake::setFood() {
    for (size_t k = 0; k < 1; k++)
        _map[_food[0][0]][_food[0][1]] = -2;
}

void Snake::isEats() {
    while (_map[_food[0][0]][_food[0][1]] > 0 && _map[_food[0][0]][_food[0][1]] != -2) {
        _food[0][0] = rand()%13+1;
        _food[0][1] = rand()%13+1;
    }
    _map[_food[0][0]][_food[0][1]] = -2;
    _size += 1;
}

void Snake::render(IDisplayModule &lib) {
    for (size_t i = 0; i < HEIGHT_MAP + 2; i++) {
        for (size_t j = 0; j < WIDTH_MAP + 2; j++) {
            if (_map[i][j] == 0) {
                if (i % 2 == 0) {
                    if (j % 2 == 0)
                        lib.setColor(IDisplayModule::Colors::LIGHT_GREEN);
                    else if (j % 2 == 1)
                        lib.setColor(IDisplayModule::Colors::GREEN);
                }
                else {
                    if (j % 2 == 1)
                        lib.setColor(IDisplayModule::Colors::LIGHT_GREEN);
                    else if (j % 2 == 0)
                        lib.setColor(IDisplayModule::Colors::GREEN);
                }
            }
            else if (_map[i][j] == -2)
                lib.setColor(IDisplayModule::Colors::RED);
            else if (_map[i][j] >= 2)
                lib.setColor(IDisplayModule::Colors::WHITE);
            else if (_map[i][j] == 1)
                lib.setColor(IDisplayModule::Colors::BLUE);
            else
                lib.setColor(IDisplayModule::Colors::LIGHT_GRAY);
            lib.putFillRect((j * 32), (i * 32), 32, 32);
        }
    }
}