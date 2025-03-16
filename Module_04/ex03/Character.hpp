#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string	name;
		AMateria	*inventory[4];
		int			size;
	public:
		Character(const std::string& name);
		Character(const Character& other);
		~Character(void);

		Character&			operator=(const Character& otehr);
		const std::string&	getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};
