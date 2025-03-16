#include "ClapTrap.hpp"

ClapTrap::ClapTrap () : name("name"),
						Hit_points(10),
						Energy_points(10),
						Attack_damage(0) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap (std::string name) : name(name),
										Hit_points(10),
										Energy_points(10),
										Attack_damage(0) {
	std::cout << "ClapTrap " << this-> name << " Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name),
											Hit_points(other.Hit_points),
											Energy_points(other.Energy_points),
											Attack_damage(other.Attack_damage)
{
	std::cout << "ClapTrap " << this-> name << " Copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		Hit_points = other.Hit_points;
		Energy_points = other.Energy_points;
		Attack_damage = other.Attack_damage;
	}
	std::cout << "ClapTrap " << this-> name << " Copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this-> name << " Destructor called" << std::endl;
}

// 			######################################################

void	ClapTrap::attack(const std::string& target)
{
	if (Hit_points <= 0 || Energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->name << " Can't attack!" << std::endl;
		return ;
	}
	this->Energy_points--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;

}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (Hit_points <= 0 || Energy_points <= 0)
	{
		std::cout << this->name << " Can't take more damage, enough!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " with " << Hit_points << " health points took " << amount << " of damage!" << std::endl;
	Hit_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (Hit_points <= 0 || Energy_points <= 0)
	{
		std::cout << this->name << " Can't repaire itself!" << std::endl;
		return ;
	}
	this->Energy_points--;
	Hit_points += amount;
	std::cout << "ClapTrap " << this->name << " repairs itself with " << amount << " points. My HitPoints: " << \
	this->Hit_points << ", And my EnergyPoints: " << this->Energy_points << std::endl;
}