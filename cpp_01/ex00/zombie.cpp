#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "constructor has been called" << std::endl;
	return;
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