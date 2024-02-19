#include "Harl.hpp"

Harl::Harl(void){};
Harl::~Harl(void){};

void    Harl::debug(void)
{
    std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
    return;
}

void    Harl::info(void)
{
    std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    return;
}

void    Harl::warning(void)
{
    std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    return;
}

void    Harl::error(void)
{
    std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now." << std::endl;
    return;
}

void    Harl::complain(std::string level)
{
    int			i = 0;
	void (Harl::*function[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	str[4] = {"debug", "info", "warning", "error"};

	while (i < 4 && level != str[i])
		i++;
	/*if (i != 4)
		(this->*function[i])();
	else
		std::cout << "Not good input" << std::endl;*/
    switch (i)
	{
		case 0:
			(this->*function[0])();
		case 1:
			(this->*function[1])();
		case 2:
			(this->*function[2])();
		case 3:
			(this->*function[3])();
			break;
		default:
			std::cout << "Not good input" << std::endl;
	}
    return;
}