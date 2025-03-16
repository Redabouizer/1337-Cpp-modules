#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain	*brain;
	public:
		Cat(void);
		Cat(const Cat& other);
		~Cat();

		Cat&	operator=(const Cat& other);
		Animal&	operator=(const Animal& other);
		void	makeSound(void) const;
		Brain	*getBrain(void) const;
};

