#include <iostream>
#include <iomanip>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "The memory address of string: " << &string << std::endl;
	std::cout << "The memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address of stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "The value of string: " << string << std::endl;
	std::cout << "The value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value of stringREF: " << stringREF << std::endl;
	return (0);
};