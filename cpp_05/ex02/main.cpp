#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	a("Wilson", 30);
	Bureaucrat	b("Patoche", 75);
	Form		form_a;
	Form		form_cool("Dev web", 78, 77);

	std::cout << "\n" << a << "\n" << form_a << std::endl;

	try
	{
		a.signForm(form_a);
		form_a.beSigned(a);
		std::cout << form_a << std::endl;
		a.signForm(form_a);
		std::cout << "\n" << b << "\n" << form_cool << std::endl;
		b.signForm(form_cool);
		//std::cout << form_cool << std::endl;
		form_cool.beSigned(b);
		std::cout << form_cool << std::endl;
		b.signForm(form_cool);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}
	std::cout << "\n"<<std::endl;
}