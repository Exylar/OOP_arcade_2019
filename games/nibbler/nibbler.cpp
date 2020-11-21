/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** nibbler.cpp
*/

#include "Snake.hpp"
#include "nibbler.hpp"

NibblerModule::NibblerModule() : IGameModule() {
    loadFromFile();
    _game = new Snake;
    reset();
}

NibblerModule::~NibblerModule() {
    delete _game;
}

void NibblerModule::reset() {
    _game->reset();
    _end = false;
}

bool NibblerModule::loadFromFile(const std::string &filepath) {
    return _scores.loadFromFile(filepath);
}

bool NibblerModule::loadFromFile() {
    return _scores.loadFromFile("score/" + getLibName());
}

bool NibblerModule::saveToFile(const std::string &filepath) const {
    return saveToFile(filepath);
}

bool NibblerModule::saveToFile() const {
    return saveToFile("score/" + getLibName());
}

void NibblerModule::setPlayerName(const std::string &name) {
    _playername = name;
}

std::pair<std::string, int> NibblerModule::getScore() const {
    return {"", 0};
}

std::vector<std::pair<std::string, int>> NibblerModule::getBestScores() const {
    return _scores.getBestScores();
}

void NibblerModule::update(const IDisplayModule &lib) {
    if (_end)
        return;
    _game->update(lib);
    if (_game->getCurrentDirection() == Snake::Direction::END) {
        _end = true;
        _scores.addscore(_playername, _game->getScore());
        _scores.saveToFile("score/" + getLibName());
    }
}

void NibblerModule::render(IDisplayModule &lib) const {
    _game->render(lib);
}

const std::string &NibblerModule::getLibName() const {
    return _libname;
}

extern "C"
{
  std::unique_ptr<IGameModule>createLib(void)
  {
    return std::make_unique<NibblerModule>();
  }
}