/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Ennemy.hpp
*/

#ifndef B851D9B3_7874_49F7_8F17_120A70DA3F1E
#define B851D9B3_7874_49F7_8F17_120A70DA3F1E

#include "IDisplayModule.hpp"
#include "Entity.hpp"

class Ennemy : public Entity {
    public:
        Ennemy(int intervalle, Direction shootDir):
            _intervalle(intervalle), _counter(intervalle), _shootDir(shootDir) {
            setWidth(16);
            setHeigth(16);
        };
        ~Ennemy() {};

    public:
        void draw(IDisplayModule &lib) const;
        void update();
        int getCounter() const {return _counter;};
        void setCounter(int count) {_counter = count;};
        int getInterval() const {return _intervalle;};
        Direction getShootDirection() const {return _shootDir;};
        
        bool isAlive() const {return _lives > 0;};
        void hit() {_lives--;};

    protected:
    Direction _shootDir;
    int _intervalle;
    int _counter;
    int _lives = 3;
};

#endif /* B851D9B3_7874_49F7_8F17_120A70DA3F1E */
