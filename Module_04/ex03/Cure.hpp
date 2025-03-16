#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure(void);
		Cure(const Cure& other);
		~Cure(void);

		Cure&            operator=(const Cure& other);
		AMateria*       clone() const;
		void            use(ICharacter& target);
};
