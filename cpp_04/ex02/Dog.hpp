#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
public:
    Dog(void);
    Dog(Dog const &src);
    ~Dog(void);
    std::string    getType(void) const;
    void           makeSound(void) const;
	void	       addIdea(std::string idea);
	void	       printIdeas(void)	const;

    Dog &operator=(Dog const &rhs);
private:
    Brain *_brain;
};

std::ostream &operator<<(std::ostream &o, Dog const &i);
#endif