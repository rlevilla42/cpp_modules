#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	int	i = 0;
	Zombie	*new_zombie = new Zombie[N];
	while (i < N)
	{
		new_zombie[i].setName(name);
		i++;
	}
	return new_zombie;
};