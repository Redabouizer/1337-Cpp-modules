#pragma once

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class ICharacter;

class AMateria {
	protected:
		std::string	type;
	public:
		AMateria(const std::string& type);
		virtual ~AMateria(void);

		virtual const std::string&	getType(void) const;
		virtual AMateria*			clone() const = 0;
		virtual void				use(ICharacter& target) = 0;
};