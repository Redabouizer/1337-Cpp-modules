# Module 05 – Bureaucracy & Exceptions (C++98)

Exercises recap:

ex00: Bureaucrat class with grade bounds (1..150), increment/decrement, exceptions, operator<<.
ex01: Form class added, signing logic, Bureaucrat::signForm.
ex02: Abstract AForm + three concrete forms (Shrubbery, Robotomy, Presidential Pardon) with execute(), Bureaucrat::executeForm.
ex03: Intern capable of creating forms by name (factory pattern with array of function pointers).

Build (from inside each exercise directory):
make

Run:
./bureaucrat
./forms
./forms2
./intern

All code follows: -std=c++98 -Wall -Wextra -Werror.
No STL containers beyond basics, no using namespace std.

Tree form produced by ShrubberyCreationForm writes to <target>_shrubbery file.
Robotomy is 50% success. Presidential Pardon prints the required message.

Intern supports names:
- "shrubbery creation"
- "robotomy request"
- "presidential pardon"

Unknown form returns NULL after message.
