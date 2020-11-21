/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Player.hpp
*/

#ifndef EDB2831C_D819_41BF_AE56_63D8E69EB56F
#define EDB2831C_D819_41BF_AE56_63D8E69EB56F

#include "IDisplayModule.hpp"
#include "Entity.hpp"

class Player : public Entity {
    public:
        Player() {
            setV(4);
            setX(320);
            setY(280);
            setWidth(32);
            setHeigth(32);
        };
        ~Player() {};
    
    public:
        void update(const IDisplayModule &win);
        void draw(IDisplayModule &win) const;

        void hit() {_lives--;};
        bool isAlive() const {return _lives > 0;};

    protected:
        int _lives = 3;
};

#endif /* EDB2831C_D819_41BF_AE56_63D8E69EB56F */
