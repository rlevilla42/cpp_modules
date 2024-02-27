#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap {
public:
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const &src);
    ClapTrap(void);
    ~ClapTrap(void);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void show_points(void);

    ClapTrap &operator=(ClapTrap const &rhs);
protected:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;
};

std::ostream &operator<<(std::ostream &o, ClapTrap const &i);
#endif