/*#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
*/
#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "hello office!" << std::endl;

	Bureaucrat b1("Conor", 140);
	Bureaucrat b2("Kamaru", 89);
	Bureaucrat b3("Ngannou", 42);
	Bureaucrat b4("Baki", 2);

	AForm *f[4];

	Intern intern;

	f[0] = intern.makeForm("robotomy request", "Bender");
	f[1] = intern.makeForm("shrubbery creation", "garden");
	f[2] = intern.makeForm("presidential pardon", "George");

	try
	{
		f[3] = intern.makeForm("made up form", "Sally");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Intern error: " << e.what() << std::endl;
	}

	b1.signForm(*f[0]);
	b3.signForm(*f[0]);
	b4.executeForm(*f[0]);

	for (int i = 0; i < 3; i++) delete f[i];

	return(0);
}