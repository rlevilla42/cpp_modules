#include "Animal.hpp"

/************** constructor *************/

Animal::Animal(void) {
    this->type = "Animal";
    return;
};

Animal::Animal(Animal const &src) {*this = src; return;};

Animal::~Animal(void) {return;};

Animal &Animal::operator=(Animal const &rhs) {
    this->type = rhs.type;
    return(*this);
};

/************** function *************/

std::ostream &operator<<(std::ostream &o, Animal const &i) {return o;};

std::string    Animal::getType(void) const {return this->type;};
void    Animal::makeSound(void) const {std::cout << "Animal sound XXXX" << std::endl;};