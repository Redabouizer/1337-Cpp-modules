#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <utility>

class PmergeMe {
private:
	std::vector<int> _vectorData;
	std::deque<int> _dequeData;
	
	// Helper functions
	bool parseInput(int argc, char* argv[]);
	void displaySequence(const std::string& prefix, const std::vector<int>& data) const;
	
	// Jacobsthal number generation
	std::vector<int> generateJacobsthal(int maxSize);
	
	// Comparison function for sorting pairs
	static bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b);
	
	// Ford-Johnson algorithm for vector
	void fordJohnsonVector(std::vector<int>& arr);
	void createAndSortPairsVector(std::vector<int>& arr, std::vector<std::pair<int, int> >& pairs, std::vector<int>& straggler);
	void buildMainAndPendVector(const std::vector<std::pair<int, int> >& pairs, std::vector<int>& main, std::vector<int>& pend);
	void insertElementsVector(std::vector<int>& main, const std::vector<int>& pend, const std::vector<int>& straggler);
	
	// Ford-Johnson algorithm for deque
	void fordJohnsonDeque(std::deque<int>& arr);
	void createAndSortPairsDeque(std::deque<int>& arr, std::deque<std::pair<int, int> >& pairs, std::deque<int>& straggler);
	void buildMainAndPendDeque(const std::deque<std::pair<int, int> >& pairs, std::deque<int>& main, std::deque<int>& pend);
	void insertElementsDeque(std::deque<int>& main, const std::deque<int>& pend, const std::deque<int>& straggler);
	
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
