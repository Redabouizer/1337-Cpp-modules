#pragma once

# include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon	&weapon;
public:
	HumanA();
	HumanA(std::string _name, Weapon &weapon);
    ~HumanA();
	void	attack();
};
