#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"

class Cat: public Animal {
public:
// constructor 

Cat(void);
Cat(Cat const &src);
~Cat(void);

// Public function

std::string    getType(void) const;
void    makeSound(void) const;

Cat &operator=(Cat const &rhs);
private:
};

std::ostream &operator<<(std::ostream &o, Cat const &i);
#endif