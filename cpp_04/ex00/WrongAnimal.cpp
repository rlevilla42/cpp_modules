#include "WrongAnimal.hpp"
/************** constructor *************/

WrongAnimal::WrongAnimal(void) {
    this->type = "WrongAnimal";
    return;
};

WrongAnimal::WrongAnimal(WrongAnimal const &src) {*this = src; return;};

WrongAnimal::~WrongAnimal(void) {return;};

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {
    this->type = rhs.type;
    return(*this);
};

/************** function *************/

std::ostream &operator<<(std::ostream &o, WrongAnimal const &i) {return o;};

std::string    WrongAnimal::getType(void) const {return this->type;};
void    WrongAnimal::makeSound(void) const {std::cout << "WrongAnimal XXXX" << std::endl;};