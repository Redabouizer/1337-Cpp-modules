#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

// Constructor
BitcoinExchange::BitcoinExchange() {}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

// Copy constructor (private - not used)
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

// Assignment operator (private - not used)
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_data = other._data;
	}
	return *this;
}

// Trim whitespace from string
std::string BitcoinExchange::trim(const std::string& str) const {
	size_t start = 0;
	size_t end = str.length();
	
	while (start < end && (str[start] == ' ' || str[start] == '\t' || str[start] == '\r' || str[start] == '\n'))
		start++;
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t' || str[end - 1] == '\r' || str[end - 1] == '\n'))
		end--;
	
	return str.substr(start, end - start);
}

// Convert string to double
double BitcoinExchange::stringToDouble(const std::string& str) const {
	std::istringstream iss(str);
	double value;
	iss >> value;
	return value;
}

// Validate date format (YYYY-MM-DD)
bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10)
		return false;
	
	if (date[4] != '-' || date[7] != '-')
		return false;
	
	// Check if all other characters are digits
	for (size_t i = 0; i < date.length(); i++) {
		if (i != 4 && i != 7 && !isdigit(date[i]))
			return false;
	}
	
	// Extract year, month, day
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	
	// Validate ranges
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	
	// Check days in month
	if (month == 2) {
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28))
			return false;
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30)
			return false;
	}
	
	return true;
}

// Validate value
bool BitcoinExchange::isValidValue(const std::string& value) const {
	if (value.empty())
		return false;
	
	size_t start = 0;
	bool hasDecimal = false;
	
	// Check for negative sign
	if (value[0] == '-')
		start = 1;
	else if (value[0] == '+')
		start = 1;
	
	if (start >= value.length())
		return false;
	
	for (size_t i = start; i < value.length(); i++) {
		if (value[i] == '.') {
			if (hasDecimal)
				return false;
			hasDecimal = true;
		} else if (!isdigit(value[i])) {
			return false;
		}
	}
	
	return true;
}

// Load database from CSV file
bool BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		return false;
	}
	
	std::string line;
	bool firstLine = true;
	
	while (std::getline(file, line)) {
		// Skip header line
		if (firstLine) {
			firstLine = false;
			continue;
		}
		
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;
		
		std::string date = line.substr(0, commaPos);
		std::string value = line.substr(commaPos + 1);
		
		if (isValidDate(date) && isValidValue(value)) {
			_data[date] = stringToDouble(value);
		}
	}
	
	file.close();
	return true;
}

// Process input file
void BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	
	std::string line;
	bool firstLine = true;
	
	while (std::getline(file, line)) {
		// Skip empty lines
		if (line.empty())
			continue;
			
		// Skip header line
		if (firstLine) {
			firstLine = false;
			if (line.find("date") != std::string::npos && line.find("value") != std::string::npos)
				continue;
		}
		
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		std::string date = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 1));
		
		// Validate date
		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		
		// Validate value format
		if (!isValidValue(valueStr)) {
			std::cerr << "Error: bad input => " << valueStr << std::endl;
			continue;
		}
		
		double value = stringToDouble(valueStr);
		
		// Check if value is negative
		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		
		// Check if value is too large
		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		
		// Find the closest date in database
		std::map<std::string, double>::const_iterator it = _data.lower_bound(date);
		
		// If exact match or it points to a date greater than searched date
		if (it != _data.end() && it->first == date) {
			// Exact match
			std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
		} else if (it == _data.begin()) {
			// Date is before all entries in database
			std::cerr << "Error: date too early in database." << std::endl;
		} else {
			// Use previous date (closest lower date)
			--it;
			std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
		}
	}
	
	file.close();
}
