#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <iomanip>

class PmergeMe
{
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;
    
    // Jacobsthal sequence helper
    static size_t jacobsthal(size_t n);
    static void generateJacobsthalSequence(size_t n, std::vector<size_t>& sequence);
    
    // Ford-Johnson algorithm for std::vector
    template<typename Container>
    static void fordJohnsonSort(Container& container);
    
    template<typename Container>
    static void mergePairs(Container& container, std::vector<std::pair<int, int> >& pairs);
    
    template<typename Container>
    static void insertRemaining(Container& mainChain, const std::vector<int>& remaining);
    
    template<typename Container>
    static typename Container::iterator binarySearchInsert(typename Container::iterator begin,
                                                           typename Container::iterator end,
                                                           int value);
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    void parseInput(int argc, char** argv);
    void sortWithVector();
    void sortWithDeque();
    void displayBefore() const;
    void displayAfter() const;
    
    const std::vector<int>& getVector() const { return _vectorData; }
    const std::deque<int>& getDeque() const { return _dequeData; }
};

// Template implementations

template<typename Container>
void PmergeMe::fordJohnsonSort(Container& container)
{
    size_t n = container.size();
    
    if (n <= 1)
        return;
    
    // Step 1: Create pairs and sort them internally
    std::vector<std::pair<int, int> > pairs;
    int unpaired = -1;
    bool hasUnpaired = false;
    
    typename Container::iterator it = container.begin();
    for (size_t i = 0; i < n / 2; ++i)
    {
        int first = *it++;
        int second = *it++;
        if (first > second)
            pairs.push_back(std::make_pair(second, first));
        else
            pairs.push_back(std::make_pair(first, second));
    }
    
    if (n % 2 == 1)
    {
        unpaired = *it;
        hasUnpaired = true;
    }
    
    // Step 2: Sort pairs by their larger element using merge sort
    if (pairs.size() > 1)
    {
        // Simple recursive merge sort for pairs
        std::vector<std::pair<int, int> > temp = pairs;
        for (size_t width = 1; width < pairs.size(); width *= 2)
        {
            for (size_t i = 0; i < pairs.size(); i += 2 * width)
            {
                size_t left = i;
                size_t mid = std::min(i + width, pairs.size());
                size_t right = std::min(i + 2 * width, pairs.size());
                
                size_t l = left, m = mid, k = left;
                while (l < mid && m < right)
                {
                    if (temp[l].second <= temp[m].second)
                        pairs[k++] = temp[l++];
                    else
                        pairs[k++] = temp[m++];
                }
                while (l < mid)
                    pairs[k++] = temp[l++];
                while (m < right)
                    pairs[k++] = temp[m++];
            }
            temp = pairs;
        }
    }
    
    // Step 3: Build main chain from larger elements
    Container mainChain;
    std::vector<int> smallElements;
    
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].second);
        smallElements.push_back(pairs[i].first);
    }
    
    // Insert the first small element at the beginning (it's always smaller than its pair)
    if (!smallElements.empty())
    {
        mainChain.insert(mainChain.begin(), smallElements[0]);
        smallElements.erase(smallElements.begin());
    }
    
    // Step 4: Insert remaining small elements using Jacobsthal sequence order
    std::vector<size_t> jacobsthalSeq;
    generateJacobsthalSequence(smallElements.size(), jacobsthalSeq);
    
    std::vector<bool> inserted(smallElements.size(), false);
    
    for (size_t i = 0; i < jacobsthalSeq.size(); ++i)
    {
        size_t idx = jacobsthalSeq[i];
        if (idx < smallElements.size() && !inserted[idx])
        {
            // Binary search insertion
            typename Container::iterator pos = binarySearchInsert<Container>(
                                                                  mainChain.begin(), 
                                                                  mainChain.end(), 
                                                                  smallElements[idx]);
            mainChain.insert(pos, smallElements[idx]);
            inserted[idx] = true;
        }
    }
    
    // Insert any remaining elements that weren't covered by Jacobsthal
    for (size_t i = 0; i < smallElements.size(); ++i)
    {
        if (!inserted[i])
        {
            typename Container::iterator pos = binarySearchInsert<Container>(
                                                                  mainChain.begin(), 
                                                                  mainChain.end(), 
                                                                  smallElements[i]);
            mainChain.insert(pos, smallElements[i]);
        }
    }
    
    // Insert unpaired element if exists
    if (hasUnpaired)
    {
        typename Container::iterator pos = binarySearchInsert<Container>(
                                                              mainChain.begin(), 
                                                              mainChain.end(), 
                                                              unpaired);
        mainChain.insert(pos, unpaired);
    }
    
    // Copy sorted result back
    container = mainChain;
}

template<typename Container>
typename Container::iterator PmergeMe::binarySearchInsert(typename Container::iterator begin,
                                                          typename Container::iterator end,
                                                          int value)
{
    typename Container::iterator left = begin;
    typename Container::iterator right = end;
    
    while (left != right)
    {
        typename Container::iterator mid = left;
        size_t distance = std::distance(left, right);
        std::advance(mid, distance / 2);
        
        if (*mid < value)
            left = ++mid;
        else
            right = mid;
    }
    
    return left;
}

#endif
