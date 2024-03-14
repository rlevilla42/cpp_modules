#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>

template <typename T>
class Array {
public:
    Array(void);
    Array(unsigned int n);
    Array(Array const &src);
    ~Array(void);

    T              *getArray(void);
    unsigned int size(void) const;
    Array<T> &operator=(Array const &rhs);
    T      &operator[](unsigned int n_pos);

    class OutOfBounds: public std::exception {
        const char* what() const throw();
    };
private:
    T           *_array;
    unsigned int _size;
};

//std::ostream &operator<<(std::ostream &o, Array const &i);

/******** Constructor *************/

template <typename T>
Array<T>::Array(void) {
    //this->_array = new T[];
    this->_array = NULL;
    this->_size = 0;
};

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n) {};

template <typename T>
Array<T>::Array(Array<T> const &src) {
    std::cout << "Copy constructor called (array)" << std::endl;
    *this = src;
    return ;
};

template <typename T>
Array<T>::~Array(void) {
    if (this->size() > 0)
        delete[] this->_array;
    std::cout << "Destructor called (array)" << std::endl;
	return ;
};

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs) {
    std::cout << "OPERATOR BY ASSIGNMENT called" << std::endl;
    if (&rhs != this) {
        if (!this->_array || this->size() > 0)
            delete[] this->_array;
        this->_size = rhs.size();
        this->_array = new T[this->_size];
        for (int i = 0; i < rhs.size(); i++) {
            this->_array[i] = rhs._array[i];
        }
    }
    return (*this);
};

template <typename T>
T   &Array<T>::operator[](unsigned int n_pos) {
    if (n_pos > (this->size() - 1)) {
        std::cerr << "Trying to access index: " << n_pos << " in array of size: " << size() << std::endl;
        throw (OutOfBounds());
    }
    return this->_array[n_pos];
};

/******** function *************/
template <typename T>
const char* Array<T>::OutOfBounds::what() const throw() {
    return "Out Of Bounds aka SEGFAULT in C++98 LANGUAGE hehehe ;p";
};

template <typename T>
T   *Array<T>::getArray(void) {
    return this->_array;
};

template <typename T>
unsigned int Array<T>::size() const {
    return this->_size;
};

#endif