# C++ Module 08 - Templated containers, iterators, algorithms

This module introduces the use of STL (Standard Template Library) containers and algorithms in C++98.

## Exercise 00 - Easy find
- **Files**: `easyfind.hpp`, `main.cpp`, `Makefile`
- **Objective**: Create a template function that finds the first occurrence of a value in any STL container
- **Key Features**:
  - Uses `std::find` algorithm from `<algorithm>`
  - Throws exception if value not found
  - Works with any container that has iterators (vector, list, deque, etc.)

## Exercise 01 - Span
- **Files**: `Span.hpp`, `Span.cpp`, `main.cpp`, `Makefile`
- **Objective**: Create a class that stores integers and can find shortest/longest spans between them
- **Key Features**:
  - Constructor takes maximum size N
  - `addNumber()` adds single integer
  - `addRange()` adds range of integers using iterators
  - `shortestSpan()` finds minimum difference between any two numbers
  - `longestSpan()` finds maximum difference (max - min)
  - Proper exception handling for edge cases

## Exercise 02 - Mutated abomination
- **Files**: `MutantStack.hpp`, `main.cpp`, `Makefile`
- **Objective**: Create a stack class with iterator support
- **Key Features**:
  - Inherits from `std::stack<T>`
  - Adds iterator functionality (begin, end, rbegin, rend)
  - Allows iteration through stack elements
  - Compatible with standard STL algorithms
  - Demonstrates that you can add functionality to existing STL containers

## Compilation
All exercises compile with:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## Key Learning Points
- Template programming with STL containers
- STL algorithms (`std::find`, `std::min_element`, `std::max_element`, `std::sort`)
- Iterator usage and types
- Exception handling in template code
- Inheritance from STL classes
- Container interoperability

## Testing
Each exercise includes comprehensive test cases demonstrating:
- Normal operation
- Edge cases
- Exception handling
- STL compatibility