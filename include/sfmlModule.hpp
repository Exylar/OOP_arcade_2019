/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** sfmlModule.hpp
*/

#ifndef B5D31BB5_2246_4B52_BD9D_7EFB6B191F5C
#define B5D31BB5_2246_4B52_BD9D_7EFB6B191F5C

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <string>
#include <memory>

#include "IDisplayModule.hpp"

class SfmlModule : public IDisplayModule {
    public:
    SfmlModule();
    ~SfmlModule();
    
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
    std::string _libname = "sfml";
    float _delta;
    std::unique_ptr<sf::RenderWindow> _window;
    sf::Color _currentColor;
    sf::Font _font;

    std::string _player;
    bool _shouldExit;
};
bool _keyState[IDisplayModule::Keys::KEYS_END] = {false};

#endif /* B5D31BB5_2246_4B52_BD9D_7EFB6B191F5C */
