
#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : type(type) {}

AMateria::~AMateria(void) {}

const std::string&	AMateria::getType(void) const
{
	return (this->type);
}
