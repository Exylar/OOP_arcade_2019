/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** NcursesModule.hpp
*/

#ifndef LIB_CACA_HPP
#define LIB_CACA_HPP

#include <ncurses.h>
#include <sys/select.h>
#include <memory>
#include <unistd.h>
#include "IDisplayModule.hpp"

class NcursesModule : public IDisplayModule {
    public:
    NcursesModule();
    ~NcursesModule();

    void reset();
    void open();
    void close();
    bool isOpen() const;

    bool switchToNextLib() const;
    bool switchToPreviousLib() const;
    bool switchToNextGame() const;
    bool switchToPreviousGame() const;

    bool shouldBeRestarted() const;
    bool shouldGoToMenu() const;
    bool shouldExit() const;

    bool isKeyPressed(IDisplayModule::Keys) const;
    bool isKeyPressedOnce(IDisplayModule::Keys) const;
    float getDelta() const;

    void clear() const;
    void update();
    void render() const;

    char getKeyCode() const;
    void setColor(IDisplayModule::Colors col);
    void putPixel(float x, float y) const;
    void putLine(float x1, float y1, float x2, float y2) const;
    void putRect(float x, float y, float w, float h) const;
    void putFillRect(float x, float y, float w, float h) const;
    void putCircle(float x, float y, float rad) const;
    void putFillCircle(float x, float y, float rad) const;
    void putText(const std::string &text, unsigned int size, float x, float y) const;

    const std::string &getLibName() const;

    protected:
    std::string _libname = "libNcurses";
    WINDOW *_window;
    int _currentColor;
    std::string _playerName;
    bool _shouldExit;
    float _delta;
    
    
};
    int _ch = 0;
    bool _keyState[IDisplayModule::Keys::KEYS_END] = {false};


#endif /* LIB_CACA_HPP */