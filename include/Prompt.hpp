/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Prompt.hpp
*/

#ifndef C7CF08C9_C40A_4FDA_ADBD_0A9D84008A27
#define C7CF08C9_C40A_4FDA_ADBD_0A9D84008A27

#include "IDisplayModule.hpp"
#include <string>

class Prompt {
    public:
        Prompt() {};
        ~Prompt() {};
    
        const std::string &loop(IDisplayModule &lib);
        void reset() {_exit = false; _current = "";};
        
    protected:
        void draw(IDisplayModule &lib);
        const std::string &getName() const {return _current;};
        void update(IDisplayModule &lib);

        bool _exit = false;
        std::string _current = "";
};

#endif /* C7CF08C9_C40A_4FDA_ADBD_0A9D84008A27 */
