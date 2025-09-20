#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

// Private constructor to prevent instantiation
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal)
{
	return (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]));
}

bool ScalarConverter::isInt(const std::string& literal)
{
	if (literal.empty())
		return false;
	
	size_t start = 0;
	if (literal[0] == '+' || literal[0] == '-')
		start = 1;
	
	if (start >= literal.length())
		return false;
		
	for (size_t i = start; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]))
			return false;
	}
	
	// Check for int overflow
	std::stringstream ss(literal);
	long long value;
	ss >> value;
	
	return (value >= INT_MIN && value <= INT_MAX);
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	if (literal.empty() || literal.back() != 'f')
		return false;
	
	std::string num = literal.substr(0, literal.length() - 1);
	if (num.empty())
		return false;
	
	size_t start = 0;
	if (num[0] == '+' || num[0] == '-')
		start = 1;
	
	bool hasDot = false;
	for (size_t i = start; i < num.length(); i++)
	{
		if (num[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(num[i]))
			return false;
	}
	
	return true;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	if (literal.empty())
		return false;
	
	size_t start = 0;
	if (literal[0] == '+' || literal[0] == '-')
		start = 1;
	
	bool hasDot = false;
	for (size_t i = start; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
	}
	
	return true;
}

bool ScalarConverter::isSpecial(const std::string& literal)
{
	return (literal == "nan" || literal == "nanf" || 
			literal == "+inf" || literal == "+inff" || 
			literal == "-inf" || literal == "-inff" ||
			literal == "inf" || literal == "inff");
}

void ScalarConverter::convertFromChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertFromInt(int value)
{
	// char conversion
	if (value >= 0 && value <= 127)
	{
		if (std::isprint(value))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromFloat(float value)
{
	// char conversion
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<int>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	
	// int conversion
	if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	
	std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromDouble(double value)
{
	// char conversion
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<int>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	
	// int conversion
	if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	
	// float conversion
	if (std::isnan(value) || std::isinf(value))
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::handleSpecial(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& literal)
{
	if (literal.empty())
	{
		std::cout << "Error: empty literal" << std::endl;
		return;
	}
	
	if (isSpecial(literal))
	{
		handleSpecial(literal);
	}
	else if (isChar(literal))
	{
		convertFromChar(literal[0]);
	}
	else if (isInt(literal))
	{
		int value = std::atoi(literal.c_str());
		convertFromInt(value);
	}
	else if (isFloat(literal))
	{
		float value = static_cast<float>(std::atof(literal.c_str()));
		convertFromFloat(value);
	}
	else if (isDouble(literal))
	{
		double value = std::atof(literal.c_str());
		convertFromDouble(value);
	}
	else
	{
		std::cout << "Error: invalid literal" << std::endl;
	}
}