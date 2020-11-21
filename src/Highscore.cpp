/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Highscore.cpp
*/

#include "Highscore.hpp"

void HighscoreScreen::draw(IDisplayModule &lib) const {
    std::vector<std::pair<std::string, int>> scores = _game->getBestScores();
    int i = 0;

    lib.setColor(IDisplayModule::Colors::WHITE);
    lib.putText("Highscores", 50, 210, 50);
    lib.putText(_game->getLibName(), 25, 280, 110);
    for (std::vector<std::pair<std::string, int>>::iterator it = scores.begin();
         it != scores.end(); it++) {
            std::pair<std::string, int> item = *it;
            if (i < 8)
                lib.putText(std::to_string(i + 1) + ". " + item.first + ":" + std::to_string(item.second), 24, 100, 150 + (i * 32));
            else
                lib.putText(std::to_string(i + 1) + ". " + item.first + ":" + std::to_string(item.second), 24, 350, 150 + ((i % 8) * 32));
            i++;
    }
    while (i < 16) {
        if (i < 8)
            lib.putText(std::to_string(i + 1) + ". --", 24, 100, 150 + (i * 32));
        else
            lib.putText(std::to_string(i + 1) + ". --", 24, 350, 150 + ((i % 8)* 32));
        i++;
    }
    lib.putText("Previous Game : <Press U>    Next Game : <Press I>", 24, 20, 450);
}

void HighscoreScreen::setGame(IGameModule &game) {
    _game = &game;
}