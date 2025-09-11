#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default_scav") {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "[ScavTrap] default ctor: " << name << std::endl;
}

ScavTrap::ScavTrap(const std::string &n) : ClapTrap(n) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "[ScavTrap] ctor: " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "[ScavTrap] copy ctor: " << name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    ClapTrap::operator=(other);
    std::cout << "[ScavTrap] copy assign: " << name << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "[ScavTrap] dtor: " << name << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (energyPoints <= 0 || hitPoints <= 0) {
        std::cout << "[ScavTrap] " << name << " cannot attack." << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "[ScavTrap] " << name << " slashes " << target << " for " << attackDamage << " damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "[ScavTrap] " << name << " is now in Gate keeper mode." << std::endl;
}
