#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) {
    //std::cout << "Constructor has been called" << std::endl;
    this->_name = name;
    this->_weapon = NULL;
    return;
};

HumanB::~HumanB(void) {
    //std::cout << "HumanB detsructor has been called" << std::endl;
    return;
};

void    HumanB::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;
    return;
}

void    HumanB::attack(void) {
    if (this->_weapon == NULL)
    {
        std::cout << this->_name << " cannot attack because he's unarmed !" << std::endl;
    }
    else 
    {
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    }
    return;
};