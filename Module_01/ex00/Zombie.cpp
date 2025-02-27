#include "Zombie.hpp"

Zombie::Zombie()
{
	
}

Zombie::Zombie( std::string Name )
{
	this->name = Name;
}

Zombie::~Zombie()
{
	std::cout << "Destructure called for : " << this->name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
