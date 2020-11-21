/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** nibbler.cpp
*/

#include "centipede.hpp"

CentipedeModule::CentipedeModule() : IGameModule() {
    loadFromFile();
}

CentipedeModule::~CentipedeModule() {
}

void CentipedeModule::reset() {
}

bool CentipedeModule::loadFromFile(const std::string &filepath) {
    return _scores.loadFromFile(filepath);
}

bool CentipedeModule::loadFromFile() {
    return _scores.loadFromFile("score/" + getLibName());
}

bool CentipedeModule::saveToFile(const std::string &filepath) const {
    return saveToFile(filepath);
}

bool CentipedeModule::saveToFile() const {
    return saveToFile("score/" + getLibName());
}

void CentipedeModule::setPlayerName(const std::string &name) {
    _playername = name;
}

std::pair<std::string, int> CentipedeModule::getScore() const {
    return {"", 0};
}

std::vector<std::pair<std::string, int>> CentipedeModule::getBestScores() const {
    return _scores.getBestScores();
}

void CentipedeModule::update(const IDisplayModule &lib) {
}

void CentipedeModule::render(IDisplayModule &lib) const {
    lib.putText("Game not available", 10, 0, 0);
}

const std::string &CentipedeModule::getLibName() const {
    return _libname;
}

extern "C"
{
  std::unique_ptr<IGameModule>createLib(void)
  {
    return std::make_unique<CentipedeModule>();
  }
}