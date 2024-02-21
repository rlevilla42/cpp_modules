#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
public:
    // default constructor
    Fixed(void);

    // constructor by copy
    Fixed(Fixed const &src);

    Fixed(const int &n);
    Fixed(const float &nf);

    //destructor
    ~Fixed(void);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int   toInt(void) const;
    
    // copy assignment operator
    Fixed &operator=(Fixed const &rhs);
private:
    int              _n;
    static const int _rawBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);
#endif