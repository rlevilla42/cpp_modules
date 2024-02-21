#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
public:
    // default constructor
    Fixed(void);

    // constructor by copy
    Fixed(Fixed const &src);

    //destructor
    ~Fixed(void);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    // copy assignment operator
    Fixed &operator=(Fixed const &rhs);
private:
    int              _n;
    static const int _rawBits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);
#endif