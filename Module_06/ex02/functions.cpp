#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	// Seed random number generator
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(0));
		seeded = true;
	}
	
	int random = std::rand() % 3;
	
	switch (random)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	// Try to dynamic_cast to each type
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	// Since we can't use pointers, we use try/catch with dynamic_cast on references
	// dynamic_cast on references throws std::bad_cast if it fails
	
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a; // Suppress unused variable warning
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception&) {}
	
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b; // Suppress unused variable warning
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception&) {}
	
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c; // Suppress unused variable warning
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception&) {}
	
	std::cout << "Unknown type" << std::endl;
}