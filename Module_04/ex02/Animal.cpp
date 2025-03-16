#include "Animal.hpp"

Animal::~Animal(void)
{
	std::cout << "Destructor of Animal" << std::endl;
}

const std::string&	Animal::getType(void) const
{
	return (this->type);
}

void				Animal::setType(const std::string& type)
{
	this->type = type;
}
