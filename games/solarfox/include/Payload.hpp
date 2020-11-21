/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Payload.hpp
*/

#ifndef CFDFFC9F_401E_4182_A82B_A011365B9E39
#define CFDFFC9F_401E_4182_A82B_A011365B9E39

#include "Entity.hpp"
#include "IDisplayModule.hpp"

class Payload : public Entity {
    public:
        Payload() {
            setWidth(16);
            setHeigth(16);
        };
        ~Payload() {};
    
    public:
        bool isClaimed() const {return _claimed;};
        void setClaimed(bool claimed) {_claimed = claimed;};
        void draw(IDisplayModule &lib) const;

    protected:
        bool _claimed = false;
};

#endif /* CFDFFC9F_401E_4182_A82B_A011365B9E39 */
