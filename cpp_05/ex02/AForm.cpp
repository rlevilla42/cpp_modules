#include "AForm.hpp"
#include "Bureaucrat.hpp"

/************** constructor *************/

AForm::AForm(void):_name("test"), _gradeToSign(150), _gradeToExec(150),_signed(false) {return;};

AForm::AForm(std::string name, int gradeToSign, int gradeToExec): _name(name),
    _gradeToSign(gradeToSign),
    _gradeToExec(gradeToExec),
    _signed(false)
{
    return;
};

AForm::AForm(AForm const &src) : _name(src.getName()),
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

AForm::~AForm(void) {return;};

AForm &AForm::operator=(AForm const &rhs) {
    // do nothing because all these variable are constant i think
    if (this != &rhs)
    {
        this->_signed = rhs.getSignedStatus();
        return(*this);
    }
    return (*this);
};

/************** function *************/

void    AForm::beSigned(Bureaucrat const &b) {
    if (b.getGrade() > this->_gradeToSign) {
        throw GradeTooLowException();
    }
    else {
        this->_signed = true;
    }
    return;
};

std::string AForm::getName(void) const{
    return this->_name;
};

int AForm::getGradeToSign(void) const{
    return this->_gradeToSign;
};

int AForm::getGradeToExec(void) const{
    return this->_gradeToExec;
};

bool AForm::getSignedStatus(void) const{
    return this->_signed;
};

const char* AForm::GradeTooHighException::what() const throw() {return "Grade is too high to sign the AForm papi chullo";};
const char* AForm::GradeTooLowException::what() const throw() {return "Grade is too low to sign the AForm papi chullo";};
std::ostream &operator<<(std::ostream &o, AForm const &i) {
    o << "AForm:" << std::endl
    << "name = " << i.getName() << std::endl
    << "gradeToSign = " << i.getGradeToSign() << std::endl
    << "gradeToExec = " << i.getGradeToExec() << std::endl
    << "getSignedStatus = " << (i.getSignedStatus() ? "true" : "false");
    return o;
};