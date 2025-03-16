#pragma once

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(const std::string& type);
		Animal(const Animal& other);
		virtual ~Animal(void);

		Animal&				operator=(const Animal& other);
		const std::string&	getType(void) const;
		void				setType(const std::string& type);
		virtual void		makeSound(void) const;
};
