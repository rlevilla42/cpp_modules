#include "Cat.hpp"
//#include "Animal.hpp"

/************** constructor *************/

Cat::Cat(void): Animal::Animal() {
    this->type = "Cat";
    return;
};

Cat::Cat(Cat const &src) {*this = src; return;};

Cat::~Cat(void) {return;};

Cat &Cat::operator=(Cat const &rhs) {return(*this);};

/************** function *************/

std::ostream    &operator<<(std::ostream &o, Cat const &i) {return o;};
std::string     Cat::getType(void) const {return this->type;};
void            Cat::makeSound(void) const {std::cout << "MIAOU MIAOU zehbinemouk" << std::endl;return;};