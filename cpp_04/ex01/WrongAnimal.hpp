#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal {
public:
WrongAnimal(void);
WrongAnimal(WrongAnimal const &src);
~WrongAnimal(void);
std::string    getType(void) const;

WrongAnimal &operator=(WrongAnimal const &rhs);
void makeSound(void) const;
protected:
    std::string    type;
};

std::ostream &operator<<(std::ostream &o, WrongAnimal const &i);
#endif