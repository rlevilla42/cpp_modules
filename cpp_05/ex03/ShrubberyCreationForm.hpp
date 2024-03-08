#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include <stdexcept>

class ShrubberyCreationForm: public AForm {
public:
/******** constructor **********/
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ~ShrubberyCreationForm(void);

    std::string    getTarget(void) const;
    void    execute(Bureaucrat const &executor) const;

    /******** EXECEPTION **********/

    class CheckSignStatus: public std::exception {
        public:
            const char* what() const throw();
    };
    /*class GradeTooHighToExec: public std::exception {
        public:
            const char* what() const throw();
    };*/
    class GradeTooLowToExec: public std::exception {
        public:
            const char* what() const throw();
    };

    /********* operator ********/
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
private:
    std::string _target;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i);
#endif