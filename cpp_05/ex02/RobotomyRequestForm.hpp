#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include <stdexcept>
#include <cstdlib>

class RobotomyRequestForm: public AForm {
public:
RobotomyRequestForm(void);
RobotomyRequestForm(std::string &target);
RobotomyRequestForm(RobotomyRequestForm const &src);
~RobotomyRequestForm(void);

void    execute(Bureaucrat const &executor) const;
    class CheckSignStatus: public std::exception {
        public:
            const char* what() const throw();
    };
    class GradeTooLowToExec: public std::exception {
        public:
            const char* what() const throw();
    };
RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
private:
    std::string _target;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i);
#endif