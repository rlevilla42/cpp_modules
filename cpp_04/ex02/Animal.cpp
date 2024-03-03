#include "Animal.hpp"

/************** constructor *************/

Animal::Animal(void) {
    std::cout << "Animal constructor DEFAULT called" << std::endl;
    this->type = "Animal";
    return;
};

Animal::Animal(Animal const &src) {
    std::cout << "Animal constructor by copy called" << std::endl;
    *this = src;
    return;
};

Animal::~Animal(void) {
    std::cout << "Animal destructor called" << std::endl;
    return;
};

Animal &Animal::operator=(Animal const &rhs) {
    std::cout << "Animal assignment by copy" << std::endl;
    this->type = rhs.type;
    return(*this);
};

/************** function *************/

std::ostream &operator<<(std::ostream &o, Animal const &i) {return o;};

std::string    Animal::getType(void) const {return this->type;};
//void    Animal::makeSound(void) const {std::cout << "Animal sound XXXX" << std::endl;};