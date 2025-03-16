#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Default constructor of " << this->type << std::endl;
	this->brain = new Brain;
}

Dog::Dog(const Dog& other) : Animal("Dog")
{
	std::cout << "Copy-Constructor of " << this->type << std::endl;
	*this = other;
}

Dog::~Dog(void)
{
	std::cout << this->type << " has been destroyed" << std::endl;
	delete this->brain;
}

Animal&		Dog::operator=(const Animal& other)
{
	const Dog	*pOther; 

	pOther = dynamic_cast<const Dog*>(&other);
	if(pOther)
	{
		this->type = pOther->type;
		*this->brain = *pOther->brain;
	}

	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "* HawHaw! *" << std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return (this->brain);
}
