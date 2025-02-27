#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string _name, Weapon &weapon) : name(_name), weapon(weapon) {
}

HumanA::~HumanA() {
	
}

void	HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}