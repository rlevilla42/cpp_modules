#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

int	main(void)
{
	std::cout << "hello office!" << std::endl;

	std::cout << "instansing invalid grades" << std::endl << "<" << std::endl;
	try
	{
		Bureaucrat f("first", 0);
		std::cout << "badly instansed " << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat f("second", 151);
		std::cout << "badly instansed: " << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat f("third", 31);
	std::cout << ">" << std::endl
	<< "correctly instatiated bureucrate: " << f << std::endl;
	return(0);
}