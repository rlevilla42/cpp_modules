#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <stdexcept>

class Bureaucrat {
public:
    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &src);
    ~Bureaucrat(void);
    std::string getName(void) const;
    int         getGrade(void) const;
    //void        setGrade(int grade);
    void         increaseGrade(void);
    void         decreaseGrade(void);
    class GradeTooHighException: public std::exception {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {
        const char* what() const throw();
    };

    Bureaucrat &operator=(Bureaucrat const &rhs);
private:
    std::string const _name;
    int               _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);
#endif