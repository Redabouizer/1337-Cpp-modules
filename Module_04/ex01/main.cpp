#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main()
{
	{
    	const Animal* j = new Dog();
    	const Animal* i = new Cat();

    	std::cout << "******" << std::endl;

    	delete j;//should not create a leak
    	delete i;

    	std::cout << "******" << std::endl;

	}
	{
		Animal	*array[100];
		int		i = 0;

		while (i < 50)
			array[i++] = new Dog();
		while (i < 100)
			array[i++] = new Cat();

    	std::cout << "******" << std::endl;

		array[4]->makeSound();
		array[72]->makeSound();

    	std::cout << "******" << std::endl;
    
		for (i = 0; i < 100; i++)
        	delete array[i];
	}
	return 0;
}