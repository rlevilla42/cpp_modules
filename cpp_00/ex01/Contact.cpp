#include "header.hpp"

void	Contact::create(void) {
	std::string	user_input;
	while (user_input.empty())
	{
		std::cout << "name: ";
		std::getline(std::cin, user_input);
		if (user_input.empty())
			std::cout << "please fill information, do net let it empty" << std::endl;
	}
	this->_name = user_input;
	user_input = "";
	while (user_input.empty())
	{
		std::cout << "lastName: ";
		std::getline(std::cin, user_input);
		if (user_input.empty())
			std::cout << "please fill information, do net let it empty" << std::endl;
	}
	this->_lastName = user_input;
	user_input = "";
	while (user_input.empty())
	{
		std::cout << "nickName: ";
		std::getline(std::cin, user_input);
		if (user_input.empty())
			std::cout << "please fill information, do net let it empty" << std::endl;
	}
	this->_nickName = user_input;
	user_input = "";
	while (user_input.empty())
	{
		std::cout << "phoneNumber: ";
		std::getline(std::cin, user_input);
		if (user_input.empty())
			std::cout << "please fill information, do net let it empty" << std::endl;
	}
	this->_phoneNumber = user_input;
	user_input = "";
	while (user_input.empty())
	{
		std::cout << "darkestSecret: ";
		std::getline(std::cin, user_input);
		if (user_input.empty())
			std::cout << "please fill information, do net let it empty" << std::endl;
	}
	this->_darkestSecret = user_input;
}