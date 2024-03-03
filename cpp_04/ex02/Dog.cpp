#include "Dog.hpp"
//#include "Animal.hpp"

/************** constructor *************/

Dog::Dog(void): Animal::Animal() {
    std::cout << "Dog constructor by default" << std::endl;
    this->_brain = new Brain;
    this->type = "Dog";
    return;
};

Dog::Dog(Dog const &src): Animal::Animal(src) {
    std::cout << "Dog constructor by copy" << std::endl;
    this->_brain = new Brain;
    *this = src;
    return;
};

Dog::~Dog(void) {
    std::cout << "Dog DEStructor" << std::endl;
    delete this->_brain;
    return;
};

Dog &Dog::operator=(Dog const &rhs) {
    std::cout << "Dog assignment by copy" << std::endl;
    Animal::operator=(rhs);
    *this->_brain = *rhs._brain;
    return(*this);
};

/************** function *************/

std::ostream &operator<<(std::ostream &o, Dog const &i) {return o;};
std::string    Dog::getType(void) const {return this->type;};
void    Dog::makeSound(void) const {std::cout << "WOAF WOAF !!" << std::endl;};

void	Dog::addIdea(std::string idea)
{
	this->_brain->addIdea(idea);
}

void	Dog::printIdeas(void)	const
{
	for	(int i = 0; i < 99 ; i++)
		std::cout << this->_brain->getIdea(i) << ";" << std::flush;
	std::cout << this->_brain->getIdea(99) << std::endl;
}