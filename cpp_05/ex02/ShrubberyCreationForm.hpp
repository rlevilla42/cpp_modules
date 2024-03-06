#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include <stdexcept>

class ShrubberyCreationForm: public AForm {
public:
/******** constructor **********/
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ~ShrubberyCreationForm(void);

/******** EXECEPTION **********/
    void    execute(Bureaucrat const &executor) const;
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