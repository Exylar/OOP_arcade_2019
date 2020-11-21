/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** HighscoreUtils.hpp
*/

#ifndef F4FB2965_6ED0_4287_B72E_244E007AFBF8
#define F4FB2965_6ED0_4287_B72E_244E007AFBF8

#include <string>
#include <cstring>
#include <vector>
#include <tuple>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unistd.h>

//! utils class for read an write scores
class HighscoreCore {
    public:
        HighscoreCore()  {};
        ~HighscoreCore() {};

        //! Load the score to this class, call this in the constructor of your GameModule main class
        /*!
            \param filepath the file which contains the score
            \return bool -> true if success / false if fail
        */
        bool loadFromFile(const std::string &filepath) {
            _scores.clear();
            std::vector<std::string> content = readFile(filepath);

            if (!content.size())
                return false;
            for (std::vector<std::string>::iterator it = content.begin(); it != content.end(); it++) {
                std::string line = *it;
                std::vector<std::string> cuttedLine = strtok(line, ":");
                int score = std::stoi(cuttedLine[1]);
                std::pair<std::string, int> formattedLine(cuttedLine[0], score);
                _scores.push_back(formattedLine);
            }
            sortScores();
            return true;
        }
        //! debug fonction, log all files in std::out
        void dump() {
            for (std::vector<std::pair<std::string, int>>::iterator it = _scores.begin();
                 it != _scores.end(); it++) {
                std::pair<std::string, int> item = *it;
                std::cout << item.first << ":" << item.second << std::endl;
            }
        }
        //! Save all stored score in the file (sorted)
        /*!
            \see addscore
            \param filepath the filepath of file to write
            \return success
        */
        bool saveToFile(const std::string &filepath) {
            std::ofstream file;
            
            file.open(filepath);
            if (!file) {
                return false;
            }
            for (std::vector<std::pair<std::string, int>>::iterator it = _scores.begin();
                it != _scores.end(); it++) {
                std::pair<std::string, int> item = *it;
                file << item.first << ":" << item.second << std::endl;
            }
            file.close();
            return true;
        }
        //! Store file in this class
        /*!
            \see saveToFile
            \param playername name of the player logged
            \param score in represent the score of the current ame session
        */
        void addscore(const std::string &playername, int score) {
            std::pair<std::string, int> line(playername, score);
            _scores.push_back(line);
            sortScores();
        }
        //! get the 16 best scores (sorted)
        /*!
            \see loadFromFile
            \return 16 best score
        */
        std::vector<std::pair<std::string, int>> getBestScores() const {
            std::vector<std::pair<std::string, int>> content;

            for (int i = 0; i < _scores.size() && i < 16; i++) {
                content.push_back(_scores[i]);
            }
            return (content);
        }

    protected:
        std::vector<std::string> strtok(std::string const &s, std::string const &token) {
            std::string sc = s;
            char *scstr = strdup(sc.c_str());
            char *column = std::strtok(scstr, token.c_str());
            std::vector<std::string> tokenized;

            while (column != NULL) {
                tokenized.push_back(std::string(column));
                column = std::strtok(NULL, token.c_str());
            }
            return (tokenized);
        }
        std::vector<std::string> readFile(std::string const &filename) {
            std::ifstream file;
            std::string line;
            std::vector<std::string> content;

            file.open(filename);
            if (!file) {
                _onError = true;
                return content;
            }
            while (std::getline(file, line)) {
                if (line == "")
                    continue;
                content.push_back(line);
            }
            file.close();
            return (content);
        }
        void sortScores() {
            std::sort(_scores.begin(), _scores.end(), 
                [](std::pair<std::string, int> &a, std::pair<std::string, int> &b) {
                    return (a.second > b.second);
                });
        }

    bool _onError = false;
    std::vector<std::pair<std::string, int>> _scores;
};

#endif /* F4FB2965_6ED0_4287_B72E_244E007AFBF8 */
