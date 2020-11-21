/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** shoot.hpp
*/

#ifndef A3124151_D62C_4487_A125_12C01D5F1CFB
#define A3124151_D62C_4487_A125_12C01D5F1CFB

#include "IDisplayModule.hpp"
#include "Player.hpp"
#include "Ennemy.hpp"
#include "Entity.hpp"

class Shoot : public Entity{
    public:
        enum From {ENNEMY, PLAYER};
    public:
        Shoot(From who) : _from(who) {
            setWidth(8);
            setHeigth(16);
        };
        ~Shoot() {};
    
    public:
        From getFrom() const {return _from;};

        void update(const IDisplayModule &win);
        void draw(IDisplayModule &win) const;

        bool isAlive() const {return _alive;};
        void setAlive(bool alive) {_alive = alive;};

    protected:

    protected:
    From _from;
    bool _alive = true;
};

#endif /* A3124151_D62C_4487_A125_12C01D5F1CFB */
