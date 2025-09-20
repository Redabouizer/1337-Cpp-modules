#include "Zombie.hpp"

int main()
{
	// Create a zombie on the heap
	Zombie* heapZombie = newZombie("Heap-Zombie");
	heapZombie->announce();
	
	// Create a zombie on the stack  
	randomChump("Stack-Zombie");
	
	// Clean up heap zombie
	delete heapZombie;
	
	return 0;
}
