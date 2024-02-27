#include "ClapTrap.hpp"

/************** constructor *************/

ClapTrap::ClapTrap(void) {
    std::cout << " ClapTrap Constructor by default called" << std::endl;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    this->_name = "Mister INCONNU -_-";
};

ClapTrap::ClapTrap(std::string name) {
    std::cout << "ClapTrap Constructor named has been called" << std::endl;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    this->_name = name;
    return;
};

ClapTrap::ClapTrap(ClapTrap const &src) {
    std::cout << "ClapTrap Constructor by copy called" << std::endl;
    *this = src;
    return;
};

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap Destructor has been called" << std::endl;
    return;
};

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
    std::cout << "ClapTrap Copy assignment called" << std::endl;
    if (this == &rhs)
    {
        return (*this);
    }
    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
    return(*this);
};

/************** function *************/

void ClapTrap::attack(const std::string& target) {
    if (target.empty())
    {
        std::cout << "ClapTrap " << this->_name << " attacks MISTER NAMELESS and causing " << this->_attackDamage << " points of damage" << std::endl;
    }
    else {
        std::cout << "ClapTrap " << this->_name << " attacks " << target
        << " and causing " << this->_attackDamage << " points of damage" << std::endl;
    }
    return;
};

void ClapTrap::takeDamage(unsigned int amount) {
    this->_attackDamage = amount;
    if (this->_hitPoints > this->_attackDamage)
    {
        this->_hitPoints -= this->_attackDamage;
    }
    else {
        this->_hitPoints = 0;
    }
    std::cout << this->_name << " takes " << amount << " points of damage" << ", he's only now got "
    << this->_hitPoints << " hit points" << std::endl;
    return;
};

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints > 0)
    {
        this->_energyPoints--;
    }
    else {
        this->_energyPoints = 0;
    }
    this->_hitPoints += amount;
    std::cout << "ClapTrap is being repaired. It lost 1 point of energy point but gain "
    << amount << " point(s) of hitpoint. He's now " << this->_hitPoints << " hit points hehe ;p"
    << std::endl;
    return;
};

void    ClapTrap::show_points(void) {
    std::cout << "For now, here's " << this->_name << " status:" << std::endl;
    std::cout << "name: " << this->_name << std::endl;
    std::cout << "hitPoints: " << this->_hitPoints << std::endl;
    std::cout << "energyPoints: " << this->_energyPoints << std::endl;
    std::cout << "attackDamage: " << this->_attackDamage << std::endl << std::endl;
};

std::ostream &operator<<(std::ostream &o, ClapTrap const &i) {/*o << i.get();*/ return o;};