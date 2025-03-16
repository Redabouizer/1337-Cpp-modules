#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "Default constructor of " << this->type << std::endl;
}

WrongCat::WrongCat(const WrongCat&) : WrongAnimal("WrongCat")
{
	std::cout << "Copy-Constructor of " << this->type << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << this->type << " has been destroyed" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "* WrongCat Meow *" << std::endl;
}
