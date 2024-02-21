#include "Fixed.hpp"

/************** constructor*************/

// default constructor
Fixed::Fixed(void): _n(0) {
    std::cout << "Default constructor called" << std::endl;
    return;
};

// constructor by copy
Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called" << std::endl;
    (*this = src);
    return;
};

Fixed::Fixed(const int &n) {
    std::cout << "Int constructor called" << std::endl;
    setRawBits(n << _rawBits);
    return;
};

Fixed::Fixed(const float &nf) {
    std::cout << "Float constructor called" << std::endl;
    this->_n = roundf(nf * (1 << Fixed::_rawBits));
    return;
};

//destructor
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
};
/************** functions *************/

// copy assignment operator
Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_n = rhs.getRawBits();
    }
    return(*this);
};

int     Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->_n);
};

void    Fixed::setRawBits(int const raw) {
    this->_n = raw;
    return;
};

float   Fixed::toFloat(void) const {
    return (this->_n / (float)(1 << this->_rawBits));
};

int     Fixed::toInt(void) const {
    return (this->_n >> 8);
};

//const int Fixed::_rawBits = 8;
std::ostream &operator<<(std::ostream &o, Fixed const &i) {
    o << i.toFloat();
    return o;
};