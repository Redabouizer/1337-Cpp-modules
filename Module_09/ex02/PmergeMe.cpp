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

// Create pairs and sort them by max value (vector)
void PmergeMe::createAndSortPairsVector(std::vector<int>& arr, std::vector<std::pair<int, int> >& pairs, std::vector<int>& straggler) {
	// Create pairs with (min, max) ordering
	for (size_t i = 0; i + 1 < arr.size(); i += 2) {
		int a = arr[i];
		int b = arr[i + 1];
		pairs.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}
	
	// Handle odd element
	if (arr.size() % 2 == 1)
		straggler.push_back(arr.back());
	
	// Sort pairs by their max value
	std::sort(pairs.begin(), pairs.end(), comparePairs);
}

// Build main chain and pend list from sorted pairs (vector)
void PmergeMe::buildMainAndPendVector(const std::vector<std::pair<int, int> >& pairs, std::vector<int>& main, std::vector<int>& pend) {
	// Build main chain from max values
	for (size_t i = 0; i < pairs.size(); i++)
		main.push_back(pairs[i].second);
	
	// Build pend from min values
	for (size_t i = 0; i < pairs.size(); i++)
		pend.push_back(pairs[i].first);
}

// Insert pend elements and straggler using binary search (vector)
void PmergeMe::insertElementsVector(std::vector<int>& main, const std::vector<int>& pend, const std::vector<int>& straggler) {
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
}

// Ford-Johnson sort for vector
void PmergeMe::fordJohnsonVector(std::vector<int>& arr) {
	if (arr.size() <= 1)
		return;
	
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> straggler;
	std::vector<int> main;
	std::vector<int> pend;
	
	// Step 1: Create and sort pairs
	createAndSortPairsVector(arr, pairs, straggler);
	
	// Step 2: Build main chain and pend list
	buildMainAndPendVector(pairs, main, pend);
	
	// Step 3: Insert elements using binary search
	insertElementsVector(main, pend, straggler);
	
	// Copy result back to arr
	arr = main;
}

// Create pairs and sort them by max value (deque)
void PmergeMe::createAndSortPairsDeque(std::deque<int>& arr, std::deque<std::pair<int, int> >& pairs, std::deque<int>& straggler) {
	// Create pairs with (min, max) ordering
	for (size_t i = 0; i + 1 < arr.size(); i += 2) {
		int a = arr[i];
		int b = arr[i + 1];
		pairs.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}
	
	// Handle odd element
	if (arr.size() % 2 == 1)
		straggler.push_back(arr.back());
	
	// Sort pairs by their max value
	std::sort(pairs.begin(), pairs.end(), comparePairs);
}

// Build main chain and pend list from sorted pairs (deque)
void PmergeMe::buildMainAndPendDeque(const std::deque<std::pair<int, int> >& pairs, std::deque<int>& main, std::deque<int>& pend) {
	// Build main chain from max values
	for (size_t i = 0; i < pairs.size(); i++)
		main.push_back(pairs[i].second);
	
	// Build pend from min values
	for (size_t i = 0; i < pairs.size(); i++)
		pend.push_back(pairs[i].first);
}

// Insert pend elements and straggler using binary search (deque)
void PmergeMe::insertElementsDeque(std::deque<int>& main, const std::deque<int>& pend, const std::deque<int>& straggler) {
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
}

// Ford-Johnson sort for deque
void PmergeMe::fordJohnsonDeque(std::deque<int>& arr) {
	if (arr.size() <= 1)
		return;
	
	std::deque<std::pair<int, int> > pairs;
	std::deque<int> straggler;
	std::deque<int> main;
	std::deque<int> pend;
	
	// Step 1: Create and sort pairs
	createAndSortPairsDeque(arr, pairs, straggler);
	
	// Step 2: Build main chain and pend list
	buildMainAndPendDeque(pairs, main, pend);
	
	// Step 3: Insert elements using binary search
	insertElementsDeque(main, pend, straggler);
	
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
