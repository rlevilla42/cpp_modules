#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include "AForm.hpp"
class PresidentialPardonForm: public AForm {
public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string &target);
    PresidentialPardonForm(PresidentialPardonForm const &src);
    ~PresidentialPardonForm(void);

    /******** exception *********/

    class CheckSignStatus: public std::exception {
        public:
            const char* what() const throw();
    };
    class GradeTooLowToExec: public std::exception {
        public:
            const char* what() const throw();
    };
    void    execute(Bureaucrat const &executor) const;
    PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
private:
    std::string _target;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i);
#endif