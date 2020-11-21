/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** NcursesModule.cpp
*/

#include "NcursesModule.hpp"

NcursesModule::NcursesModule() {

}

NcursesModule::~NcursesModule() {
    close();
}


void NcursesModule::reset() {
}

void NcursesModule::open() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    timeout(1000 / 60);

    start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_BLACK, COLOR_BLUE);
    init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(6, COLOR_BLACK, COLOR_CYAN);
    init_pair(7, COLOR_BLACK, COLOR_WHITE);
}

bool NcursesModule::isOpen() const {
    return !_shouldExit;
}

void NcursesModule::close() {
    endwin();
}

bool NcursesModule::switchToNextLib() const {
   return (_ch == 266);
}

bool NcursesModule::switchToPreviousLib() const {
    return (_ch == 265);
}

bool NcursesModule::switchToNextGame() const {
    return (_ch == 268);
}

bool NcursesModule::switchToPreviousGame() const {
    return (_ch == 267);
}

bool NcursesModule::shouldBeRestarted() const {
    return (_ch == 'R') || (_ch == 'r');
}

bool NcursesModule::shouldGoToMenu() const {
    return (_ch == 'M') || (_ch == 'm');
}

bool NcursesModule::shouldExit() const {
    return (_shouldExit);
}

bool NcursesModule::isKeyPressed(IDisplayModule::Keys k) const {
    switch(k) {
        case LEFT:
        case Q:
            return (_ch == 'Q') || (_ch == 'q') || (_ch == 260);
            break;
        case RIGHT:
        case D:
            return (_ch == 'D') || (_ch == 'd') || (_ch == 261);
            break;
        case Z:
        case UP:
            return (_ch == 'Z') || (_ch == 'z') || (_ch == 259);
            break;
        case DOWN:
        case S:
            return (_ch == 'S') || (_ch == 's') || (_ch == 258);
            break;
        case A:
            return (_ch == 'A') || (_ch == 'a');
            break;
        case E:
            return (_ch == 'E') || (_ch == 'a');
            break;
        case W:
            return (_ch == 'W') || (_ch == 'a');
            break;
        case X:
            return (_ch == 'X') || (_ch == 'a');
            break;
        case SPACE:
            return (_ch == ' ') || (_ch == 'a');
            break;
        case J:
            return (_ch == 'J') || (_ch == 'j');
            break;
        case K:
            return (_ch == 'K') || (_ch == 'k');
            break;
        case U:
            return (_ch == 'U') || (_ch == 'u');
            break;
        case I:
            return (_ch == 'I') || (_ch == 'i');
            break;
        case BACKSPACE:
            return (_ch == 263);
            break;
        case ENTER:
            return (_ch == '\n');
            break;
        default:
            return false;
            break;
    }
    
    return false;
}

bool NcursesModule::isKeyPressedOnce(IDisplayModule::Keys k) const {
    return isKeyPressed(k);
}

float NcursesModule::getDelta() const {
    return 1;
}

void NcursesModule::clear() const {
    erase();
}

void NcursesModule::update() {
    _ch = getch();

    if (_ch == 27)
        _shouldExit = true;
}

void NcursesModule::render() const {
    refresh();
}

char NcursesModule::getKeyCode() const {
    if (_ch == '\n')
        return '\n';
    else
        return _ch;
    return '\0';
}

void NcursesModule::setColor(IDisplayModule::Colors col) {
    start_color();
    switch(col) {
        case RED:
        case LIGHT_RED:
        case BLACK:
        case LIGHT_GRAY:
        case DARK_GRAY:
            this->_currentColor = COLOR_RED;
            break;
        case GREEN:
        case LIGHT_GREEN:
            this->_currentColor = COLOR_GREEN;
            break;
        case YELLOW:
        case LIGHT_YELLOW:
            this->_currentColor = COLOR_YELLOW;
            break;
        case BLUE:
        case LIGHT_BLUE:
            this->_currentColor = COLOR_BLUE;
            break;
        case MAGENTA:
        case LIGHT_MAGENTA:
            this->_currentColor = COLOR_MAGENTA;
            break;
        case CYAN:
        case LIGHT_CYAN:
            this->_currentColor = COLOR_CYAN;
            break;
        case WHITE:
        case DEFAULT:
        default:
            this->_currentColor = COLOR_WHITE;
            break;
    }
}

void NcursesModule::putPixel(float x, float y) const {
    attron(COLOR_PAIR(_currentColor));
    mvprintw((int)(y / 16), (int)(x / 8), " ");
    attroff(COLOR_PAIR(_currentColor));
}

void NcursesModule::putLine(float x1, float y1, float x2, float y2) const {
    attron(COLOR_PAIR(_currentColor));
    if (x1 == x2) {
        for (size_t axe_y = (y1 / 16); axe_y <= (y2 / 16) + (y1 / 16); axe_y++)
            mvprintw(axe_y, x1, " ");
    }
    else if (y1 == y2) {
        for (size_t axe_x = (x1 / 8); axe_x <= (x2 / 8) + (x1 / 8); axe_x++)
            mvprintw(y1, axe_x, " ");
    }     
    attron(COLOR_PAIR(_currentColor));
}

void NcursesModule::putRect(float x, float y, float w, float h) const {
    attron(COLOR_PAIR(_currentColor));
    for (size_t axe_y = (y / 16); axe_y <= (y / 16) + (h / 16); axe_y++) {
        for (size_t axe_x = (x / 8); axe_x <= (x / 8) + (w / 8); axe_x++) {
            if (axe_y == (int)(y / 16) || axe_y == (int)((y / 8) + (h / 16))
            || axe_y != (int)(y / 16) && (axe_x == (int)(x / 8) || axe_x == (int)((x / 8) + (w / 8)))) {
                mvprintw(axe_y, axe_x, " ");
            }
        }
    }
    attron(COLOR_PAIR(_currentColor));
}

void NcursesModule::putFillRect(float x, float y, float w, float h) const {
    attron(COLOR_PAIR(_currentColor));
    for (size_t axe_y = (y / 16); axe_y <= (y / 16) + (h / 16); axe_y++) {
        for (size_t axe_x = (x / 8); axe_x <= (x / 8) + (w / 8); axe_x++) {
            mvprintw(axe_y, axe_x, " ");
        }
    }
    attron(COLOR_PAIR(_currentColor));
}

void NcursesModule::putCircle(float x, float y, float rad) const {
}

void NcursesModule::putFillCircle(float x, float y, float rad) const {
}

void NcursesModule::putText(const std::string &text, unsigned int size, float x, float y) const {
    attroff(COLOR_PAIR(_currentColor));
    attron(COLOR_PAIR(0));
    mvprintw((int)((y / 16) + (size / 32)), (int)((x / 8) + (size / 10)), text.c_str());
    attroff(COLOR_PAIR(0));
    attron(COLOR_PAIR(_currentColor));
}

const std::string &NcursesModule::getLibName() const {
    return _libname;
}

extern "C"
{
  std::unique_ptr<IDisplayModule>createLib(void)
  {
    return std::make_unique<NcursesModule>();
  }
}