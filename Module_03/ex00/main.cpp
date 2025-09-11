#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Alpha");
    ClapTrap b("Beta");

    a.attack("Beta");
    b.takeDamage(0); // attackDamage is 0 by default
    b.beRepaired(5);

    for (int i = 0; i < 11; ++i)
        a.attack("some target");

    a.beRepaired(3);
    return 0;
}
