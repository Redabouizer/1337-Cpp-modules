#include "Zombie.hpp"

int	main() {
	Zombie	*horde = zombieHorde(5, "Frank");
    if (!horde)
		return 1;
	delete[] horde;
	return 0;
}