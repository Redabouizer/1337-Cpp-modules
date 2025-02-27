#include "Zombie.hpp"

Zombie* Zombie::newZombie( std::string name )
{
	Zombie *z;
    
    z = (Zombie *) new (std::nothrow) Zombie ( name );
	if (!z)
	{
		std::cerr << "Memory allocation failed" << std::endl;
		return NULL;
	}
    z->announce();
	return (z);
}
