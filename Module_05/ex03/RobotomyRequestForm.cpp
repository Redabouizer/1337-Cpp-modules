#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest",72,45), _target("default") { std::srand(std::time(NULL)); }
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequest",72,45), _target(target) { std::srand(std::time(NULL)); }
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &o) : AForm(o), _target(o._target) {}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &o) { if (this!=&o) _target=o._target; return *this; }
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {
    std::cout << "* Drilling noises *" << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy failed." << std::endl;
}
