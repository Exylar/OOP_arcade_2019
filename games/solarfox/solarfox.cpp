/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** solarfox.cpp
*/

#include "solarfox.hpp"

SolarfoxModule::SolarfoxModule() : IGameModule() {
    loadFromFile();
    reset();
}

void SolarfoxModule::reset() {
    _shoots.clear();
    _ennemies.clear();
    _payloads.clear();
    _end = false;

    _lastScore = (std::pair<std::string, int>){_playername, 5000};
    _p = (Player){};

    _ennemies.push_back((Ennemy){100, Entity::Direction::DOWN});
    _ennemies[0].setX(0); _ennemies[0].setY(0); _ennemies[0].setV(1);
    _ennemies[0].setDirection(Entity::Direction::RIGHT);

    _ennemies.push_back((Ennemy){120, Entity::Direction::RIGHT});
    _ennemies[1].setX(0); _ennemies[1].setY(0); _ennemies[1].setV(2);
    _ennemies[1].setDirection(Entity::Direction::DOWN);

    _ennemies.push_back((Ennemy){80, Entity::Direction::LEFT});
    _ennemies[2].setX(630); _ennemies[2].setY(0); _ennemies[2].setV(1);
    _ennemies[2].setDirection(Entity::Direction::DOWN);

    _ennemies.push_back((Ennemy){70, Entity::Direction::UP});
    _ennemies[3].setX(0); _ennemies[3].setY(480); _ennemies[3].setV(2);
    _ennemies[3].setDirection(Entity::Direction::RIGHT);

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            Payload p;
            p.setX(i * 32 + 150);
            p.setY(j * 64 + 100);
            _payloads.push_back(p);
        }
    }
}

bool SolarfoxModule::loadFromFile(const std::string &filepath) {
    return _scores.loadFromFile(filepath);
}

bool SolarfoxModule::loadFromFile() {
    return _scores.loadFromFile("score/" + getLibName());
}

bool SolarfoxModule::saveToFile(const std::string &filepath) const {
    return saveToFile(filepath);
}

bool SolarfoxModule::saveToFile() const {
    return saveToFile("score/" + getLibName());
}

void SolarfoxModule::setPlayerName(const std::string &name) {
    _playername = name;
    _lastScore.first = name;
}

std::pair<std::string, int> SolarfoxModule::getScore() const {
    return {"", 0};
}

std::vector<std::pair<std::string, int>> SolarfoxModule::getBestScores() const {
    return _scores.getBestScores();
}

void SolarfoxModule::update(const IDisplayModule &lib) {
    if (_end)
        return;
    static float delta = 0;

    delta += lib.getDelta();
    if (delta >= 1) {
        if (_lastScore.second > 0)
            _lastScore.second--;
        delta = 0;
        if (_p.isAlive()) {
            _p.update(lib);
            shootEvent(lib);
            ennemyEvent(lib);
            payloadEvent(lib);
        }
    }
}

void SolarfoxModule::render(IDisplayModule &lib) const {
    for (const Shoot &s : _shoots) s.draw(lib);
    for (const Ennemy &e : _ennemies) e.draw(lib);
    for (const Payload &p : _payloads) p.draw(lib);
    _p.draw(lib);
    lib.putText(std::to_string(_lastScore.second), 16, 0, 0);
}

const std::string &SolarfoxModule::getLibName() const {
  return _libname;
}

//---------------------------------------------------------//

void SolarfoxModule::shootEvent(const IDisplayModule &lib) {
    for (Shoot &s : _shoots) {
        s.update(lib);
    }
    if (lib.isKeyPressedOnce(IDisplayModule::Keys::SPACE)) {
        Shoot s(Shoot::From::PLAYER);
        s.setX(_p.getX() + 10);
        s.setY(_p.getY() + 10);
        s.setV(12);
        s.setDirection(_p.getDirection());
        _shoots.push_back(s);
    }
    //player hit ennemies
    for (Ennemy &e : _ennemies) {
        if (e.isAlive()) {
            for (Shoot &s : _shoots) {
                if (s.isAlive() && s.getFrom() == Shoot::PLAYER && e.isCollide(s)) {
                    s.setAlive(false);
                    e.hit();
                }
            }
        }
    }
    //ennemies hit player
    for (Shoot &s : _shoots) {
        if (s.isAlive() && s.getFrom() == Shoot::ENNEMY && _p.isCollide(s)) {
            s.setAlive(false);
             _p.hit();
        } 
    }
}

void SolarfoxModule::ennemyEvent(const IDisplayModule &lib) {
    //shoots
    for (Ennemy &e: _ennemies) {
        e.update();
        if (e.getCounter() < 0) {
            Shoot s(Shoot::From::ENNEMY);
            s.setX(e.getX());
            s.setY(e.getY());
            s.setV(8);
            s.setDirection(e.getShootDirection());
            _shoots.push_back(s);
            e.setCounter(e.getInterval());
        }
    }
}

void SolarfoxModule::payloadEvent(const IDisplayModule &lib) {
    //check collision
    for (Payload &p : _payloads) {
        if (_p.isCollide(p)) {
            p.setClaimed(true);
        }
    }

    //check victory
    for (Payload &p : _payloads) {
        if (!p.isClaimed())
            return;
    }
    //win
    _end = true;
    _scores.addscore(_lastScore.first, _lastScore.second);
    _scores.saveToFile("score/" + getLibName());
}

//---------------------------------------------------------//
extern "C"
{
  std::unique_ptr<IGameModule>createLib(void)
  {
    return std::make_unique<SolarfoxModule>();
  }
}
