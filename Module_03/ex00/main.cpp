#include "ClapTrap.hpp"

int     main()
{
	ClapTrap A("reda");
	ClapTrap B("Spirit");

	std::cout << std::endl;

	A.attack("Spirit");
	B.takeDamage(5);
	B.beRepaired(4);

	std::cout << std::endl;

	B.attack("reda");
	A.takeDamage(10);
	A.takeDamage(9);
	A.attack("Spirit");

	std::cout << std::endl;

	return 0;
}