#include "ScavTrap.hpp"

int main() {
    ScavTrap s("Serena");
    s.attack("an intruder");
    s.guardGate();
    s.takeDamage(40);
    s.beRepaired(10);
    for (int i = 0; i < 55; ++i) s.attack("dummy");
    return 0;
}
