#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    Bureaucrat boss("Boss", 1);
    Bureaucrat exec("Exec", 20);
    Bureaucrat low("Low", 140);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    boss.signForm(shrub);
    low.signForm(robo); // fail
    boss.signForm(robo);
    exec.signForm(pardon); // fail (needs 25)
    boss.signForm(pardon);

    boss.executeForm(shrub);
    boss.executeForm(robo);
    exec.executeForm(pardon); // fail execute needs 5
    boss.executeForm(pardon);

    return 0;
}
