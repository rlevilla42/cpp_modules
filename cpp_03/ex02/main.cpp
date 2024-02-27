#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define GREEN(w) "\033[92m" << w << "\033[0m"

int	main(void)
{

	ClapTrap a("Alice");
	ClapTrap b("Bobby");
	ClapTrap c("Cindy");

	std::cout << std::endl;

	a.takeDamage(4);
	a.beRepaired(3);
	a.beRepaired(5);
	a.beRepaired(8);

	std::cout << std::endl;

	b.takeDamage(91);
	b.beRepaired(41);

	std::cout << std::endl;


	c.attack("Gregg");
	c.attack("Georgina");
	c.attack("Galia");
	c.attack("Gleb");

	std::cout << std::endl;

	a = c;

	std::cout << std::endl;

	ScavTrap s("Savyy");

	s.attack("Billy");
	s.beRepaired(12);
	s.takeDamage(2);
	s.guardGate();

	std::cout << std::endl;

	ScavTrap z = s;

	std::cout << std::endl;

	std::cout << GREEN(">>> THE NEW FRAGTRAP <<<") << std::endl << std::endl;

	FragTrap f("Filly");

	f.attack("Hans");
	f.takeDamage(42);
	f.highFivesGuys();
	f.beRepaired(64);

	std::cout << std::endl;

	return(0);
}