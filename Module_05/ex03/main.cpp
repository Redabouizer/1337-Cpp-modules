#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm *f1 = someRandomIntern.makeForm("shrubbery creation", "garden");
    AForm *f2 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm *f3 = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    AForm *fBad = someRandomIntern.makeForm("time travel", "Doc");

    Bureaucrat boss("Boss", 1);

    if (f1) { boss.signForm(*f1); boss.executeForm(*f1); }
    if (f2) { boss.signForm(*f2); boss.executeForm(*f2); }
    if (f3) { boss.signForm(*f3); boss.executeForm(*f3); }

    delete f1;
    delete f2;
    delete f3;
    delete fBad; // NULL safe
    return 0;
}
