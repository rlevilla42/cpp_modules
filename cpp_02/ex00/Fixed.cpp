#include "Fixed.hpp"

Fixed::Fixed(void): _n(0) {
    std::cout << "Default constructor called" << std::endl;
    return;
};

Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called" << std::endl;
    (*this = src);
    return;
};

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
};

Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_n = rhs.getRawBits();
    }
    return(*this);
};

int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_n);
};
void    Fixed::setRawBits(int const raw) {
    this->_n = raw;
    return;
};
const int Fixed::_rawBits = 8;
std::ostream &operator<<(std::ostream &o, Fixed const &i) {
    return o;
};