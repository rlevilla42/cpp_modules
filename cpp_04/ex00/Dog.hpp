#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"

class Dog: public Animal {
public:
Dog(void);
Dog(Dog const &src);
~Dog(void);
std::string    getType(void) const;
void    makeSound(void) const;

Dog &operator=(Dog const &rhs);
//private:
};

std::ostream &operator<<(std::ostream &o, Dog const &i);
#endif