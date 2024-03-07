#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{


	try
	{
		Bureaucrat              a("Trump", 5);
		Bureaucrat              b("Macron", 150);
    	ShrubberyCreationForm   a_shrub("Capibara");
    	RobotomyRequestForm     a_robot("Wapiti");
    	PresidentialPardonForm  a_presid("Lama");
		std::cout << "\n" 
                << a << "\n"
                << a_shrub << "\n"
                << a_robot << "\n"
                << a_presid << "\n"<< std::endl;
		a.signForm(a_shrub);
        a.executeForm(a_shrub);
		a_shrub.beSigned(a);
		a.signForm(a_shrub);
		std::cout << std::endl;

		/********** TEST 1 *********/

		/*** change form ****/

		a.signForm(a_robot);
        a.executeForm(a_robot);
		a_robot.beSigned(a);
		a.signForm(a_robot);
		std::cout << std::endl;

		/*** change form ****/

		a.signForm(a_presid);
        a.executeForm(a_presid);
		a_presid.beSigned(a);
		a.signForm(a_presid);
		std::cout << std::endl;

		/********** TEST 2 **************/

		b.signForm(a_shrub);
        b.executeForm(a_shrub);
		a_shrub.beSigned(b);
		b.signForm(a_shrub);
		std::cout << std::endl;

		/*** change form ****/

		b.signForm(a_robot);
        b.executeForm(a_robot);
		a_robot.beSigned(b);
		b.signForm(a_robot);
		std::cout << std::endl;

		/*** change form ****/

		b.signForm(a_presid);
        b.executeForm(a_presid);
		a_presid.beSigned(b);
		b.signForm(a_presid);
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}
	std::cout << std::endl;
}