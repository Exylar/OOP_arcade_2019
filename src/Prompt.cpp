/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Prompt.cpp
*/

#include "Prompt.hpp"

const std::string &Prompt::loop(IDisplayModule &lib) {
    while (1) {
        if (lib.shouldExit()) {_current.clear(); return (_current);}
        if (_exit && !_current.empty()) {return (_current);}

        lib.clear();
        lib.update();
        update(lib);
        draw(lib);
        lib.render();
    }
}

//--------------------------  -------------------------------//

void Prompt::draw(IDisplayModule &lib) {
    lib.setColor(IDisplayModule::Colors::WHITE);
    lib.putRect(100, 230, 440, 100);
    lib.putText(_current, 32, 150, 260);
}

void Prompt::update(IDisplayModule &lib) {
    if (lib.isKeyPressed(IDisplayModule::Keys::BACKSPACE) && !_current.empty()) {
        _current.pop_back();
    } else if (lib.isKeyPressed(IDisplayModule::Keys::ENTER)) {
        if (!_current.empty())
            _exit = true;
    } else {
        char c = lib.getKeyCode();

        if (c == '\0')
            return;
        if (_current.size() < 20) {
            if (c != 0)
                _current += c;
        }
    }
}