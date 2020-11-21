/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** nibbler.cpp
*/

#include "qix.hpp"

QixModule::QixModule() : IGameModule() {
    loadFromFile();
}

QixModule::~QixModule() {
}

void QixModule::reset() {
}

bool QixModule::loadFromFile(const std::string &filepath) {
    return _scores.loadFromFile(filepath);
}

bool QixModule::loadFromFile() {
    return _scores.loadFromFile("score/" + getLibName());
}

bool QixModule::saveToFile(const std::string &filepath) const {
    return saveToFile(filepath);
}

bool QixModule::saveToFile() const {
    return saveToFile("score/" + getLibName());
}

void QixModule::setPlayerName(const std::string &name) {
    _playername = name;
}

std::pair<std::string, int> QixModule::getScore() const {
    return {"", 0};
}

std::vector<std::pair<std::string, int>> QixModule::getBestScores() const {
    return _scores.getBestScores();
}

void QixModule::update(const IDisplayModule &lib) {
}

void QixModule::render(IDisplayModule &lib) const {
    lib.putText("Game not available", 10, 0, 0);
}

const std::string &QixModule::getLibName() const {
    return _libname;
}

extern "C"
{
  std::unique_ptr<IGameModule>createLib(void)
  {
    return std::make_unique<QixModule>();
  }
}