#include <iostream>
#include <iomanip>

class	Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(void);
		~Zombie(void);
		void		announce(void);
		void		setName(std::string name);
		std::string	getName(void) const;
};