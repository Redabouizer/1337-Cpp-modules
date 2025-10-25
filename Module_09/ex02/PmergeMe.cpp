#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _vectorData(other._vectorData), _dequeData(other._dequeData)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::parseInput(int argc, char** argv)
{
    if (argc < 2)
        throw std::runtime_error("Error: no input provided");
    
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        
        // Check if argument is a valid positive integer
        if (arg.empty())
            throw std::runtime_error("Error: invalid input");
        
        for (size_t j = 0; j < arg.length(); ++j)
        {
            if (!std::isdigit(arg[j]))
                throw std::runtime_error("Error: invalid input");
        }
        
        std::istringstream iss(arg);
        long num;
        iss >> num;
        
        if (iss.fail() || num < 0 || num > 2147483647)
            throw std::runtime_error("Error: invalid input");
        
        _vectorData.push_back(static_cast<int>(num));
        _dequeData.push_back(static_cast<int>(num));
    }
    
    if (_vectorData.empty())
        throw std::runtime_error("Error: no valid numbers provided");
}

size_t PmergeMe::jacobsthal(size_t n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    size_t prev2 = 0;
    size_t prev1 = 1;
    size_t current;
    
    for (size_t i = 2; i <= n; ++i)
    {
        current = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}

void PmergeMe::generateJacobsthalSequence(size_t n, std::vector<size_t>& sequence)
{
    if (n == 0)
        return;
    
    sequence.clear();
    
    // Generate Jacobsthal numbers
    std::vector<size_t> jacobNumbers;
    size_t index = 3;
    while (true)
    {
        size_t jacob = jacobsthal(index);
        if (jacob >= n)
            break;
        jacobNumbers.push_back(jacob);
        ++index;
    }
    
    // Build the insertion sequence
    size_t prevJacob = 1;
    for (size_t i = 0; i < jacobNumbers.size(); ++i)
    {
        size_t currentJacob = jacobNumbers[i];
        
        // Add elements in descending order between prevJacob and currentJacob
        for (size_t j = currentJacob - 1; j >= prevJacob && j < n; --j)
        {
            sequence.push_back(j);
            if (j == 0)
                break;
        }
        
        prevJacob = currentJacob;
    }
    
    // Add remaining elements
    for (size_t i = prevJacob; i < n; ++i)
    {
        sequence.push_back(i);
    }
}

void PmergeMe::sortWithVector()
{
    fordJohnsonSort(_vectorData);
}

void PmergeMe::sortWithDeque()
{
    fordJohnsonSort(_dequeData);
}

void PmergeMe::displayBefore() const
{
    std::cout << "Before: ";
    
    size_t displayCount = std::min(_vectorData.size(), static_cast<size_t>(10));
    for (size_t i = 0; i < displayCount; ++i)
    {
        std::cout << _vectorData[i];
        if (i < displayCount - 1)
            std::cout << " ";
    }
    
    if (_vectorData.size() > 10)
        std::cout << " [...]";
    
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const
{
    std::cout << "After:  ";
    
    size_t displayCount = std::min(_vectorData.size(), static_cast<size_t>(10));
    for (size_t i = 0; i < displayCount; ++i)
    {
        std::cout << _vectorData[i];
        if (i < displayCount - 1)
            std::cout << " ";
    }
    
    if (_vectorData.size() > 10)
        std::cout << " [...]";
    
    std::cout << std::endl;
}
