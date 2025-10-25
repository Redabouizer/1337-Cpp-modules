#include "PmergeMe.hpp"

static double getElapsedTime(clock_t start, clock_t end)
{
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
}

int main(int argc, char** argv)
{
    try
    {
        PmergeMe sorter;
        
        // Parse input
        sorter.parseInput(argc, argv);
        
        // Display before sorting
        sorter.displayBefore();
        
        // Sort with std::vector and measure time
        clock_t startVector = clock();
        sorter.sortWithVector();
        clock_t endVector = clock();
        double timeVector = getElapsedTime(startVector, endVector);
        
        // Display after sorting
        sorter.displayAfter();
        
        // Sort with std::deque and measure time
        clock_t startDeque = clock();
        sorter.sortWithDeque();
        clock_t endDeque = clock();
        double timeDeque = getElapsedTime(startDeque, endDeque);
        
        // Display timing results
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << sorter.getVector().size() 
                  << " elements with std::vector : " << timeVector << " us" << std::endl;
        std::cout << "Time to process a range of " << sorter.getDeque().size() 
                  << " elements with std::deque  : " << timeDeque << " us" << std::endl;
        
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
