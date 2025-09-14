#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;
protected:
    virtual void executeAction() const;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &o);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &o);
    virtual ~ShrubberyCreationForm();
};

#endif
