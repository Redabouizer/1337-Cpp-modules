#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	// Create a Data structure
	Data originalData;
	originalData.id = 42;
	originalData.name = "Test Data";
	originalData.value = 3.14159;
	
	std::cout << "Original Data:" << std::endl;
	std::cout << "Address: " << &originalData << std::endl;
	std::cout << "ID: " << originalData.id << std::endl;
	std::cout << "Name: " << originalData.name << std::endl;
	std::cout << "Value: " << originalData.value << std::endl;
	std::cout << std::endl;
	
	// Serialize the pointer
	uintptr_t serialized = Serializer::serialize(&originalData);
	std::cout << "Serialized value: " << serialized << std::endl;
	std::cout << std::endl;
	
	// Deserialize back to pointer
	Data* deserializedPtr = Serializer::deserialize(serialized);
	
	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "Address: " << deserializedPtr << std::endl;
	std::cout << "ID: " << deserializedPtr->id << std::endl;
	std::cout << "Name: " << deserializedPtr->name << std::endl;
	std::cout << "Value: " << deserializedPtr->value << std::endl;
	std::cout << std::endl;
	
	// Check if pointers are equal
	if (&originalData == deserializedPtr)
	{
		std::cout << "Success! The original pointer and deserialized pointer are equal." << std::endl;
	}
	else
	{
		std::cout << "Error! The pointers are not equal." << std::endl;
	}
	
	return 0;
}