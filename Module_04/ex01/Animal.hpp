#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal {
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(const std::string& type);
		Animal(const Animal& other);
		virtual ~Animal(void);

		virtual Animal&				operator=(const Animal& other);
		const std::string&	getType(void) const;
		void				setType(const std::string& type);
		virtual void		makeSound(void) const;
		virtual Brain		*getBrain(void) const = 0;
};
