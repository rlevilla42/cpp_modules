#include "ClapTrap.hpp"

int	main(void)
{
	std::cout <<"--cp-t a---" << std::endl;
	ClapTrap a;
	a.attack("Montagnier");
	a.takeDamage(6);
	a.beRepaired(1);
	
	std::cout <<"--cp-t b---" << std::endl;
	ClapTrap b(a);
	b.attack("Gilbert");
	b.takeDamage(1);
	b.takeDamage(4);
	b.attack("Tomb shrimp");
	b.beRepaired(1);

	std::cout <<"--cp-t c---" << std::endl;
	ClapTrap c("Link");
	c.attack("Gilbert");
	c.takeDamage(1);
	c.beRepaired(1);

	std::cout << "\t DESTRUCTORS" << std::endl;
}