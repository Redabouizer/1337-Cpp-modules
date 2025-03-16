#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria("cure")
{
	*this = other;
}

Cure::~Cure(void) {}

Cure&    Cure::operator=(const Cure& other)
{
	this->type = other.type;
	return (*this);
}

AMateria*       Cure::clone() const
{
	return (new Cure(*this));
}

void            Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
                        
