#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
	protected:
		std::string    type;
	public:
		WrongAnimal(void);
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal(void);

		WrongAnimal&		operator=(const WrongAnimal& other);
		const std::string&	getType(void) const;
		void				setType(const std::string& type);
		void		makeSound(void) const;
};
