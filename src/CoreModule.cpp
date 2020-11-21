/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** CoreModule.cpp
*/

#include "CoreModule.hpp"

CoreModule::CoreModule(const std::string &librarypath) {
    std::string path_array;
    std::string path_librarypath;

    for (const auto & list_libs : std::filesystem::directory_iterator("./lib/")) {
        if (list_libs.path().extension() == ".so") {
            _displays.push_back(list_libs.path());
            _number_displays++;
        }
    }
    for (const auto & list_games : std::filesystem::directory_iterator("./games/")) {
        if (list_games.path().extension() == ".so") {
            _games.push_back(list_games.path());
            _number_games++;
        }
    }
    if (_games.size() == 0)
        throw LibraryError("No valid game so found");
    _number_current_games = 0;
    if (librarypath.find("lib/") == std::string::npos)
        throw ParameterError("Library passed as parameter is not a graphical library");
    path_librarypath = librarypath.substr(librarypath.find("lib/"));
    for (size_t i = 0; i < _number_displays; i++) {
        path_array = _displays[i].substr(_displays[i].find("lib/"));
        if (path_array != path_librarypath)
            _number_current_displays++;
        else
            break;
    }
    _displaySo = new SoLoader<IDisplayModule>(_displays[_number_current_displays]);
    _display = _displaySo->getInstance("createLib");
    _gameSo = new SoLoader<IGameModule>(_games[0]);
    _game = _gameSo->getInstance("createLib");
    _game->setPlayerName(_playername);
    _score.setGame(*(_game.get()));
}

CoreModule::~CoreModule() {
    IDisplayModule *lib = _display.release();
    IGameModule *game = _game.release();
    delete lib;
    delete game;
    delete _displaySo;
    delete _gameSo;
}

void CoreModule::loop() {
    _display->open();
    while (_display->isOpen() && !_exit) {
        _display->update();
        _display->clear();
        if (_display->switchToNextLib())
            nextGraphLib();
        else if (_display->switchToPreviousLib())
            previousGraphLib();
        if (_display->switchToNextGame())
            nextGame();
        else if (_display->switchToPreviousGame())
            previousGame();

        if (_display->isKeyPressedOnce(IDisplayModule::Keys::ENTER) && _status != GAME)
            _status = _selected;
            
        if (_display->shouldGoToMenu()) {
            reset();
            _status = MENU;
        }

        if (_display->isKeyPressedOnce(IDisplayModule::Keys::UP) && _status == MENU)
            _selected = PROMPT;
        if (_display->isKeyPressedOnce(IDisplayModule::Keys::DOWN) && _status == MENU)
            _selected = SCORE;


        if (_status == MENU)
            menu();
        else if (_status == PROMPT)
            prompt();
        else if (_status == SCORE)
            score();
        else if (_status == GAME) {
            if (_display->shouldBeRestarted())
                reset();
            _game->update(*_display);
            _game->render(*_display);
        }
        _display->render();
    }
}

void CoreModule::reset() {
    _display->reset();
    _game->reset();
}

void CoreModule::previousGraphLib() {
    if (_number_current_displays > 0)
        _number_current_displays--;
    else
        _number_current_displays = _number_displays - 1;
    _displaySo = new SoLoader<IDisplayModule>(_displays[_number_current_displays]);
    _display = _displaySo->getInstance("createLib");
    _display->open();
}

void CoreModule::nextGraphLib() {
    if (_number_current_displays + 1 < _number_displays)
        _number_current_displays++;
    else
        _number_current_displays = 0;
    _displaySo = new SoLoader<IDisplayModule>(_displays[_number_current_displays]);
    _display = _displaySo->getInstance("createLib");
    _display->open();
}

void CoreModule::previousGame() {
    if (_number_current_games > 0)
        _number_current_games--;
    else
        _number_current_games = _number_games - 1;
    _gameSo = new SoLoader<IGameModule>(_games[_number_current_games]);
    _game = _gameSo->getInstance("createLib");
    _game->setPlayerName(_playername);
    _score.setGame(*(_game.get()));
}

void CoreModule::nextGame() {
    if (_number_current_games + 1 < _number_games)
        _number_current_games++;
    else
        _number_current_games = 0;
    _gameSo = new SoLoader<IGameModule>(_games[_number_current_games]);
    _game = _gameSo->getInstance("createLib");
    _game->setPlayerName(_playername);
    _score.setGame(*(_game.get()));
}

void CoreModule::menu() {
    _display->setColor(IDisplayModule::Colors::MAGENTA);
    _display->putFillRect(150, 50, 360, 50);
    _display->setColor(IDisplayModule::Colors::YELLOW);
    _display->putText("ARCADE", 75, 215, 35);

    if (_selected == GAME || _selected == PROMPT)
        _display->setColor(IDisplayModule::Colors::WHITE);
    else 
        _display->setColor(IDisplayModule::Colors::LIGHT_GRAY);
    _display->putFillRect(180, 250, 280, 50);
    _display->setColor(IDisplayModule::Colors::LIGHT_BLUE);
    _display->putText("PLAY", 50, 275, 249);

    if (_selected == SCORE)
        _display->setColor(IDisplayModule::Colors::WHITE);
    else 
        _display->setColor(IDisplayModule::Colors::LIGHT_GRAY);
    _display->putFillRect(180, 350, 280, 50);
    _display->setColor(IDisplayModule::Colors::LIGHT_BLUE);
    _display->putText("SCOREBOARD", 50, 195, 349);
}

void CoreModule::prompt() {
    _playername = _prompt.loop(*_display);

    if (_playername.empty())
        exit();
    else {
        _game->setPlayerName(_playername);
        _status = GAME;
        _prompt.reset();
    }
}

void CoreModule::score() {
    _score.draw(*_display);
}

void CoreModule::exit() {
    _exit = true;
}