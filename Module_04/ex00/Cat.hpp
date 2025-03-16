#pragma once

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat(void);
		Cat(const Cat&);
		~Cat();

		using   Animal::operator=;
		void    makeSound(void) const;
};

