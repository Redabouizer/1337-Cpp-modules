#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) { if (grade < 1) throw GradeTooHighException(); if (grade > 150) throw GradeTooLowException(); }
Bureaucrat::Bureaucrat(const Bureaucrat &o) : _name(o._name), _grade(o._grade) {}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &o) { if (this!=&o) _grade=o._grade; return *this; }
Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() { if (_grade - 1 < 1) throw GradeTooHighException(); --_grade; }
void Bureaucrat::decrementGrade() { if (_grade + 1 > 150) throw GradeTooLowException(); ++_grade; }

void Bureaucrat::signForm(AForm &f) { try { f.beSigned(*this); std::cout << _name << " signed " << f.getName() << std::endl; } catch (std::exception &e) { std::cout << _name << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl; } }
void Bureaucrat::executeForm(AForm const &form) const { try { form.execute(*this); std::cout << _name << " executed " << form.getName() << std::endl; } catch (std::exception &e) { std::cout << _name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl; } }

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Bureaucrat grade too high"; }
const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Bureaucrat grade too low"; }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) { os << b.getName() << ", bureaucrat grade " << b.getGrade(); return os; }
