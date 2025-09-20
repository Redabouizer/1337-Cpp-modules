#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Testing type identification ===" << std::endl;
	std::cout << std::endl;
	
	// Test with randomly generated objects
	std::cout << "Testing with randomly generated objects:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base* obj = generate();
		if (obj)
		{
			std::cout << "Object " << (i + 1) << " - ";
			std::cout << "Pointer identification: ";
			identify(obj);
			std::cout << "Reference identification: ";
			identify(*obj);
			std::cout << std::endl;
			
			delete obj;
		}
	}
	
	std::cout << std::endl;
	
	// Test with known objects
	std::cout << "Testing with known objects:" << std::endl;
	
	A a;
	B b;
	C c;
	
	std::cout << "A object - Pointer: ";
	identify(&a);
	std::cout << "A object - Reference: ";
	identify(a);
	
	std::cout << "B object - Pointer: ";
	identify(&b);
	std::cout << "B object - Reference: ";
	identify(b);
	
	std::cout << "C object - Pointer: ";
	identify(&c);
	std::cout << "C object - Reference: ";
	identify(c);
	
	return 0;
}