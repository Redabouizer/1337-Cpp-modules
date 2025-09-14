#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
        // This will throw
        a.incrementGrade();
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bob", 149);
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
        b.decrementGrade(); // throws
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat c("Bad", 0); // constructor throws
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat d("Bad2", 151); // constructor throws
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}
