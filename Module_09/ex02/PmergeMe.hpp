#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>

class PmergeMe {
private:
	std::vector<int> _vectorData;
	std::deque<int> _dequeData;
	
	// Helper functions
	bool parseInput(int argc, char* argv[]);
	void displaySequence(const std::string& prefix, const std::vector<int>& data) const;
	
	// Ford-Johnson algorithm for vector
	void fordJohnsonVector(std::vector<int>& arr);
	void mergeInsertVector(std::vector<int>& arr, int left, int right);
	void insertionSortVector(std::vector<int>& arr, int left, int right);
	
	// Ford-Johnson algorithm for deque
	void fordJohnsonDeque(std::deque<int>& arr);
	void mergeInsertDeque(std::deque<int>& arr, int left, int right);
	void insertionSortDeque(std::deque<int>& arr, int left, int right);
	
	// Orthodox Canonical Form
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);

public:
	// Constructor & Destructor
	PmergeMe();
	~PmergeMe();
	
	// Main function
	bool run(int argc, char* argv[]);
};

#endif
