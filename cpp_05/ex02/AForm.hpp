#ifndef AForm_HPP
#define AForm_HPP
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
public:
    AForm(void);
    AForm(std::string name, int gradeToSign, int gradeToExec);
    AForm(AForm const &src);
    ~AForm(void);

    AForm &operator=(AForm const &rhs);
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

std::ostream &operator<<(std::ostream &o, AForm const &i);
#endif