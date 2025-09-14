#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &o) { (void)o; }
Intern &Intern::operator=(const Intern &o) { (void)o; return *this; }
Intern::~Intern() {}

static AForm *makeShrub(const std::string &t) { return new ShrubberyCreationForm(t); }
static AForm *makeRobo(const std::string &t) { return new RobotomyRequestForm(t); }
static AForm *makePardon(const std::string &t) { return new PresidentialPardonForm(t); }

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
    const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*funcs[3])(const std::string &) = { &makeShrub, &makeRobo, &makePardon };
    for (int i = 0; i < 3; ++i) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return funcs[i](target);
        }
    }
    std::cout << "Intern cannot find form: " << formName << std::endl;
    return NULL;
}

const char *Intern::UnknownFormException::what() const throw() { return "Intern: unknown form"; }
