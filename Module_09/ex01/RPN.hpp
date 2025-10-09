#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN {
private:
	// Helper functions
	bool isOperator(char c) const;
	bool isNumber(const std::string& str) const;
	int performOperation(int a, int b, char op) const;
	
	// Orthodox Canonical Form
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);

public:
	// Constructor & Destructor
	RPN();
	~RPN();
	
	// Main function
	int evaluate(const std::string& expression) const;
};

#endif
