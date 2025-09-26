#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "=== Basic Span Test ===" << std::endl;
    try
    {
        Span sp = Span(5);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Exception Tests ===" << std::endl;
    
    // Test empty span
    try
    {
        Span empty(1);
        std::cout << "Shortest span on empty: " << empty.shortestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception (expected): " << e.what() << std::endl;
    }
    
    // Test single element
    try
    {
        Span single(1);
        single.addNumber(42);
        std::cout << "Longest span with single element: " << single.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception (expected): " << e.what() << std::endl;
    }
    
    // Test overflow
    try
    {
        Span small(2);
        small.addNumber(1);
        small.addNumber(2);
        small.addNumber(3); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception (expected): " << e.what() << std::endl;
    }

    std::cout << "\n=== Large Container Test ===" << std::endl;
    try
    {
        Span large(10000);
        std::vector<int> numbers;
        
        // Fill with numbers 1 to 10000
        for (int i = 1; i <= 10000; ++i)
            numbers.push_back(i);
        
        large.addRange(numbers.begin(), numbers.end());
        
        std::cout << "Large span size: " << large.size() << std::endl;
        std::cout << "Shortest span in large: " << large.shortestSpan() << std::endl;
        std::cout << "Longest span in large: " << large.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Range Addition Test ===" << std::endl;
    try
    {
        Span sp(6);
        std::vector<int> range1;
        range1.push_back(100);
        range1.push_back(50);
        range1.push_back(75);
        
        std::vector<int> range2;
        range2.push_back(25);
        range2.push_back(150);
        range2.push_back(125);
        
        sp.addRange(range1.begin(), range1.end());
        sp.addRange(range2.begin(), range2.end());
        
        std::cout << "After adding ranges, size: " << sp.size() << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}