#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
private:
    std::string _target;
protected:
    virtual void executeAction() const;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &o);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &o);
    virtual ~RobotomyRequestForm();
};

#endif
