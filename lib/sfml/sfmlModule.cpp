/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** sfml.cpp
*/

#include "sfmlModule.hpp"

SfmlModule::SfmlModule() {
    _font.loadFromFile("./assets/arial.ttf");
    reset();
}

SfmlModule::~SfmlModule() {
    _window->close();
}

void SfmlModule::reset() {
    _delta = 0;
    _shouldExit = false;
}

void SfmlModule::open() {
    _window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH + 8, HEIGHT + 16), "Arcade");
    _window->setFramerateLimit(60);
}

void SfmlModule::close() {
    if (this->_window != nullptr) {
        this->_window->close();
        this->_window.release();
    }
}

bool SfmlModule::isOpen() const{
    return (_window->isOpen());
}

bool SfmlModule::switchToNextLib() const {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F2);
}

bool SfmlModule::switchToPreviousLib() const {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F1);
}

bool SfmlModule::switchToNextGame() const {
    static bool state = false;

    if (state && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F4))
        return false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F4)) {
        state = true;
        return true;
    } else {
        state = false;
    }
    return (false);
}

bool SfmlModule::switchToPreviousGame() const {
        static bool state = false;

    if (state && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F3))
        return false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F3)) {
        state = true;
        return true;
    } else {
        state = false;
    }
    return (false);
}

bool SfmlModule::shouldBeRestarted() const {
    return(sf::Keyboard::isKeyPressed(sf::Keyboard::R));
}

bool SfmlModule::shouldGoToMenu() const {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::M));
}

bool SfmlModule::shouldExit() const {
    return (_shouldExit);
}

bool SfmlModule::isKeyPressed(IDisplayModule::Keys k) const {
    switch(k) {
        case LEFT:
        case Q:
            return (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
            break;
        case RIGHT:
        case D:
            return (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
            break;
        case Z:
        case UP:
            return (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
            break;
        case DOWN:
        case S:
            return (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S));
            break;
        case A:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
            break;
        case E:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::E);
            break;
        case W:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
            break;
        case X:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::X);
            break;
        case SPACE:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
            break;
        case J:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::J);
            break;
        case K:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::K);
            break;
        case U:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::U);
            break;
        case I:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::I);
            break;
        case ENTER:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Return);
            break;
        case BACKSPACE:
            return sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace);
            break;
        default:
            return false;
            break;
    }
}

bool SfmlModule::isKeyPressedOnce(IDisplayModule::Keys k) const {
    if (!isKeyPressed(k))
        _keyState[k] = false;
    if (!_keyState[k] && isKeyPressed(k)) {
        _keyState[k] = true;
        return (true);
    }
    return (false);
}

float SfmlModule::getDelta() const {
    static sf::Clock clock;
    float frames = clock.getElapsedTime().asSeconds() * 60;

    clock.restart();
    return frames;
}

void SfmlModule::clear() const {
    _window->clear(sf::Color::Black);
}

void SfmlModule::update() {
    sf::Event event;
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window->close();
            _shouldExit = true;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        _window->close();
        _shouldExit = true;
    }
}

void SfmlModule::render() const {
    _window->display();
}

char SfmlModule::getKeyCode() const {
    char c = '\0';
    static bool state[(int)sf::Keyboard::Z] = {false};

    for (int i = sf::Keyboard::A ; i <= sf::Keyboard::Z; i++) {
        if (!sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i))
            state[i] = false;
    }
    for (int i = sf::Keyboard::A ; i <= sf::Keyboard::Z; i++) {
        if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i) && !state[i]) {
            c = i + 97;
            state[i] = true;
        }
    }
    return (c);
}

void SfmlModule::setColor(IDisplayModule::Colors col) {
    switch (col) {
    case DEFAULT:
        _currentColor = sf::Color::White;
        break;
    case BLACK:
        _currentColor = sf::Color::Black;
        break;
    case RED:
        _currentColor = sf::Color(255, 0, 0);
        break;
    case LIGHT_RED:
        _currentColor = sf::Color(255, 102, 102);
        break;
    case LIGHT_GREEN:
        _currentColor = sf::Color(0, 255, 0);
        break;
    case GREEN:
        _currentColor = sf::Color(0, 153, 0);
        break;
    case LIGHT_YELLOW:
        _currentColor = sf::Color(255, 255, 102);
        break;
    case YELLOW:
        _currentColor = sf::Color(255, 255, 0);
        break;
    case LIGHT_BLUE:
        _currentColor = sf::Color(0, 128, 255);
        break;
    case BLUE:
        _currentColor = sf::Color(0, 0, 255);
        break;
    case LIGHT_MAGENTA:
        _currentColor = sf::Color(255, 102, 255);
        break;
    case MAGENTA:
        _currentColor = sf::Color(255, 0, 255);
        break;
    case LIGHT_CYAN:
        _currentColor = sf::Color(0, 255, 255);
        break;
    case CYAN:
        _currentColor = sf::Color(102, 255, 255);
        break;
    case LIGHT_GRAY:
        _currentColor = sf::Color(128, 128, 128);
        break;
    case DARK_GRAY:
        _currentColor = sf::Color(192, 192, 192);
        break;
    case WHITE:
        _currentColor = sf::Color::White;
        break;
    case COLORS_END:
        _currentColor = sf::Color::White;
        break;
    default:
        break;
    }
}

void SfmlModule::putPixel(float x, float y) const {
    putFillRect(x,y,1,1);
}

void SfmlModule::putLine(float x1, float y1, float x2, float y2) const {
    sf::Vertex line[] ={sf::Vertex(sf::Vector2f(x1, y1)), sf::Vertex(sf::Vector2f(x2, y2))};

    _window->draw(line, 2, sf::Lines);
}

void SfmlModule::putRect(float x, float y, float w, float h) const {
    sf::RectangleShape shape(sf::Vector2f(w-16, h-16));

    shape.setPosition(x+16, y+16);
    shape.setOutlineColor(_currentColor);
    shape.setOutlineThickness(16);
    shape.setFillColor(sf::Color::Black);
    _window->draw(shape);
}

void SfmlModule::putFillRect(float x, float y, float w, float h) const {
    sf::RectangleShape shape(sf::Vector2f(w, h));

    shape.setPosition(x, y);
    shape.setFillColor(_currentColor);
    _window->draw(shape);
}

void SfmlModule::putCircle(float x, float y, float rad) const {
    sf::CircleShape shape(rad);

    shape.setPosition(x, y);
    shape.setOutlineColor(_currentColor);
    shape.setOutlineThickness(3);
    shape.setFillColor(sf::Color::Black);
    _window->draw(shape);
}

void SfmlModule::putFillCircle(float x, float y, float rad) const {
    sf::CircleShape shape(rad);

    shape.setPosition(x, y);
    shape.setFillColor(_currentColor);
    _window->draw(shape);
}

void SfmlModule::putText(const std::string &text, unsigned int size, float x, float y) const {
    sf::Text t;
    
    t.setString(text);
    t.setFillColor(_currentColor);
    t.setFont(_font);
    t.setCharacterSize(size);
    t.setPosition(x, y);
    _window->draw(t);
}

const std::string &SfmlModule::getLibName() const {
    return _libname;
}

extern "C" {
    std::unique_ptr<IDisplayModule>createLib(void) {
        return std::make_unique<SfmlModule>();
    }
}