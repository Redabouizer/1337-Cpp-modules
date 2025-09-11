#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default_frag") {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "[FragTrap] default ctor: " << name << std::endl;
}

FragTrap::FragTrap(const std::string &n) : ClapTrap(n) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "[FragTrap] ctor: " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "[FragTrap] copy ctor: " << name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    ClapTrap::operator=(other);
    std::cout << "[FragTrap] copy assign: " << name << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "[FragTrap] dtor: " << name << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (energyPoints <= 0 || hitPoints <= 0) {
        std::cout << "[FragTrap] " << name << " cannot attack." << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "[FragTrap] " << name << " blasts " << target << " for " << attackDamage << " damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "[FragTrap] " << name << " requests a high five!" << std::endl;
}
