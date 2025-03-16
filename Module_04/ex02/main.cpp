#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main() {
	Cat		Gattino;
	Dog		Rex;

	std::cout << Gattino.getType() << " " << std::endl;
	std::cout << Rex.getType() << " " << std::endl;

	Rex.makeSound();
	Gattino.getBrain();
	Rex.getBrain();

	return 0;
}