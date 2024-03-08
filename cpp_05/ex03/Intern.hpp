#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "AForm.hpp"
#include <stdexcept>

class AForm;

class Intern {
public:
    Intern(void);
    Intern(Intern const &src);
    ~Intern(void);

    class FormExist: public std::exception {
            public:
                const char* what() const throw();
        };
    AForm *makeForm(std::string formObjectName, std::string target);
    Intern &operator=(Intern const &rhs);
private:
};

std::ostream &operator<<(std::ostream &o, Intern const &i);
#endif