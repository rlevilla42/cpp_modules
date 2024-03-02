#include "Cat.hpp"
//#include "Animal.hpp"

/************** constructor *************/

Cat::Cat(void): Animal::Animal() {
    std::cout << "Cat constructor by default" << std::endl;
    this->_brain = new Brain;
    this->type = "Cat";
    return;
};

Cat::Cat(Cat const &src): Animal::Animal(src) {
    std::cout << "Cat constructor by copy" << std::endl;
    this->_brain = new Brain;
    *this = src;
    return;
};

Cat::~Cat(void) {
    std::cout << "Cat DEStructor" << std::endl;
    delete this->_brain;
    return;
};

Cat &Cat::operator=(Cat const &rhs) {
    std::cout << "Cat assignment by copy" << std::endl;
    Animal::operator=(rhs);
    *this->_brain = *rhs._brain;
    return(*this);
};

/************** function *************/

std::ostream    &operator<<(std::ostream &o, Cat const &i) {return o;};
std::string     Cat::getType(void) const {return this->type;};
void            Cat::makeSound(void) const {std::cout << "MIAOU MIAOU zehbinemouk" << std::endl;return;};

void	Cat::addIdea(std::string idea)
{
	this->_brain->addIdea(idea);
}
void	Cat::printIdeas(void)	const
{
	for	(int i = 0; i < 99 ; i++)
		std::cout << this->_brain->getIdea(i) << ";" << std::flush;
	std::cout << this->_brain->getIdea(99) << std::endl;
}