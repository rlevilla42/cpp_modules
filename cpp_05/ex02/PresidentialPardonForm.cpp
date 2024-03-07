#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <fstream>
/************** constructor *************/

PresidentialPardonForm::PresidentialPardonForm(void): AForm::AForm("Default PresidentialPardon Form", 25, 5) {
    this->_target = "Default_target_value_snif :'(";
    return;
};

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm::AForm("PresidentialPardon Form", 25, 5) {
    this->_target = target;
    return;
};


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src): AForm::AForm(src)
{
    if (this != &src)
    {
        this->_target = src._target;
        *this = src;
    }
    return;
};

PresidentialPardonForm::~PresidentialPardonForm(void) {return;};

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return(*this);
};

/************** EXECEPTION *************/

const char* PresidentialPardonForm::CheckSignStatus::what() const throw() {
    return ("The form is not signed !");
};

const char* PresidentialPardonForm::GradeTooLowToExec::what() const throw() {
    return ("EXECUTOR grade is too low to execute the PresidentialPardon Form");
};

/************** function *************/
std::string    PresidentialPardonForm::getTarget(void) const {
    return this->_target;
};

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeToExec())
    {
        throw PresidentialPardonForm::GradeTooLowToExec();
    } else if (!this->getSignedStatus()) {
        throw PresidentialPardonForm::CheckSignStatus();
    }
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    return;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i) {
    o << "target: " << i.getTarget() << std::endl
    << "_gradeToSign: " << i.getGradeToSign() << std::endl
    << "_gradeToExec: " << i.getGradeToExec() << std::endl
    << "_signed: " << (i.getSignedStatus() ? "true" : "false") << std::endl;
    return o;
};