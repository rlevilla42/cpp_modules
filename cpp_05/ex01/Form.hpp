#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
public:
    Form(void);
    Form(std::string name, int gradeToSign, int gradeToExec);
    Form(Form const &src);
    ~Form(void);

    Form &operator=(Form const &rhs);
    std::string getName(void) const;
    int         getGradeToSign(void) const;
    int         getGradeToExec(void) const;
    bool        getSignedStatus(void) const;
    void        beSigned(Bureaucrat const &b);
    class GradeTooHighException: public std::exception {const char *what() const throw();};
    class GradeTooLowException: public std::exception {const char *what() const throw();};
    
private:
    std::string const _name;
    int         const _gradeToSign;
    int         const _gradeToExec;
    bool              _signed;
};

std::ostream &operator<<(std::ostream &o, Form const &i);
#endif