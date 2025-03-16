#include "DiamondTrap.hpp"

int main(void)
{
    ClapTrap claptrap("clap");
	std::cout << "**************" << std::endl;
	ScavTrap scavtrap("scav");
	std::cout << "**************" << std::endl;
	FragTrap fragtrap("frag");
	std::cout << "**************" << std::endl;
	DiamondTrap diamondtrap("diamond");

	std::cout << "\n**************\n**************\n" << std::endl;

	claptrap.attack("Enemy1");
	claptrap.takeDamage(15);
	claptrap.beRepaired(9);
	std::cout << "**************" << std::endl;
	scavtrap.attack("Enemy2");
	scavtrap.takeDamage(14);
	scavtrap.guardGate();
	std::cout << "**************" << std::endl;
	fragtrap.attack("Enemy3");
	fragtrap.takeDamage(11);
	fragtrap.highFivesGuys();
	std::cout << "**************" << std::endl;
	diamondtrap.whoAmI();
	diamondtrap.guardGate();
	diamondtrap.attack("Enemy4");
	diamondtrap.highFivesGuys();
	diamondtrap.beRepaired(10);


	std::cout << "\n**************\n**************\n" << std::endl;


    return 0;
}