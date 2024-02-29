#include "Dog.hpp"
//#include "Animal.hpp"

/************** constructor *************/

Dog::Dog(void): Animal::Animal() {
    this->type = "Dog";
    return;
};

Dog::Dog(Dog const &src) {*this = src; return;};

Dog::~Dog(void) {return;};

Dog &Dog::operator=(Dog const &rhs) {
    this->type = rhs.type;
    return(*this);
};

/************** function *************/

std::ostream &operator<<(std::ostream &o, Dog const &i) {return o;};
std::string    Dog::getType(void) const {return this->type;};
void    Dog::makeSound(void) const {std::cout << "WOAF WOAF !!" << std::endl;};