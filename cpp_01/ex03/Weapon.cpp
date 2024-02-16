#include "Weapon.hpp"

Weapon::Weapon(void){};
Weapon::~Weapon(void){};

void	Weapon::setType(std::string name) {
	this->_type = name;
	return;
};

const	std::string &Weapon::getType(void) {
	if (this->_type.empty())
	{
		std::cout << "Set _type before call the getters." << std::endl;
		//return(0);
	}
	return (this->_type);
};