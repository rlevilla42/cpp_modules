#include "Form.hpp"
#include "Bureaucrat.hpp"

/************** constructor *************/

Form::Form(void):_name("test"), _gradeToSign(150), _gradeToExec(150),_signed(false) {return;};

Form::Form(std::string name, int gradeToSign, int gradeToExec): _name(name),
    _gradeToSign(gradeToSign),
    _gradeToExec(gradeToExec),
    _signed(false)
{
    return;
};

Form::Form(Form const &src) : _name(src.getName()),
    _gradeToSign(src.getGradeToSign()),
    _gradeToExec(src.getGradeToExec()),
    _signed(src.getSignedStatus())
{
    if (_gradeToSign < 1 || _gradeToExec < 1) {
        throw GradeTooHighException();
    }
    if (_gradeToSign > 150 || _gradeToExec > 150) {
        throw GradeTooLowException();
    }
    return;
};

Form::~Form(void) {return;};

Form &Form::operator=(Form const &rhs) {
    if (this != &rhs)
    {
        return(*this);
    }
    return (*this);
};

/************** function *************/

void    Form::beSigned(Bureaucrat const &b) {
    if (b.getGrade() > this->_gradeToSign) {
        throw GradeTooLowException();
    }
    else {
        this->_signed = true;
    }
    return;
};

std::string Form::getName(void) const{
    return this->_name;
};

int Form::getGradeToSign(void) const{
    return this->_gradeToSign;
};

int Form::getGradeToExec(void) const{
    return this->_gradeToExec;
};

bool Form::getSignedStatus(void) const{
    return this->_signed;
};

const char* Form::GradeTooHighException::what() const throw() {return "Grade is too high to sign the form papi chullo";};
const char* Form::GradeTooLowException::what() const throw() {return "Grade is too low to sign the form papi chullo";};
std::ostream &operator<<(std::ostream &o, Form const &i) {
    o << "Form:" << std::endl
    << "name = " << i.getName() << std::endl
    << "gradeToSign = " << i.getGradeToSign() << std::endl
    << "gradeToExec = " << i.getGradeToExec() << std::endl
    << "getSignedStatus = " << (i.getSignedStatus() ? "true" : "false");
    return o;
};