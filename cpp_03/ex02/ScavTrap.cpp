#include "ScavTrap.hpp"

/************** constructor *************/

ScavTrap::ScavTrap(void):ClapTrap::ClapTrap("Default Scav") {
    std::cout << "ScavTrap \"" << _name << "\" by default constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    return;
};

ScavTrap::ScavTrap(std::string name):ClapTrap::ClapTrap(name) {
    std::cout << "ScavTrap \"" << _name << "\" constructor by name called " << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    return;
};

ScavTrap::ScavTrap(ScavTrap const &src): ClapTrap::ClapTrap(src) {
    std::cout << "ScavTrap \"" << _name << "\" constructor by copy called " << std::endl;
    *this = src;
    return;
};

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap \"" << _name << "\" destructor called " << std::endl;
    return;
};

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
    std::cout << "ScavTrap \"" << _name << "\" Copy assignment called " << std::endl;
    ClapTrap::operator=(rhs);
    return(*this);
};

/************** function *************/

std::ostream &operator<<(std::ostream &o, ScavTrap const &i) {
    // o << i.get();
    return o;
};

void    ScavTrap::attack(const std::string &target) {
    if (target.empty())
    {
        std::cout << "ScavTrap " << _name << " attacks MISTER NAMELESS and causing " << _attackDamage << " points of damage" << std::endl;
    }
    else {
        std::cout << "ScavTrap " << _name << " attacks " << target
        << " and causing " << _attackDamage << " points of damage" << std::endl;
    }
    return;
};
void    ScavTrap::guardGate(void){
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
    return;
};