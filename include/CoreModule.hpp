/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** CoreModule.hpp
*/

#ifndef FFA00F97_A53E_4462_AF19_AAB7EDA79BB7
#define FFA00F97_A53E_4462_AF19_AAB7EDA79BB7

#include <vector>
#include <map>
#include <string>
#include <filesystem>
#include <iostream>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "SoLoader.hpp"
#include "Prompt.hpp"
#include "Highscore.hpp"

class CoreModule {

    enum status {
        MENU,
        GAME,
        SCORE,
        PROMPT
    };

    public:
    CoreModule(const std::string &librarypath);
    ~CoreModule();

    void loop();
    void reset();
    void previousGraphLib();
    void nextGraphLib();
    void previousGame();
    void nextGame();
    void menu();
    void prompt();
    void score();
    void exit();

    protected:
    std::string _playername = "Guest";
    Prompt _prompt;
    HighscoreScreen _score;

    std::unique_ptr<IDisplayModule> _display;
    std::unique_ptr<IGameModule> _game;
    SoLoader<IDisplayModule> *_displaySo;
    SoLoader<IGameModule> *_gameSo;
    
    std::vector<std::string> _displays;
    std::vector<std::string> _games;

    size_t _number_displays = 0;
    size_t _number_current_displays = 0;
    size_t _number_games = 0;
    size_t _number_current_games = 0;

    status _status = MENU;
    status _selected = PROMPT;
    bool _exit = false;
};

#endif /* FFA00F97_A53E_4462_AF19_AAB7EDA79BB7 */
