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

// Insertion sort for vector
void PmergeMe::insertionSortVector(std::vector<int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int key = arr[i];
		int j = i - 1;
		
		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// Merge-insert for vector (Ford-Johnson implementation)
void PmergeMe::mergeInsertVector(std::vector<int>& arr, int left, int right) {
	if (right - left <= 15) {
		insertionSortVector(arr, left, right);
		return;
	}
	
	int mid = left + (right - left) / 2;
	mergeInsertVector(arr, left, mid);
	mergeInsertVector(arr, mid + 1, right);
	
	// Merge
	std::vector<int> temp(right - left + 1);
	int i = left, j = mid + 1, k = 0;
	
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	
	while (i <= mid)
		temp[k++] = arr[i++];
	
	while (j <= right)
		temp[k++] = arr[j++];
	
	for (i = 0; i < k; i++)
		arr[left + i] = temp[i];
}

// Ford-Johnson sort for vector
void PmergeMe::fordJohnsonVector(std::vector<int>& arr) {
	if (arr.size() <= 1)
		return;
	mergeInsertVector(arr, 0, arr.size() - 1);
}

// Insertion sort for deque
void PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int key = arr[i];
		int j = i - 1;
		
		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// Merge-insert for deque (Ford-Johnson implementation)
void PmergeMe::mergeInsertDeque(std::deque<int>& arr, int left, int right) {
	if (right - left <= 15) {
		insertionSortDeque(arr, left, right);
		return;
	}
	
	int mid = left + (right - left) / 2;
	mergeInsertDeque(arr, left, mid);
	mergeInsertDeque(arr, mid + 1, right);
	
	// Merge
	std::deque<int> temp(right - left + 1);
	int i = left, j = mid + 1, k = 0;
	
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	
	while (i <= mid)
		temp[k++] = arr[i++];
	
	while (j <= right)
		temp[k++] = arr[j++];
	
	for (i = 0; i < k; i++)
		arr[left + i] = temp[i];
}

// Ford-Johnson sort for deque
void PmergeMe::fordJohnsonDeque(std::deque<int>& arr) {
	if (arr.size() <= 1)
		return;
	mergeInsertDeque(arr, 0, arr.size() - 1);
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
