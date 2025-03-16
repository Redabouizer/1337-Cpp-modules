#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int     main()
{
	ClapTrap reda("reda");
	ScavTrap spirit("Spirit");

	std::cout << std::endl;

	reda.attack("Spirit"); // working with ClapTrap's attack here!
	spirit.takeDamage(5);
	spirit.guardGate();
	spirit.attack("reda"); // working with ScavTrap's attack here!
	reda.takeDamage(20);
	reda.takeDamage(20);

	std::cout << std::endl;

	return 0;
}