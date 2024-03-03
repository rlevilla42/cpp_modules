#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
public:
WrongCat(void);
WrongCat(WrongCat const &src);
~WrongCat(void);

WrongCat &operator=(WrongCat const &rhs);
std::string    getType(void) const;
void    makeSound(void) const;
private:
};

std::ostream &operator<<(std::ostream &o, WrongCat const &i);
#endif