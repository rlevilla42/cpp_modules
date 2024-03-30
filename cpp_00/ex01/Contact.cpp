#include "header.hpp"

void	Contact::create(void) {
	std::string	user_input;
	while (user_input.empty())
	{
		std::cout << "first name: " << std::flush;
		std::getline(std::cin, user_input);
		//std::cin >> user_input;
		if (user_input.empty())
		{
			std::cout << "please fill information, do net let it empty" << std::endl;
		}
	}
	this->firstName = user_input;
	user_input = "";
	while (user_input.empty())
	{
		std::cout << "lastName: ";
		std::getline(std::cin, user_input);
		if (user_input.empty())
			std::cout << "please fill information, do net let it empty" << std::endl;
	}
	this->lastName = user_input;
	user_input = "";
	while (user_input.empty())
	{
		std::cout << "nickName: ";
		std::getline(std::cin, user_input);
		if (user_input.empty())
			std::cout << "please fill information, do net let it empty" << std::endl;
	}
	this->nickName = user_input;
	user_input = "";
	while (user_input.empty())
	{
		std::cout << "phoneNumber: ";
		std::getline(std::cin, user_input);
		if (user_input.empty())
			std::cout << "please fill information, do net let it empty" << std::endl;
	}
	this->phoneNumber = user_input;
	user_input = "";
	while (user_input.empty())
	{
		std::cout << "darkestSecret: ";
		std::getline(std::cin, user_input);
		if (user_input.empty())
			std::cout << "please fill information, do net let it empty" << std::endl;
	}
	this->darkestSecret = user_input;
	return;
}

std::string Contact::getFirstName() {return this->firstName;}; 
std::string Contact::getLastName() {return this->lastName;};
std::string Contact::getNickName() {return this->nickName;};
std::string Contact::getPhoneNumber () {return this->phoneNumber;};
std::string Contact::getDarkestSecret() {return this->darkestSecret;};