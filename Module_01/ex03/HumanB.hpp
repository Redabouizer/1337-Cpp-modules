#pragma once

# include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon		*weapon;
public:
	HumanB();
	HumanB(std::string Name);
    ~HumanB();
	void	setWeapon(Weapon &Wset);
	void	attack( void );
};