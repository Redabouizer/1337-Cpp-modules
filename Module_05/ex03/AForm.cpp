#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}
AForm::AForm(const std::string &name, int gSign, int gExec) : _name(name), _isSigned(false), _gradeToSign(gSign), _gradeToExecute(gExec) { if (gSign < 1 || gExec < 1) throw GradeTooHighException(); if (gSign > 150 || gExec > 150) throw GradeTooLowException(); }
AForm::AForm(const AForm &o) : _name(o._name), _isSigned(o._isSigned), _gradeToSign(o._gradeToSign), _gradeToExecute(o._gradeToExecute) {}
AForm &AForm::operator=(const AForm &o) { if (this!=&o) _isSigned=o._isSigned; return *this; }
AForm::~AForm() {}

const std::string &AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat &b) { if (b.getGrade() > _gradeToSign) throw GradeTooLowException(); _isSigned = true; }
void AForm::execute(Bureaucrat const &executor) const { if (!_isSigned) throw NotSignedException(); if (executor.getGrade() > _gradeToExecute) throw GradeTooLowException(); executeAction(); }

const char *AForm::GradeTooHighException::what() const throw() { return "Form grade too high"; }
const char *AForm::GradeTooLowException::what() const throw() { return "Form grade too low"; }
const char *AForm::NotSignedException::what() const throw() { return "Form not signed"; }

std::ostream &operator<<(std::ostream &os, const AForm &f) { os << "Form '" << f.getName() << "', signed: " << (f.isSigned()?"yes":"no") << ", grade to sign: " << f.getGradeToSign() << ", grade to execute: " << f.getGradeToExecute(); return os; }
