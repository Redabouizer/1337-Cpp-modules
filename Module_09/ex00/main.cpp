#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	
	BitcoinExchange btc;
	
	// Load the database (data.csv should be in the same directory or path)
	if (!btc.loadDatabase("data.csv")) {
		return 1;
	}
	
	// Process the input file
	btc.processInput(argv[1]);
	
	return 0;
}
