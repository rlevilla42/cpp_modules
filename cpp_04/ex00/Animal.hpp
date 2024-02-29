#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal {
public:
    Animal(void);
    Animal(Animal const &src);
    ~Animal(void);
    std::string    getType(void) const;
    virtual void    makeSound(void) const;

Animal &operator=(Animal const &rhs);
protected:
    std::string    type;
};

std::ostream &operator<<(std::ostream &o, Animal const &i);
#endif