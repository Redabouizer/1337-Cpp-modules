#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat&);
		~WrongCat();

		using   WrongAnimal::operator=;
		void    makeSound(void) const;
};
