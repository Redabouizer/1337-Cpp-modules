#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* _cat = new Cat();
		const Animal* _dog = new Dog();

		std::cout << "******" << std::endl;

		std::cout << _cat->getType() << " " << std::endl;
		std::cout << _dog->getType() << " " << std::endl;
		
		std::cout << "******" << std::endl;
		meta->makeSound();
		_cat->makeSound();
		_dog->makeSound();
		std::cout << "******" << std::endl;

		delete meta;
		delete _cat;
		delete _dog;
	}

	std::cout << "*******************************" << std::endl;
    
	{
		WrongAnimal* meta = new WrongAnimal();
		WrongAnimal* _cat = new WrongCat();

		std::cout << "******" << std::endl;
		meta->makeSound();
		_cat->makeSound();
		std::cout << "******" << std::endl;

		delete meta;
		delete _cat;
	}
	return 0;
}