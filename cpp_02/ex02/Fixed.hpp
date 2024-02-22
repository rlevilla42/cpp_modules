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
    /****** static function ********/
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    
    /****** assignment function ********/

    Fixed &operator=(Fixed const &rhs);

    // comparaison

    bool operator>(Fixed const &rhs) const;
    bool operator<(Fixed const &rhs) const;
    bool operator>=(Fixed const &rhs) const;
    bool operator<=(Fixed const &rhs) const;
    bool operator==(Fixed const &rhs) const;
    bool operator!=(Fixed const &rhs) const;

    // arithmetique

    Fixed operator+(Fixed const &rhs);
    Fixed operator-(Fixed const &rhs);
    Fixed operator*(Fixed const &rhs);
    Fixed operator/(Fixed const &rhs);

    // increment / decrement

    Fixed &operator++(void);
    Fixed &operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);
private:
    int              _n;
    static const int _rawBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);
#endif