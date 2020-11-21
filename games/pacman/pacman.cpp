/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** nibbler.cpp
*/

#include "pacman.hpp"

PacmanModule::PacmanModule() : IGameModule() {
    loadFromFile();
}

PacmanModule::~PacmanModule() {
}

void PacmanModule::reset() {
}

bool PacmanModule::loadFromFile(const std::string &filepath) {
    return _scores.loadFromFile(filepath);
}

bool PacmanModule::loadFromFile() {
    return _scores.loadFromFile("score/" + getLibName());
}

bool PacmanModule::saveToFile(const std::string &filepath) const {
    return saveToFile(filepath);
}

bool PacmanModule::saveToFile() const {
    return saveToFile("score/" + getLibName());
}

void PacmanModule::setPlayerName(const std::string &name) {
    _playername = name;
}

std::pair<std::string, int> PacmanModule::getScore() const {
    return {"", 0};
}

std::vector<std::pair<std::string, int>> PacmanModule::getBestScores() const {
    return _scores.getBestScores();
}

void PacmanModule::update(const IDisplayModule &lib) {
}

void PacmanModule::render(IDisplayModule &lib) const {
    lib.putText("Game not available", 10, 0, 0);
}

const std::string &PacmanModule::getLibName() const {
    return _libname;
}

extern "C"
{
  std::unique_ptr<IGameModule>createLib(void)
  {
    return std::make_unique<PacmanModule>();
  }
}