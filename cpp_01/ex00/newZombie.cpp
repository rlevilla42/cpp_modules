#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie	*z1 = new Zombie(name);
	return z1;
};