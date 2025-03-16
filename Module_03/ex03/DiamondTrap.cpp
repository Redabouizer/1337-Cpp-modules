#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap () : ClapTrap() {
	this->name = "diamond";
	this->Hit_points = FragTrap::Hit_points;
	this->Energy_points = ScavTrap::Energy_points;
	this->Attack_damage = FragTrap::Attack_damage;
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap (std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->name = name;
	this->Hit_points = FragTrap::Hit_points;
	this->Energy_points = ScavTrap::Energy_points;
	this->Attack_damage = FragTrap::Attack_damage;
	std::cout << "DiamondTrap " << this->name << " Parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.name + "_clap_name"), ScavTrap(other.name), FragTrap(other.name)
{
	this->name = other.name;
	this->Hit_points = other.Hit_points;
	this->Energy_points = other.Energy_points;
	this->Attack_damage = other.Attack_damage;
	std::cout << "DiamondTrap " << this-> name << " Copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->Hit_points = other.Hit_points;
		this->Energy_points = other.Energy_points;
		this->Attack_damage = other.Attack_damage;
	}
	std::cout << "DiamondTrap " << this-> name << " Copy assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this-> name << " Destructor called" << std::endl;
}

// 			######################################################

void    DiamondTrap::whoAmI()
{
    std::cout << "call whoAmI from DiamondTrap" << std::endl;
    std::cout << "DiamondTrap: " << this->name << std::endl;
    std::cout << "ClapTrap: " << ClapTrap::name << std::endl;
}