#include "PmergeMe.hpp"
#include <cstdlib>
#include <sys/time.h>
#include <iomanip>
#include <algorithm>

// Constructor
PmergeMe::PmergeMe() {}

// Destructor
PmergeMe::~PmergeMe() {}

// Copy constructor (private - not used)
PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

// Assignment operator (private - not used)
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vectorData = other._vectorData;
		_dequeData = other._dequeData;
	}
	return *this;
}

// Generate Jacobsthal numbers up to maxSize
std::vector<int> PmergeMe::generateJacobsthal(int maxSize) {
	std::vector<int> jacobsthal;
	jacobsthal.push_back(1);
	
	if (maxSize > 1)
		jacobsthal.push_back(3);
	
	while (jacobsthal.back() < maxSize) {
		int prev = jacobsthal.back();
		int prevPrev = jacobsthal[jacobsthal.size() - 2];
		int next = 2 * prev + prevPrev;
		
		if (next >= maxSize)
			break;
		jacobsthal.push_back(next);
	}
	
	return jacobsthal;
}

// Comparison function for sorting pairs
bool PmergeMe::comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.second < b.second;
}

// Display sequence
void PmergeMe::displaySequence(const std::string& prefix, const std::vector<int>& data) const {
	std::cout << prefix;
	for (size_t i = 0; i < data.size(); i++) {
		std::cout << data[i];
		if (i < data.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

// Ford-Johnson merge-insert for vector
void PmergeMe::mergeInsertVector(std::vector<std::pair<int, int> >& pairs, std::vector<int>& pend, std::vector<int>& main) {
	// Recursively sort pairs by their maximum element
	if (pairs.size() <= 1)
		return;
	
	if (pairs.size() == 2) {
		if (pairs[0].second < pairs[1].second)
			std::swap(pairs[0], pairs[1]);
		return;
	}
	
	// Divide pairs into two halves
	std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + pairs.size() / 2);
	std::vector<std::pair<int, int> > right(pairs.begin() + pairs.size() / 2, pairs.end());
	
	// Extract pend and main from left/right (simplified)
	std::vector<int> leftPend, rightPend;
	std::vector<int> leftMain, rightMain;
	
	mergeInsertVector(left, leftPend, leftMain);
	mergeInsertVector(right, rightPend, rightMain);
	
	// Merge main chains
	main.clear();
	size_t i = 0, j = 0;
	while (i < leftMain.size() && j < rightMain.size()) {
		if (leftMain[i] <= rightMain[j])
			main.push_back(leftMain[i++]);
		else
			main.push_back(rightMain[j++]);
	}
	while (i < leftMain.size())
		main.push_back(leftMain[i++]);
	while (j < rightMain.size())
		main.push_back(rightMain[j++]);
	
	// Combine pend sequences
	pend.insert(pend.end(), leftPend.begin(), leftPend.end());
	pend.insert(pend.end(), rightPend.begin(), rightPend.end());
}

// Ford-Johnson sort for vector
void PmergeMe::fordJohnsonVector(std::vector<int>& arr) {
	if (arr.size() <= 1)
		return;
	
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> straggler;
	
	// Step 1: Pair up elements
	for (size_t i = 0; i + 1 < arr.size(); i += 2) {
		int a = arr[i];
		int b = arr[i + 1];
		// Store as (min, max)
		pairs.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}
	
	// Handle odd element
	if (arr.size() % 2 == 1)
		straggler.push_back(arr.back());
	
	// Step 2: Recursively sort pairs by their maximum element
	if (pairs.size() > 1) {
		std::vector<int> pend, mainChain;
		mergeInsertVector(pairs, pend, mainChain);
	}
	
	// Step 3: Sort pairs by their max value
	std::sort(pairs.begin(), pairs.end(), comparePairs);
	
	// Step 4: Insert the larger elements into main chain
	std::vector<int> main;
	for (size_t i = 0; i < pairs.size(); i++)
		main.push_back(pairs[i].second);
	
	// Step 5: Insert smaller elements using binary search
	std::vector<int> pend;
	for (size_t i = 0; i < pairs.size(); i++)
		pend.push_back(pairs[i].first);
	
	// Generate Jacobsthal numbers for insertion order
	std::vector<int> jacobsthal = generateJacobsthal(pend.size());
	std::vector<bool> inserted(pend.size(), false);
	
	// Insert elements in Jacobsthal order
	for (size_t ji = 0; ji < jacobsthal.size(); ji++) {
		int j_idx = jacobsthal[ji];
		if (j_idx > static_cast<int>(pend.size()))
			break;
		
		int idx = j_idx - 1;
		if (inserted[idx])
			continue;
		
		// Binary search insertion position
		std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[idx]);
		main.insert(pos, pend[idx]);
		inserted[idx] = true;
	}
	
	// Insert remaining pend elements
	for (size_t i = 0; i < pend.size(); i++) {
		if (!inserted[i]) {
			std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[i]);
			main.insert(pos, pend[i]);
		}
	}
	
	// Insert straggler
	if (!straggler.empty()) {
		std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), straggler[0]);
		main.insert(pos, straggler[0]);
	}
	
	// Copy result back to arr
	arr = main;
}

// Ford-Johnson merge-insert for deque
void PmergeMe::mergeInsertDeque(std::deque<std::pair<int, int> >& pairs, std::deque<int>& pend, std::deque<int>& main) {
	// Recursively sort pairs by their maximum element
	if (pairs.size() <= 1)
		return;
	
	if (pairs.size() == 2) {
		if (pairs[0].second < pairs[1].second)
			std::swap(pairs[0], pairs[1]);
		return;
	}
	
	// Divide pairs into two halves
	std::deque<std::pair<int, int> > left(pairs.begin(), pairs.begin() + pairs.size() / 2);
	std::deque<std::pair<int, int> > right(pairs.begin() + pairs.size() / 2, pairs.end());
	
	// Extract pend and main from left/right
	std::deque<int> leftPend, rightPend;
	std::deque<int> leftMain, rightMain;
	
	mergeInsertDeque(left, leftPend, leftMain);
	mergeInsertDeque(right, rightPend, rightMain);
	
	// Merge main chains
	main.clear();
	size_t i = 0, j = 0;
	while (i < leftMain.size() && j < rightMain.size()) {
		if (leftMain[i] <= rightMain[j])
			main.push_back(leftMain[i++]);
		else
			main.push_back(rightMain[j++]);
	}
	while (i < leftMain.size())
		main.push_back(leftMain[i++]);
	while (j < rightMain.size())
		main.push_back(rightMain[j++]);
	
	// Combine pend sequences
	pend.insert(pend.end(), leftPend.begin(), leftPend.end());
	pend.insert(pend.end(), rightPend.begin(), rightPend.end());
}

// Ford-Johnson sort for deque
void PmergeMe::fordJohnsonDeque(std::deque<int>& arr) {
	if (arr.size() <= 1)
		return;
	
	std::deque<std::pair<int, int> > pairs;
	std::deque<int> straggler;
	
	// Step 1: Pair up elements
	for (size_t i = 0; i + 1 < arr.size(); i += 2) {
		int a = arr[i];
		int b = arr[i + 1];
		// Store as (min, max)
		pairs.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}
	
	// Handle odd element
	if (arr.size() % 2 == 1)
		straggler.push_back(arr.back());
	
	// Step 2: Recursively sort pairs by their maximum element
	if (pairs.size() > 1) {
		std::deque<int> pend, mainChain;
		mergeInsertDeque(pairs, pend, mainChain);
	}
	
	// Step 3: Sort pairs by their max value
	std::sort(pairs.begin(), pairs.end(), comparePairs);
	
	// Step 4: Insert the larger elements into main chain
	std::deque<int> main;
	for (size_t i = 0; i < pairs.size(); i++)
		main.push_back(pairs[i].second);
	
	// Step 5: Insert smaller elements using binary search
	std::deque<int> pend;
	for (size_t i = 0; i < pairs.size(); i++)
		pend.push_back(pairs[i].first);
	
	// Generate Jacobsthal numbers for insertion order
	std::vector<int> jacobsthal = generateJacobsthal(pend.size());
	std::vector<bool> inserted(pend.size(), false);
	
	// Insert elements in Jacobsthal order
	for (size_t ji = 0; ji < jacobsthal.size(); ji++) {
		int j_idx = jacobsthal[ji];
		if (j_idx > static_cast<int>(pend.size()))
			break;
		
		int idx = j_idx - 1;
		if (inserted[idx])
			continue;
		
		// Binary search insertion position
		std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[idx]);
		main.insert(pos, pend[idx]);
		inserted[idx] = true;
	}
	
	// Insert remaining pend elements
	for (size_t i = 0; i < pend.size(); i++) {
		if (!inserted[i]) {
			std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[i]);
			main.insert(pos, pend[i]);
		}
	}
	
	// Insert straggler
	if (!straggler.empty()) {
		std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), straggler[0]);
		main.insert(pos, straggler[0]);
	}
	
	// Copy result back to arr
	arr = main;
}

// Parse input arguments
bool PmergeMe::parseInput(int argc, char* argv[]) {
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		
		// Check if argument is a positive integer
		if (arg.empty())
			return false;
		
		for (size_t j = 0; j < arg.length(); j++) {
			if (!isdigit(arg[j]))
				return false;
		}
		
		long num = atol(arg.c_str());
		if (num < 0 || num > 2147483647)
			return false;
		
		_vectorData.push_back(static_cast<int>(num));
		_dequeData.push_back(static_cast<int>(num));
	}
	
	return true;
}

// Main run function
bool PmergeMe::run(int argc, char* argv[]) {
	// Parse input
	if (!parseInput(argc, argv)) {
		std::cerr << "Error" << std::endl;
		return false;
	}
	
	if (_vectorData.empty()) {
		std::cerr << "Error" << std::endl;
		return false;
	}
	
	// Display before
	displaySequence("Before: ", _vectorData);
	
	// Sort with vector and measure time
	struct timeval start, end;
	gettimeofday(&start, NULL);
	fordJohnsonVector(_vectorData);
	gettimeofday(&end, NULL);
	double vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	
	// Sort with deque and measure time
	gettimeofday(&start, NULL);
	fordJohnsonDeque(_dequeData);
	gettimeofday(&end, NULL);
	double dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	
	// Display after
	displaySequence("After:  ", _vectorData);
	
	// Display timing
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vectorData.size() 
	          << " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeData.size() 
	          << " elements with std::deque  : " << dequeTime << " us" << std::endl;
	
	return true;
}
