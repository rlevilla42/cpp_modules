#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "constructor has been called" << std::endl;
	return;
};
void	Zombie::setName(std::string name)
{
	this->_name = name;
	return;
};

std::string	Zombie::getName(void) const
{
	return this->_name;
};

Zombie::~Zombie(void)
{
	std::cout << "Destructor " << this->_name << ": " << "has been destroyed" << std::endl;
	return;	
};

void	Zombie::announce(void)
{
	std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
	return;
};