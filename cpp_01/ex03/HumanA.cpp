#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w): _weapon(w) {
    //std::cout << "Constructor has been called" << std::endl;
    this->_name = name;
    //this->_weapon = w;
    return;
};

HumanA::~HumanA(void) {
    //std::cout << "Destructor HUmanA has been called" << std::endl;
    return;
};

void    HumanA::attack(void) {
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
    return;
};