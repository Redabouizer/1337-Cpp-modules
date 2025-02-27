#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name) {
	int		i = -1;
	Zombie	*horde = new Zombie[n];

	while (++i < n) {
		horde[i].setName(name);
		horde[i].announce();
	}
	return (horde);
}