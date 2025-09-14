#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
protected:
    virtual void executeAction() const = 0;
public:
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &o);
    AForm &operator=(const AForm &o);
    virtual ~AForm();

    const std::string &getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat &b);
    void execute(Bureaucrat const &executor) const;

    class GradeTooHighException : public std::exception { public: virtual const char *what() const throw(); };
    class GradeTooLowException : public std::exception { public: virtual const char *what() const throw(); };
    class NotSignedException : public std::exception { public: virtual const char *what() const throw(); };
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
