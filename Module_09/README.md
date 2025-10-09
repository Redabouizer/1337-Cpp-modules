# C++ Module 09 - STL

This module focuses on using the C++ Standard Template Library (STL) containers.

## Exercises

### Exercise 00: Bitcoin Exchange
A program that evaluates Bitcoin values on specific dates using a CSV database.

**Features:**
- Uses `std::map` container to store price data
- Validates date format (YYYY-MM-DD)
- Validates value ranges (0-1000)
- Finds closest lower date if exact match not found
- Comprehensive error handling

**Usage:**
```bash
cd ex00
make
./btc input.txt
```

**Input format:**
```
date | value
2011-01-03 | 3
2011-01-03 | 2
```

**Output example:**
```
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
Error: not a positive number.
```

### Exercise 01: Reverse Polish Notation (RPN)
A calculator that evaluates expressions in Reverse Polish Notation.

**Features:**
- Uses `std::stack` container
- Supports operators: `+`, `-`, `*`, `/`
- Validates input format
- Handles single-digit numbers only

**Usage:**
```bash
cd ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

**Output:**
```
42
```

**Examples:**
- `"1 2 +"` → `3`
- `"5 1 2 + 4 * + 3 -"` → `14`
- `"(1 + 1)"` → `Error: invalid token`

### Exercise 02: PmergeMe
Sorts positive integers using the Ford-Johnson merge-insert algorithm with two different containers.

**Features:**
- Implements Ford-Johnson algorithm for both `std::vector` and `std::deque`
- Handles ≥3000 integers
- Displays timing comparisons
- Shows before/after sequences

**Usage:**
```bash
cd ex02
make
./PmergeMe 3 5 9 7 4
```

**Output:**
```
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector : 1.00000 us
Time to process a range of 5 elements with std::deque  : 1.00000 us
```

**Testing with large dataset:**
```bash
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
```

## Key Concepts

### STL Containers Used
- **ex00:** `std::map` - Ordered associative container for key-value pairs
- **ex01:** `std::stack` - LIFO (Last-In-First-Out) container adapter
- **ex02:** `std::vector` and `std::deque` - Sequential containers

### Ford-Johnson Algorithm
The merge-insert sort (also known as Ford-Johnson algorithm) is a sorting algorithm that:
1. Uses merge sort for larger subarrays
2. Switches to insertion sort for small subarrays (≤15 elements)
3. Provides good performance on various data distributions

## Compilation

All exercises compile with:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

Each directory has its own Makefile with standard rules:
- `make` or `make all` - Compile the program
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Recompile everything

## Requirements

- C++98 standard compliance
- No memory leaks
- Orthodox Canonical Form for all classes
- Proper error handling
- Each container can only be used once per module

## Testing

### Exercise 00
Create various input files with:
- Valid dates and values
- Invalid dates (bad format, impossible dates)
- Negative numbers
- Numbers > 1000
- Missing pipes

### Exercise 01
Test with:
- Valid RPN expressions
- Invalid tokens (parentheses, multi-digit numbers)
- Insufficient operands
- Division by zero

### Exercise 02
Test with:
- Small sequences (< 10 elements)
- Medium sequences (100-1000 elements)
- Large sequences (≥3000 elements)
- Already sorted/reverse sorted sequences

## Notes

- The data.csv file for Exercise 00 should be placed in the ex00 directory
- Exercise 01 only accepts single-digit numbers in the input (though results can be larger)
- Exercise 02's performance may vary based on container implementation and system architecture
