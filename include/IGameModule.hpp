/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** IGameModule.hpp
*/

#ifndef DB865092_F1E8_4A6B_8572_D0D0A1236F4A
#define DB865092_F1E8_4A6B_8572_D0D0A1236F4A

#define SAVE_PATH "games/.saves/"
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "IDisplayModule.hpp"

//! You Game class must inherit from IGameModule and have an extern createLib function for work properly
/*!
    extern "C"
    {
        std::unique_ptr<IGameModule>createLib(void)
        {
            return std::make_unique<YourClass>();
        }
    }
*/
class IGameModule {
    public:
        virtual ~IGameModule() = default;

        //! Reset game at any moment
        virtual void reset() = 0;

        //! Load highscores from file and return wether it worked or not
        virtual bool loadFromFile(const std::string &filepath) = 0;
        //! Load highscores from file and return wether it worked or not
        virtual bool loadFromFile() = 0;

        //! save highscores to file
        /*!
            \see HighscoreCore
            \return sucess
        */
        virtual bool saveToFile(const std::string &filepath) const = 0; // with filename
        //! save highscores to default file
        /*!
            \see HighscoreCore
            \return sucess
        */
        virtual bool saveToFile() const = 0; // default filename

        //! Set the player's name for the highscore
        /*!
            \param name name to set
        */
        virtual void setPlayerName(const std::string &name) = 0;
        //! get the current score (the last)
        /*!
            \return the last score
        */
        virtual std::pair<std::string, int> getScore() const = 0;

        //! get the 16 best scores
        /*!
            \return 16 best score of this game (sorted)
        */
        virtual std::vector<std::pair<std::string, int>> getBestScores() const = 0;

        //! update the game, do all change to internal here (event, moves, ...)
        /*!
            \param lib an IDisplayLib, provided by the core, dont call it yourself, use this only for events
        */
        virtual void update(const IDisplayModule &lib) = 0;
        //! render your game, all display must be here
        /*!
            \param lib, provided by the core (don't call it yourself), use this only for drawing
        */
        virtual void render(IDisplayModule &lib) const = 0;

        //!get the lib name
        /*!
            \return the lib name
        */
        virtual const std::string &getLibName() const = 0;
};

#endif /* DB865092_F1E8_4A6B_8572_D0D0A1236F4A */
