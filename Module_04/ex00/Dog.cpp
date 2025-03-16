#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Default constructor of " << this->type << std::endl;
}

Dog::Dog(const Dog&) : Animal("Dog")
{
	std::cout << "Copy-Constructor of " << this->type << std::endl;
}

Dog::~Dog(void)
{
	std::cout << this->type << " has been destroyed" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "* HawHaw! *" << std::endl;
}
