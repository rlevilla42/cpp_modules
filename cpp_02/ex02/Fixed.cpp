#include "Fixed.hpp"

/************** constructor*************/

// default constructor
Fixed::Fixed(void): _n(0) {
    return;
};

// constructor by copy
Fixed::Fixed(Fixed const &src) {
    (*this = src);
    return;
};

Fixed::Fixed(const int &n) {
    setRawBits(n << _rawBits);
    //_n = n << _rawBits;
    return;
};

//Fixed::Fixed(const float &nf) { _n = int(nf * float(1U << _rawBits) + (nf >= 0 ? 0.5 : -0.5));};
Fixed::Fixed(const float &nf) {
    this->_n = roundf(nf * (1 << Fixed::_rawBits));
    return;
};

//destructor
Fixed::~Fixed(void) {return;}


/************** functions *************/

// copy assignment operator
Fixed &Fixed::operator=(Fixed const &rhs) {
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

/****** static function ********/

Fixed &Fixed::min(Fixed &a, Fixed &b) {return (a < b ? a : b);};
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {return (a < b ? a : b);};
Fixed &Fixed::max(Fixed &a, Fixed &b) {return (a > b ? a : b);};
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {return (a > b ? a : b);};

/****** assignment function ********/

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
    o << i.toFloat();
    return o;
};

bool Fixed::operator>(Fixed const &rhs) const {return (this->getRawBits() > rhs.getRawBits() ? true : false);};
bool Fixed::operator<(Fixed const &rhs) const {return (this->getRawBits() < rhs.getRawBits() ? true : false);};
bool Fixed::operator>=(Fixed const &rhs) const {return (_n >= rhs.getRawBits() ? true : false);};
bool Fixed::operator<=(Fixed const &rhs) const {return (_n <= rhs.getRawBits() ? true : false);};
bool Fixed::operator==(Fixed const &rhs) const {return (_n == rhs.getRawBits() ? true : false);};
bool Fixed::operator!=(Fixed const &rhs) const {return (_n != rhs.getRawBits() ? true : false);};

/****** arithmetic function ********/

Fixed Fixed::operator+(Fixed const &rhs) {Fixed tmp; tmp.setRawBits(this->_n + rhs.getRawBits()); return (tmp);};
Fixed Fixed::operator-(Fixed const &rhs) {Fixed tmp; tmp.setRawBits(this->_n - rhs.getRawBits()); return (tmp);};
//Fixed Fixed::operator*(Fixed const &rhs) {Fixed tmp; tmp._n = this->_n * rhs.getRawBits() >> _rawBits; return (tmp);};
Fixed Fixed::operator*(Fixed const &rhs) {Fixed tmp; tmp.setRawBits(this->_n * rhs.getRawBits() >> _rawBits); return (tmp);};
/*Fixed	Fixed::operator*(Fixed const &rhs)
{
	Fixed	tmp;
	tmp.setRawBits(static_cast<int>((static_cast<long int>(this->getRawBits()) * rhs.getRawBits()) >> Fixed::_rawBits));
	return tmp;
}*/
Fixed Fixed::operator/(Fixed const &rhs) {Fixed tmp; tmp.setRawBits(this->_n / rhs.getRawBits() >> _rawBits); return (tmp);};

/****** increment / decrement function ********/

Fixed &Fixed::operator++(void) {this->setRawBits(this->getRawBits() + 1); return *this;};
Fixed &Fixed::operator--(void) {this->setRawBits(this->getRawBits() - 1); return *this;};
Fixed Fixed::operator++(int) { Fixed tmp(*this); this->setRawBits(this->getRawBits() + 1); return tmp;};
//Fixed	Fixed::operator++(int) { Fixed	tmp(*this); this->setRawBits(this->getRawBits() + 1); return tmp;};
Fixed Fixed::operator--(int) { Fixed tmp(*this); this->setRawBits(this->getRawBits() - 1); return tmp;};