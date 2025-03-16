#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal {
	protected:
		std::string	type;
	public:
		virtual ~Animal(void);

		virtual Animal&		operator=(const Animal& other) = 0;
		const std::string&	getType(void) const;
		void				setType(const std::string& type);
		virtual void		makeSound(void) const = 0;
		virtual Brain		*getBrain(void) const = 0;
};
