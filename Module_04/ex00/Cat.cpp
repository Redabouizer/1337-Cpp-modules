#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
        std::cout << "Default constructor of " << this->type << std::endl;
}

Cat::Cat(const Cat&) : Animal("Cat")
{
        std::cout << "Copy-Constructor of " << this->type << std::endl;
}

Cat::~Cat(void)
{
        std::cout << this->type << " has been destroyed" << std::endl;
}

void    Cat::makeSound(void) const
{
        std::cout << "* Meow! *" << std::endl;
}

