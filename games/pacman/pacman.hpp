/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** nibbler.hpp
*/

#ifndef NIBBLER_HPP
#define NIBBLER_HPP

#include "HighscoreCore.hpp"
#include "IGameModule.hpp"
#include "IDisplayModule.hpp"

class PacmanModule : public IGameModule {
    public:
    PacmanModule();
    ~PacmanModule();

    //---------------------------------------------------------//
    public:
    void reset();
    bool loadFromFile(const std::string &filepath); // with filename
    bool loadFromFile(); // default filename
    bool saveToFile(const std::string &filepath) const; // with filename
    bool saveToFile() const; // default filename
    void setPlayerName(const std::string &name);
    std::pair<std::string, int> getScore() const;
    std::vector<std::pair<std::string, int>> getBestScores() const;

    void update(const IDisplayModule &lib);
    void render(IDisplayModule &lib) const;
    const std::string &getLibName() const;

    //---------------------------------------------------------//

    protected:
        std::string _libname = "pacman";
        std::string _playername;
        HighscoreCore _scores;
        bool _end = false;
};

#endif /* NIBBLER_HPP */
