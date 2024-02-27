#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	//  ===SCAVS===
	std::cout <<"\n\033[34m--scav-t aa---\033[0m" << std::endl;
	ScavTrap aa;
	/*aa.attack("Gilbert");
	aa.takeDamage(60);
	aa.beRepaired(1);*/

	std::cout <<"\n\033[34m--scav-t bb---\033[0m" << std::endl;
	ScavTrap bb(aa);
	bb.attack("Patriccio");
	bb.takeDamage(29);
	bb.takeDamage(12);
	bb.attack("Tomb shrimp");
	bb.beRepaired(1);

	std::cout <<"\n\033[34m--clap-t cc---\033[0m" << std::endl;
	ScavTrap cc("Bojack");
	cc.guardGate();
	cc.attack("Michelangelo");
	cc.takeDamage(1);
	cc.beRepaired(1);

	std::cout <<"\n\033[34m--clap-t dd---\033[0m" << std::endl;
	ClapTrap*	dd_p;
	ScavTrap dd("Pointed");
	dd_p = &dd;
	dd_p->takeDamage(50);
	dd_p->takeDamage(50);
	std::cout << "\t DESTRUCTORS" << std::endl;
	return (0);
}