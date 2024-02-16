#include <iostream>

class Weapon {
private:
	std::string _type;
public:
	Weapon(void);
	~Weapon(void);
	const std::string	&getType(void);
	void				setType(std::string name);
};