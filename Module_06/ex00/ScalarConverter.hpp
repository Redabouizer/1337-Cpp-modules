#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include <climits>

class ScalarConverter
{
private:
	// Make constructor, destructor, copy constructor and assignment operator private
	// to prevent instantiation
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	// Helper methods for type detection and conversion
	static bool isChar(const std::string& literal);
	static bool isInt(const std::string& literal);
	static bool isFloat(const std::string& literal);
	static bool isDouble(const std::string& literal);
	static bool isSpecial(const std::string& literal);
	
	static void convertFromChar(char c);
	static void convertFromInt(int value);
	static void convertFromFloat(float value);
	static void convertFromDouble(double value);
	static void handleSpecial(const std::string& literal);

public:
	static void convert(const std::string& literal);
};

#endif