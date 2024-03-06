#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
/************** constructor *************/

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm::AForm("Default Shrubbery Form", 145, 137) {
    this->_target = "Default_target_value_snif :'(";
    return;
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target): AForm::AForm("Shrubbery Form", 145, 137) {
    this->_target = target;
    return;
};


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): AForm::AForm(src)
{
    if (this != &src)
    {
        this->_target = src._target;
        *this = src;
    }
    return;
};

ShrubberyCreationForm::~ShrubberyCreationForm(void) {return;};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return(*this);
};

/************** EXECEPTION *************/

const char* ShrubberyCreationForm::CheckSignStatus::what() const throw() {
    return ("The form is not signed !");
};

const char* ShrubberyCreationForm::GradeTooLowToExec::what() const throw() {
    return ("EXECUTOR grade is too low");
};

/************** function *************/

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeToExec())
    {
        throw ShrubberyCreationForm::GradeTooLowToExec();
    } else if (!this->getSignedStatus()) {
        throw ShrubberyCreationForm::CheckSignStatus();
    }
    std::ofstream file;
    file.open(this->_target + "_shrubbery");
    file << "              * *" << std::endl
		<< "           *    *  *" << std::endl
		<< "      *  *    *     *  *" << std::endl
		<< "     *     *    *  *    *" << std::endl
		<< " * *   *    *    *    *   *" << std::endl
		<< " *     *  *    * * .#  *   *" << std::endl
		<< " *   *     * #.  .# *   *" << std::endl
		<< "  *      #.  #: #  * *    *" << std::endl
		<< " *   * *  #. ##        *" << std::endl
		<< "   *        ###" << std::endl
		<< "              ##" << std::endl
		<< "              ##." << std::endl
		<< "              .##:" << std::endl
		<< "              :###" << std::endl
		<< "              ;###" << std::endl
		<< "            ,####." << std::endl
		<< "/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\" << std::endl;
        file.close();
        return;
};

//std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i) {o << i.get();return o;};