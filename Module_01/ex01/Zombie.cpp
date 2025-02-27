#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Be careful ! a new zombie her" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "A zombie died!" << std::endl;
}

void	Zombie::setName( std::string Name )
{
	this->name = Name;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}