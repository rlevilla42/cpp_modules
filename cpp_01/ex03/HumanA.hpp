#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>
#include "Weapon.hpp"

class	HumanA {
    private:
        std::string _name;
        Weapon &_weapon;
    public:
        //std::string weapon;
        HumanA(std::string name, Weapon &w);
        ~HumanA(void);
        void        attack(void);
};

#endif