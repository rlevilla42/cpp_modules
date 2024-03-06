#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <fstream>
/************** constructor *************/

RobotomyRequestForm::RobotomyRequestForm(void): AForm::AForm("Default Robotomy Form", 72, 45) {
    this->_target = "Default_target_value_snif :'(";
    return;
};

RobotomyRequestForm::RobotomyRequestForm(std::string &target): AForm::AForm("Robotomy Form", 72, 45) {
    this->_target = target;
    return;
};


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): AForm::AForm(src)
{
    if (this != &src)
    {
        this->_target = src._target;
        *this = src;
    }
    return;
};

RobotomyRequestForm::~RobotomyRequestForm(void) {return;};

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return(*this);
};

/************** EXECEPTION *************/

const char* RobotomyRequestForm::CheckSignStatus::what() const throw() {
    return ("The form is not signed !");
};

const char* RobotomyRequestForm::GradeTooLowToExec::what() const throw() {
    return ("EXECUTOR grade is too low to execute the Robotomy Form");
};

/************** function *************/

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeToExec())
    {
        throw RobotomyRequestForm::GradeTooLowToExec();
    } else if (!this->getSignedStatus()) {
        throw RobotomyRequestForm::CheckSignStatus();
    }
    std::srand((unsigned) time(NULL));
    if ((std::rand() % (100 + 1)) < 50)
    {
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    }
    else {
        std::cout << "The robotomy failed *dead* *dead* *dead* (satante rasengan...)" << std::endl;
    }
    return;
};

//std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i) {o << i.get();return o;};