#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}
Form::Form(const std::string &name, int gSign, int gExec)
    : _name(name), _isSigned(false), _gradeToSign(gSign), _gradeToExecute(gExec) {
    if (gSign < 1 || gExec < 1) throw GradeTooHighException();
    if (gSign > 150 || gExec > 150) throw GradeTooLowException();
}
Form::Form(const Form &o)
    : _name(o._name), _isSigned(o._isSigned), _gradeToSign(o._gradeToSign), _gradeToExecute(o._gradeToExecute) {}
Form &Form::operator=(const Form &o) { if (this!=&o) _isSigned = o._isSigned; return *this; }
Form::~Form() {}

const std::string &Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() { return "Form grade too high"; }
const char *Form::GradeTooLowException::what() const throw() { return "Form grade too low"; }

std::ostream &operator<<(std::ostream &os, const Form &f) {
    os << "Form '" << f.getName() << "', signed: " << (f.isSigned()?"yes":"no")
       << ", grade to sign: " << f.getGradeToSign() << ", grade to execute: " << f.getGradeToExecute();
    return os;
}
