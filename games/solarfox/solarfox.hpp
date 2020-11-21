/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** solarfox.hpp
*/

#ifndef CD36AF0F_65EB_4C1A_AB57_0ABA62F22CC1
#define CD36AF0F_65EB_4C1A_AB57_0ABA62F22CC1

#include "IGameModule.hpp"
#include "HighscoreCore.hpp"
#include "Player.hpp"
#include "shoot.hpp"
#include "Ennemy.hpp"
#include "Payload.hpp"
#include <vector>

class SolarfoxModule : public IGameModule {
    public:
    SolarfoxModule();
    ~SolarfoxModule() {};

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
    void shootEvent(const IDisplayModule &lib);
    void ennemyEvent(const IDisplayModule &lib);
    void payloadEvent(const IDisplayModule &lib);

    //---------------------------------------------------------//
    protected:
    std::string _libname = "solarfox";
    bool _end = false;
    Player _p;
    std::string _playername;
    HighscoreCore _scores;
    std::pair<std::string, int> _lastScore;
    std::vector<Shoot> _shoots;
    std::vector<Ennemy> _ennemies;
    std::vector<Payload> _payloads;
};

#endif /* CD36AF0F_65EB_4C1A_AB57_0ABA62F22CC1 */
