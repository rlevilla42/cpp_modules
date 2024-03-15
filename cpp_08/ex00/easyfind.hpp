#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <exception>
#include <algorithm>

class notFoundIteratorException: public std::exception {
    const char *what() const throw() {
        return "There's no double value papi chulo";
    };
};

template <typename T>
typename T::const_iterator  easyfind(T &var, int value) {
    typename T::const_iterator  it = var.begin();
    typename T::const_iterator  ite = var.end();
    typename T::const_iterator  found_iterator = std::find(it, ite, value);
    if (found_iterator == var.end()) {
        throw notFoundIteratorException();
    }
    return found_iterator;
};
#endif