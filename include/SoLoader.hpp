/*
** EPITECH PROJECT, 2020
** Alexandre Wagner - Guillian Gangster - Thomas bastien
** File description:
** class Load library
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <dlfcn.h>
#include <string>
#include <memory>
#include <iostream>
#include <exception>
#include "Error.hpp"

template <typename T>
class SoLoader {
    public:
        SoLoader(std::string const &path) {
            this->_path = path;
            this->_handle = dlopen(this->_path.c_str(), RTLD_NOW | RTLD_GLOBAL);

            if (this->_handle == NULL) {
                throw LibraryError(dlerror());
            }
        }
        ~SoLoader() {
            dlclose(this->_handle);
        }

        std::unique_ptr<T> getInstance(std::string const &sig) {
            std::unique_ptr<T> (*func)();
            func = reinterpret_cast<std::unique_ptr<T> (*)()>(dlsym(this->_handle, sig.c_str()));
            
            if (func == NULL)
                return NULL;
            return func();
        }

    private:
        std::string _path;
        void *_handle;
};

#endif /* !DLLOADER_HPP_ */
