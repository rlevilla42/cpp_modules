#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/************** constructor *************/

Intern::Intern(void) {return;};

//Intern::Intern(std::string formObjectName, std::string target) {};

Intern::Intern(Intern const &src) {if (this != &src){*this = src;} return;};

Intern::~Intern(void) {return;};

Intern &Intern::operator=(Intern const &rhs) {return (*this);};

/************** function *************/

static AForm *_ShrubberyCreationForm(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *_RobotomyRequestForm(const std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm *_PresidentialPardonForm(const std::string target)
{
	return new PresidentialPardonForm(target);
}

const char* Intern::FormExist::what() const throw() {
    //std::cout << "Any Form exits with this target name bro" << std::endl;
    return ("Any Form exits with this target name bro");
};

AForm *Intern::makeForm(std::string formObjectName, std::string target) {
    const char* AFormName[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    static AForm *(*func[])(const std::string) = {
		_ShrubberyCreationForm, _RobotomyRequestForm, _PresidentialPardonForm
	};
    for (int i = 0; i < 3; i++) {
        if (AFormName[i] == formObjectName) {
            return func[i](target);
        }
    }
    throw Intern::FormExist();
};
//std::ostream &operator<<(std::ostream &o, Intern const &i) {o << i.get();return o;};