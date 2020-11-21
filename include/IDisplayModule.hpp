/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** IDisplayModule.hpp
*/

#ifndef CBF23289_D25A_42E6_866C_5F60D8A4FC22
#define CBF23289_D25A_42E6_866C_5F60D8A4FC22

#include <string>
#include <iostream>
#include <memory>

//! Width of your window
#define WIDTH 640
//! Height of your window
#define HEIGHT 480

//! You Display class must inherit from IDisplayModule and have an extern createLib function for work properly
/*!
    extern "C"
    {
        std::unique_ptr<IDisplayModule>createLib(void)
        {
            return std::make_unique<YourClass>();
        }
    }
*/
class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;

        //! Limited to the bash color codes in case colors aren't handled by a library
        //! Limited to the bash color codes in case colors aren't handled by a library
        enum Colors {
            DEFAULT,
            BLACK,
            RED,
            GREEN,
            YELLOW,
            BLUE,
            MAGENTA,
            CYAN,
            LIGHT_GRAY,
            DARK_GRAY,
            LIGHT_RED,
            LIGHT_GREEN,
            LIGHT_YELLOW,
            LIGHT_BLUE,
            LIGHT_MAGENTA,
            LIGHT_CYAN,
            WHITE,
            COLORS_END
        };

        //! Keys you have to implement, there are enough keys to have multiple keyboard configurations for every game
        //! You only need 6 keys for the core and 6 for the games.
        enum Keys {
            LEFT,
            RIGHT,
            UP,
            DOWN,
            Z,
            Q,
            S,
            D,
            A,
            E,
            W,
            X,
            SPACE,
            J,
            K,
            U,
            I,
            ENTER,
            BACKSPACE,
            KEYS_END
        };

        //! For the core
        //! Reset the library
        virtual void reset() = 0;
        //! Opens / inits the window
        virtual void open() = 0;
        //! Closes / destroys the window
        virtual void close() = 0;
        //! Check if the window is open
        virtual bool isOpen() const = 0;

        //! are key presses
        //! must be different than the keys listed in the Keys enum.
        //! The keys enum only lists keys used by games, not special keys to switch libraries.
        virtual bool switchToNextLib() const = 0;
        //! are key presses
        //! must be different than the keys listed in the Keys enum.
        //! The keys enum only lists keys used by games, not special keys to switch libraries.
        virtual bool switchToPreviousLib() const = 0;
        //! are key presses
        //! must be different than the keys listed in the Keys enum.
        //! The keys enum only lists keys used by games, not special keys to switch libraries.
        virtual bool switchToNextGame() const = 0;
        //! are key presses
        //! must be different than the keys listed in the Keys enum.
        //! The keys enum only lists keys used by games, not special keys to switch libraries.
        virtual bool switchToPreviousGame() const = 0;
        //! are key presses
        //! must be different than the keys listed in the Keys enum.
        //! The keys enum only lists keys used by games, not special keys to switch libraries.
        virtual bool shouldBeRestarted() const = 0;
        //! are key presses
        //! must be different than the keys listed in the Keys enum.
        //! The keys enum only lists keys used by games, not special keys to switch libraries.
        virtual bool shouldGoToMenu() const = 0;
        //! are key presses
        //! must be different than the keys listed in the Keys enum.
        //! The keys enum only lists keys used by games, not special keys to switch libraries.
        virtual bool shouldExit() const = 0;

        //! Handle Inputs & Events
        /*!
            \see Keys
            \return true if the key is pressed
        */
        virtual bool isKeyPressed(IDisplayModule::Keys) const = 0;

        //! Handle Inputs & Events, but only once by key pressed
        /*!
            \see Keys
            \return true if the key is pressed
        */
        virtual bool isKeyPressedOnce(IDisplayModule::Keys) const = 0;

        //! Get the number of frames that passed between two calls to this function
        //! The games should not be frame dependant!! That's why this is here.
        virtual float getDelta() const = 0;

        //! clear the window
        virtual void clear() const = 0;
        //! update the window and handle basic events
        virtual void update() = 0;
        //! apply drawing function to the window
        virtual void render() const = 0;

        //! Handle Text Input
        //! Get key Presses.
        /*
            \return key pressed | \n if enter | \0 if nothing pressed | \b if backspace
        */
        virtual char getKeyCode() const = 0;

        //! Sets the color for all the following draw functions.
        //! everything you display after this will have the selected color
        /*!
            \see Colors
            \param col the color of future putXXX
        */
        virtual void setColor(IDisplayModule::Colors col) = 0;

        //! Display a pixel
        /*!
            \param x float coordinate in window
            \param y float coordinate in window
        */
        virtual void putPixel(float x, float y) const = 0;
        //! Display a line
        /*!
            \param x1 coordinates in window
            \param y1 coordinates in window
            \param x2 coordinates in window
            \param y2 coordinates in window
        */
        virtual void putLine(float x1, float y1, float x2, float y2) const = 0;
        //! Display an empty rectangle
        /*!
            \param x coordinates in window
            \param y coordinates in window
            \param w width of rect
            \param h height of rect
        */
        virtual void putRect(float x, float y, float w, float h) const = 0;
        //! Display a full rectangle
        /*!
            \param x coordinates in window
            \param y coordinates in window
            \param w width of rect
            \param h height of rect
        */
        virtual void putFillRect(float x, float y, float w, float h) const = 0;
        //! Display an empty circle
        /*!
            \param x coordinates in window
            \param y coordinates in window
            \param rad radius of the circle
        */
        virtual void putCircle(float x, float y, float rad) const = 0;
        //! Display a full circle
        /*!
            \param x coordinates in window
            \param y coordinates in window
            \param rad radius of the circle
        */
        virtual void putFillCircle(float x, float y, float rad) const = 0;
        //! Display some text
        /*!
            \param text text to display
            \param size size a caracter, in pixel
            \param x coordinates in windoww
            \param y coordinates in windoww
        */
        virtual void putText(const std::string &text, unsigned int size, float x, float y) const = 0;

        //! get the lib name
        /*!
            \return the lib name
        */
        virtual const std::string &getLibName() const = 0;
};

#endif /* CBF23289_D25A_42E6_866C_5F60D8A4FC22 */
