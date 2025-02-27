#include "Zombie.hpp"

int main()
{
	Zombie *zem = NULL;

	zem = zem->newZombie("Heap-Zombie");
	if (!zem)
		return 1;
	zem->randomChump("Stack-Zombie");
    delete zem;
}
