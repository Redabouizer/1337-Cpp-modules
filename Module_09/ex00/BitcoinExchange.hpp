#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
	std::map<std::string, double> _data;
	
	// Helper functions
	bool isValidDate(const std::string& date) const;
	bool isValidValue(const std::string& value) const;
	double stringToDouble(const std::string& str) const;
	std::string trim(const std::string& str) const;
	
	// Orthodox Canonical Form
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

public:
	// Constructor & Destructor
	BitcoinExchange();
	~BitcoinExchange();
	
	// Main functions
	bool loadDatabase(const std::string& filename);
	void processInput(const std::string& filename);
};

#endif
