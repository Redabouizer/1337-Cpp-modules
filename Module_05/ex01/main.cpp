#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat high("High", 1);
    Bureaucrat mid("Mid", 75);
    Bureaucrat low("Low", 150);

    Form tax("TaxForm", 50, 100);
    Form vacation("Vacation", 140, 120);

    std::cout << tax << std::endl;
    std::cout << vacation << std::endl;

    high.signForm(tax);      // success
    mid.signForm(tax);       // already signed
    low.signForm(tax);       // too low

    low.signForm(vacation);  // success
    mid.signForm(vacation);  // already signed

    try { Form bad("Bad", 0, 10); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try { Form bad2("Bad2", 10, 151); } catch (std::exception &e) { std::cout << e.what() << std::endl; }

    std::cout << tax << std::endl;
    std::cout << vacation << std::endl;
}
