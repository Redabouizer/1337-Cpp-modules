#include "FragTrap.hpp"

FragTrap::FragTrap () : ClapTrap() {
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap (std::string name) : ClapTrap(name) {
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << "FragTrap " << this->name << " Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.name)
{
	this->name = other.name;
	this->Hit_points = other.Hit_points;
	this->Energy_points = other.Energy_points;
	this->Attack_damage = other.Attack_damage;
	std::cout << "FragTrap " << this-> name << " Copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->Hit_points = other.Hit_points;
		this->Energy_points = other.Energy_points;
		this->Attack_damage = other.Attack_damage;
	}
	std::cout << "FragTrap " << this-> name << " Copy assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this-> name << " Destructor called" << std::endl;
}

// 			######################################################

void	FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " requests a high five." << std::endl;
}