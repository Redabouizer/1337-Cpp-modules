#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain	*brain;
	public:
		Dog(void);
		Dog(const Dog& other);
		~Dog();

		Dog&	operator=(const Dog& other);
		Animal&	operator=(const Animal& other);
		void	makeSound(void) const;
		Brain	*getBrain(void) const;
};
