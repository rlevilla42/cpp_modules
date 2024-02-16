#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int	main(void)
{
	int	N = 15;
	int	i = 0;
	Zombie	*arrayZombie = zombieHorde(N, "Conor mcgregor");

	while (i < N)
	{
		std::cout << "Numero " << i << ": " << std::flush;
		arrayZombie[i].announce();
		i++;
	}
	delete [] arrayZombie;
	return (0);
};