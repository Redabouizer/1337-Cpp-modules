#pragma once

#include <iostream>
#include <string>

class ClapTrap {
private:
	std::string	name;
	int			Hit_points;
	int			Energy_points;
	int			Attack_damage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap	&operator=(const ClapTrap &other);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};