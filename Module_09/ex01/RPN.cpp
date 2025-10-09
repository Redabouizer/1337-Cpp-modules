#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

// Constructor
RPN::RPN() {}

// Destructor
RPN::~RPN() {}

// Copy constructor (private - not used)
RPN::RPN(const RPN& other) {
	(void)other;
}

// Assignment operator (private - not used)
RPN& RPN::operator=(const RPN& other) {
	(void)other;
	return *this;
}

// Check if character is an operator
bool RPN::isOperator(char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Check if string is a valid number
bool RPN::isNumber(const std::string& str) const {
	if (str.empty())
		return false;
	
	// Check for single digit number (< 10)
	if (str.length() == 1 && str[0] >= '0' && str[0] <= '9')
		return true;
	
	return false;
}

// Perform arithmetic operation
int RPN::performOperation(int a, int b, char op) const {
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: division by zero");
			return a / b;
		default:
			throw std::runtime_error("Error: unknown operator");
	}
}

// Evaluate RPN expression
int RPN::evaluate(const std::string& expression) const {
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;
	
	while (iss >> token) {
		// Check if token is a number
		if (isNumber(token)) {
			int num = token[0] - '0';
			stack.push(num);
		}
		// Check if token is an operator
		else if (token.length() == 1 && isOperator(token[0])) {
			if (stack.size() < 2)
				throw std::runtime_error("Error: insufficient operands");
			
			// Pop two operands (note: order matters for - and /)
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			
			// Perform operation and push result
			int result = performOperation(a, b, token[0]);
			stack.push(result);
		}
		else {
			throw std::runtime_error("Error: invalid token");
		}
	}
	
	// Should have exactly one value left
	if (stack.size() != 1)
		throw std::runtime_error("Error: invalid expression");
	
	return stack.top();
}
