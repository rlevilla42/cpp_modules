#include "Bureaucrat.hpp"

/************** constructor *************/

Bureaucrat::Bureaucrat(void) {return;};
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
    if (grade > 150) {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade < 1) {
        throw Bureaucrat::GradeTooLowException();
    }
    else {
        this->_grade = grade;
    }
};

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
    if (this != &src)
    {
        *this = src;
    }
    return;
};

Bureaucrat::~Bureaucrat(void) {return;};

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
    //this->_name = rhs._name;
    std::cerr << "Private variable _name is const so it can't be change sorry" << std::endl;
    //this->_grade = rhs._grade;
    return(*this);
};

/************** function *************/

std::string Bureaucrat::getName(void) const {
    return this->_name;
};

int         Bureaucrat::getGrade(void) const {
    return this->_grade;
};

void Bureaucrat::increaseGrade(void) {
    this->_grade++;
    return;
};
void Bureaucrat::decreaseGrade(void) {
    this->_grade--;
    return;
};

const char* Bureaucrat::GradeTooHighException::what() const throw() {return "Grade is too high hehehe";};

const char* Bureaucrat::GradeTooLowException::what() const throw () {return "Grade is too low hehehe";};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i) {
    o << i.getName() << ", bureaucrat grade " << i.getGrade();
    return o;
};