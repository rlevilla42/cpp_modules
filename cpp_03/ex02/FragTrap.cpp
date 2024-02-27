#include "FragTrap.hpp"

/************** constructor *************/

FragTrap::FragTrap(void): ClapTrap::ClapTrap("Deafult FragTrap") {
    std::cout << "FragTrap " << _name << " by default constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    return;
};

FragTrap::FragTrap(std::string name): ClapTrap::ClapTrap(name) {
    std::cout << "FragTrap " << _name << " constructor by name called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    return;
};

FragTrap::FragTrap(FragTrap const &src): ClapTrap::ClapTrap(src) {
    std::cout << "FragTrap " << _name << " constructor by copy called" << std::endl;
    *this = src;
    return;
};

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap " << _name << " destructor called" << std::endl;
    return;
};

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
    std::cout << "FragTrap " << _name << " Copy assignment called " << std::endl;
    ClapTrap::operator=(rhs);
    return(*this);
};

/************** function *************/

std::ostream &operator<<(std::ostream &o, FragTrap const &i) {
    //o << i.get();
    return o;
};

void FragTrap::highFivesGuys(void) {
    std::cout << "Hey guys i have no friend, let's high five hehehe please :')))" << std::endl;
    return;
};