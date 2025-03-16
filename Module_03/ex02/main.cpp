#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int     main()
{
	ClapTrap reda("reda");
	ScavTrap spirit("spirit");
	FragTrap slow("Slow");

	std::cout << std::endl;

	reda.attack("spirit"); // working with ClapTrap's attack here!
	spirit.guardGate();
	spirit.attack("reda"); // working with ScavTrap's attack here!
	reda.takeDamage(20);

	slow.attack("reda");
	reda.takeDamage(30);
	reda.beRepaired(100);
	slow.highFivesGuys();


	std::cout << std::endl;

	return 0;
}