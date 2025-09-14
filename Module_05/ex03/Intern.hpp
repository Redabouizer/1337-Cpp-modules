#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern &o);
    Intern &operator=(const Intern &o);
    ~Intern();

    AForm *makeForm(const std::string &formName, const std::string &target) const;

    class UnknownFormException : public std::exception { public: virtual const char *what() const throw(); };
};

#endif
