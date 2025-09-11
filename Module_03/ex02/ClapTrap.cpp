#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "[ClapTrap] default ctor: " << name << std::endl;
}

ClapTrap::ClapTrap(const std::string &n): name(n), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "[ClapTrap] ctor: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "[ClapTrap] copy ctor: " << name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "[ClapTrap] copy assign: " << name << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "[ClapTrap] dtor: " << name << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (energyPoints <= 0 || hitPoints <= 0) {
        std::cout << "[ClapTrap] " << name << " cannot attack." << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "[ClapTrap] " << name << " attacks " << target << " causing " << attackDamage << " damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints <= 0) {
        std::cout << "[ClapTrap] " << name << " already destroyed." << std::endl;
        return;
    }
    hitPoints -= amount;
    if (hitPoints < 0) hitPoints = 0;
    std::cout << "[ClapTrap] " << name << " takes " << amount << " damage, HP=" << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints <= 0 || hitPoints <= 0) {
        std::cout << "[ClapTrap] " << name << " cannot repair." << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "[ClapTrap] " << name << " repairs " << amount << " HP, HP=" << hitPoints << std::endl;
}
