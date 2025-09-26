#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
    // Test with std::vector
    std::cout << "=== Testing with std::vector ===" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(i * 2);
    
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 8);
        std::cout << "Found value 8 in vector at position: " << (it - vec.begin()) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 15);
        std::cout << "Found value 15 in vector at position: " << (it - vec.begin()) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test with std::list
    std::cout << "\n=== Testing with std::list ===" << std::endl;
    std::list<int> lst;
    for (int i = 1; i <= 5; ++i)
        lst.push_back(i * 3);
    
    try
    {
        easyfind(lst, 9);
        std::cout << "Found value 9 in list" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try
    {
        easyfind(lst, 7);
        std::cout << "Found value 7 in list" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test with std::deque
    std::cout << "\n=== Testing with std::deque ===" << std::endl;
    std::deque<int> deq;
    for (int i = 10; i >= 1; --i)
        deq.push_back(i);
    
    try
    {
        std::deque<int>::iterator it = easyfind(deq, 5);
        std::cout << "Found value 5 in deque at position: " << (it - deq.begin()) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try
    {
        std::deque<int>::iterator it = easyfind(deq, 42);
        std::cout << "Found value 42 in deque at position: " << (it - deq.begin()) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}