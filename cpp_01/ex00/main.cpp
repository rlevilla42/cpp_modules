#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie* z1 = newZombie("Le jeune loup");
	z1->announce();
	randomChump("Francis Ngannou");
	delete z1;
	return(0);
}