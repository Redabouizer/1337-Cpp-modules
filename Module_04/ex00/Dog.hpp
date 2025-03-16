#pragma once

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		Dog(const Dog&);
		~Dog();

		using	Animal::operator=;
		void	makeSound(void) const;
};
