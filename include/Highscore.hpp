/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Highscore.hpp
*/

#ifndef E148B2A8_6A9E_4D5D_BA6C_C7156EC79F06
#define E148B2A8_6A9E_4D5D_BA6C_C7156EC79F06

#include <vector>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include <algorithm>
class HighscoreScreen {
    public:
        HighscoreScreen()  {};
        ~HighscoreScreen() {};
    
        void draw(IDisplayModule &lib) const;
        void setGame(IGameModule &game);

    protected:
        IGameModule *_game;
};

#endif /* E148B2A8_6A9E_4D5D_BA6C_C7156EC79F06 */
