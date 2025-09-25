# C++ Module 07: C++ Templates

This module explores fundamental C++98 template patterns through three progressive exercises. You will build generic functions, apply higher-order iteration, and implement a dynamic array class template while preserving orthodox canonical form.

## Exercises Overview

### Exercise 00: Whatever
**Directory:** `ex00/`  
**Files:** `Makefile`, `main.cpp`, `whatever.hpp`

Implement three function templates:
- `swap(T&, T&)` — exchange two values by reference.
- `min(T const&, T const&)` — return the smaller operand (second operand when equal).
- `max(T const&, T const&)` — return the larger operand (second operand when equal).

The provided `main.cpp` demonstrates usage with integers, strings, and const floats.

### Exercise 01: Iter
**Directory:** `ex01/`  
**Files:** `Makefile`, `main.cpp`, `iter.hpp`

Create a function template `iter(T* array, size_t length, void (*func)(T&))` and an overload handling `const` arrays. The function applies a callback to each element of any raw array. The sample program prints values, increments integers, and uppercases characters to showcase both overloads.

### Exercise 02: Array
**Directory:** `ex02/`  
**Files:** `Makefile`, `main.cpp`, `Array.hpp`

Design a generic `Array<T>` class template that models a simple dynamic array:
- Default constructor — creates an empty array.
- Constructor `Array(unsigned int n)` — allocates `n` default-initialized elements.
- Copy constructor and assignment operator — deep copy semantics without shared storage.
- Destructor — releases allocated memory with `delete[]`.
- `operator[]` — bounds-checked element access (throws `std::out_of_range`).
- `size()` — returns the number of stored elements.

The test program exercises copy, assignment, mutation, and exception paths.

## Compilation & Usage

Every exercise ships with a Makefile targeting the C++98 standard and strict warnings:

```bash
make
./whatever      # ex00
./iter          # ex01
./array         # ex02
```

Use `make clean`, `make fclean`, and `make re` as usual to manage build artifacts.

## Key Takeaways

- Template definitions must reside in headers to avoid linker issues.
- Prefer pass-by-reference and const-correctness for generic utilities.
- Enforce bounds checking to surface logic errors early.
- Follow Orthodox Canonical Form to manage resource ownership predictably.
