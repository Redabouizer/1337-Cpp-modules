#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), name("default") {
    // Adjust stats according to spec
    hitPoints = FragTrap::hitPoints;     // 100 from FragTrap
    energyPoints = ScavTrap::energyPoints; // 50 from ScavTrap
    attackDamage = FragTrap::attackDamage; // 30 from FragTrap
    ClapTrap::name = name + "_clap_name";
    std::cout << "[DiamondTrap] default ctor: " << name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &n) : ClapTrap(n + "_clap_name"), ScavTrap(n), FragTrap(n), name(n) {
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    ClapTrap::name = n + "_clap_name";
    std::cout << "[DiamondTrap] ctor: " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
    std::cout << "[DiamondTrap] copy ctor: " << name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        name = other.name;
    }
    std::cout << "[DiamondTrap] copy assign: " << name << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "[DiamondTrap] dtor: " << name << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "[DiamondTrap] name: " << name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target); // use ScavTrap version
}
