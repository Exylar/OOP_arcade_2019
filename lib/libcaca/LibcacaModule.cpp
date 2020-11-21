/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** libcacaModule.cpp
*/

#include "LibcacaModule.hpp"

LibcacaModule::LibcacaModule() {
}

LibcacaModule::~LibcacaModule() {
    caca_free_canvas(this->_canvas);
    caca_free_display(this->_window);
}

void LibcacaModule::reset() 
{
    caca_get_event(this->_window, CACA_EVENT_KEY_PRESS, &this->_event, 1);
}

void LibcacaModule::open() {
    this->_canvas = caca_create_canvas(WIDTH / 8, HEIGHT / 16);
    this->_window = caca_create_display(this->_canvas);
    caca_set_display_time(this->_window, 1000000 / 60);
    caca_set_display_title(this->_window, "Arcade");
    this->_currentColor = CACA_WHITE;
    caca_set_color_ansi(this->_canvas, CACA_BLACK, this->_currentColor);
    caca_refresh_display(this->_window);
    reset();
    _shouldExit = false;
}

void LibcacaModule::close() {

}

bool LibcacaModule::isOpen() const {
    return !_shouldExit;
}

bool LibcacaModule::switchToNextLib() const {
    return (caca_get_event_key_ch(&_event) == CACA_KEY_F2);
}

bool LibcacaModule::switchToPreviousLib() const {
    return (caca_get_event_key_ch(&_event) == CACA_KEY_F1);
}

bool LibcacaModule::switchToNextGame() const {
    return (caca_get_event_key_ch(&_event) == CACA_KEY_F4);
}

bool LibcacaModule::switchToPreviousGame() const {
    return (caca_get_event_key_ch(&_event) == CACA_KEY_F1);
}

bool LibcacaModule::shouldBeRestarted() const {
    return (caca_get_event_key_utf32(&_event) == 'r') || (caca_get_event_key_utf32(&_event) == 'R');
}

bool LibcacaModule::shouldGoToMenu() const {
    return (caca_get_event_key_utf32(&_event) == 'm') || (caca_get_event_key_utf32(&_event) == 'M');
}

bool LibcacaModule::shouldExit() const {
    return (_shouldExit);
}

bool LibcacaModule::isKeyPressed(IDisplayModule::Keys k) const {
    if (caca_get_event_type(&this->_event) == CACA_EVENT_KEY_PRESS) {
        switch(k) {
            case LEFT:
            case Q:
                return (caca_get_event_key_utf32(&_event) == 'q') || (caca_get_event_key_utf32(&_event) == 'Q') || (caca_get_event_key_ch(&_event) == CACA_KEY_LEFT);
                break;
            case RIGHT:
            case D:
                return (caca_get_event_key_utf32(&_event) == 'd') || (caca_get_event_key_utf32(&_event) == 'D') || (caca_get_event_key_ch(&_event) == CACA_KEY_RIGHT);
                break;
            case Z:
            case UP:
                return (caca_get_event_key_utf32(&_event) == 'z') || (caca_get_event_key_utf32(&_event) == 'Z') || (caca_get_event_key_ch(&_event) == CACA_KEY_UP);
                break;
            case DOWN:
            case S:
                return (caca_get_event_key_utf32(&_event) == 's') || (caca_get_event_key_utf32(&_event) == 'S') || (caca_get_event_key_ch(&_event) == CACA_KEY_DOWN);
                break;
            case A:
                return (caca_get_event_key_utf32(&_event) == 'a') || (caca_get_event_key_utf32(&_event) == 'A');
                break;
            case E:
                return (caca_get_event_key_utf32(&_event) == 'e') || (caca_get_event_key_utf32(&_event) == 'E');
                break;
            case W:
                return (caca_get_event_key_utf32(&_event) == 'w') || (caca_get_event_key_utf32(&_event) == 'W');
                break;
            case X:
                return (caca_get_event_key_utf32(&_event) == 'x') || (caca_get_event_key_utf32(&_event) == 'X');
                break;
            case SPACE:
                return (caca_get_event_key_utf32(&_event) == ' ');
                break;
            case J:
                return (caca_get_event_key_utf32(&_event) == 'j') || (caca_get_event_key_utf32(&_event) == 'J');
                break;
            case K:
                return (caca_get_event_key_utf32(&_event) == 'k') || (caca_get_event_key_utf32(&_event) == 'K');
                break;
            case U:
                return (caca_get_event_key_utf32(&_event) == 'u') || (caca_get_event_key_utf32(&_event) == 'U');
                break;
            case I:
                return (caca_get_event_key_utf32(&_event) == 'i') || (caca_get_event_key_utf32(&_event) == 'I');
                break;
            case BACKSPACE:
                return (caca_get_event_key_ch(&_event) == CACA_KEY_BACKSPACE);
                break;
            case ENTER:
                return (caca_get_event_key_ch(&_event) == CACA_KEY_RETURN);
                break;
            default:
                return false;
                break;
        }
    }
    return false;
}

bool LibcacaModule::isKeyPressedOnce(IDisplayModule::Keys k) const {
    for (int i = 0; i < IDisplayModule::Keys::KEYS_END; i++) {
        if (!isKeyPressed((IDisplayModule::Keys) i))
            _keyState[i] = false;
    }
    if (!_keyState[k] && isKeyPressed(k)) {
        _keyState[k] = true;
        return (true);
    }
    return (false);
}

float LibcacaModule::getDelta() const {
    return 1;
}

void LibcacaModule::clear() const {
    caca_set_color_ansi(this->_canvas, CACA_BLACK, CACA_BLACK);
    caca_clear_canvas(this->_canvas);
    caca_set_color_ansi(this->_canvas, CACA_BLACK, this->_currentColor);
}

void LibcacaModule::update() {
    caca_get_event(this->_window, CACA_EVENT_KEY_PRESS, &this->_event, 1);
    if (caca_get_event_key_ch(&_event) == CACA_KEY_ESCAPE)
        _shouldExit = true;
}

void LibcacaModule::render() const {
    caca_refresh_display(this->_window);
}

char LibcacaModule::getKeyCode() const {
    if (caca_get_event_type(&this->_event) == CACA_EVENT_KEY_PRESS) {
        if (caca_get_event_key_ch(&_event) == CACA_KEY_RETURN)
            return '\n';
        else
            return caca_get_event_key_ch(&_event);
    }
    return '\0';
}

void LibcacaModule::setColor(IDisplayModule::Colors col) {
    switch(col) {
        case BLACK:
            this->_currentColor = CACA_BLACK;
            break;
        case RED:
            this->_currentColor = CACA_RED;
            break;
        case GREEN:
            this->_currentColor = CACA_GREEN;
            break;
        case YELLOW:
        case LIGHT_YELLOW:
            this->_currentColor = CACA_YELLOW;
            break;
        case BLUE:
            this->_currentColor = CACA_BLUE;
            break;
        case MAGENTA:
            this->_currentColor = CACA_MAGENTA;
            break;
        case CYAN:
            this->_currentColor = CACA_CYAN;
            break;
        case LIGHT_GRAY:
            this->_currentColor = CACA_LIGHTGRAY;
            break;
        case LIGHT_RED:
            this->_currentColor = CACA_LIGHTRED;
            break;
        case LIGHT_GREEN:
            this->_currentColor = CACA_LIGHTGREEN;
            break;
        case LIGHT_BLUE:
            this->_currentColor = CACA_LIGHTBLUE;
            break;
        case LIGHT_MAGENTA:
            this->_currentColor = CACA_LIGHTMAGENTA;
            break;
        case LIGHT_CYAN:
            this->_currentColor = CACA_LIGHTCYAN;
            break;
        case WHITE:
        case DEFAULT:
        default:
            this->_currentColor = CACA_WHITE;
            break;
    }
    caca_set_color_ansi(this->_canvas, CACA_BLACK, this->_currentColor);
}

void LibcacaModule::putPixel(float x, float y) const {
    caca_put_char(this->_canvas, (int)(x / 8), (int)(y / 16), ' ');
}

void LibcacaModule::putLine(float x1, float y1, float x2, float y2) const {
    caca_draw_line(this->_canvas, (int)(x1), (int)(y1 / 1), (int)(x2 / 8), (int)(y2 / 16), ' ');
}

void LibcacaModule::putRect(float x, float y, float w, float h) const {
    caca_draw_box(this->_canvas, (int)(x / 8), (int)(y / 16), (int)(w / 8), (int)(h / 16), ' ');
}

void LibcacaModule::putFillRect(float x, float y, float w, float h) const {
    caca_fill_box(this->_canvas, (int)(x / 8), (int)(y / 16), (int)(w / 8), (int)(h / 16), ' ');
}

void LibcacaModule::putCircle(float x, float y, float rad) const {
    caca_draw_ellipse(this->_canvas, (int)(x / 8), (int)(y / 16), (int)(rad / 8), (int)(((rad / 16) / 2) + 1) , ' ');
}

void LibcacaModule::putFillCircle(float x, float y, float rad) const {
    caca_fill_ellipse(this->_canvas, (int)(x / 8), (int)(y / 16), (int)(rad / 8), (int)(((rad / 16) / 2) + 1) , ' ');
}

void LibcacaModule::putText(const std::string &text, unsigned int size, float x, float y) const {
    caca_set_color_ansi(this->_canvas, this->_currentColor, CACA_TRANSPARENT);
    caca_put_str(this->_canvas, (int)((x / 8) + (size / 10)), (int)((y / 16) + (size / 32)), text.c_str());
    caca_set_color_ansi(this->_canvas, CACA_BLACK, this->_currentColor);
}

const std::string &LibcacaModule::getLibName() const {
    return _libname;
}

extern "C"
{
  std::unique_ptr<IDisplayModule>createLib(void)
  {
    return std::make_unique<LibcacaModule>();
  }
}