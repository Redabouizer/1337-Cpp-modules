#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "=== MutantStack Test ===" << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "\nIterating through MutantStack:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << "\n=== Comparison with std::list ===" << std::endl;
    
    std::list<int> lst;
    
    lst.push_back(5);
    lst.push_back(17);
    
    std::cout << "List back element: " << lst.back() << std::endl;
    
    lst.pop_back();
    
    std::cout << "List size after pop: " << lst.size() << std::endl;
    
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << "\nIterating through std::list:" << std::endl;
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    
    std::cout << "\n=== Additional MutantStack Tests ===" << std::endl;
    
    // Test with strings
    MutantStack<std::string> sstack;
    sstack.push("Hello");
    sstack.push("World");
    sstack.push("C++");
    sstack.push("Templates");
    
    std::cout << "String stack contents:" << std::endl;
    for (MutantStack<std::string>::iterator sit = sstack.begin(); sit != sstack.end(); ++sit)
    {
        std::cout << *sit << " ";
    }
    std::cout << std::endl;
    
    // Test reverse iterators
    std::cout << "\nReverse iteration:" << std::endl;
    for (MutantStack<std::string>::reverse_iterator rit = sstack.rbegin(); rit != sstack.rend(); ++rit)
    {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    
    // Test copy constructor
    std::cout << "\n=== Copy Constructor Test ===" << std::endl;
    MutantStack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);
    
    MutantStack<int> copy(original);
    
    std::cout << "Original stack:" << std::endl;
    for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Copied stack:" << std::endl;
    for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    return 0;
}