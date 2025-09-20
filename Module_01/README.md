# C++ Module 01: Memory Allocation, Pointers to Members, References, Switch Statement

This module focuses on memory management, pointers, references, and introduces more advanced C++ concepts including dynamic allocation and member pointers.

## Learning Objectives

- Dynamic memory allocation with `new` and `delete`
- Understanding pointers vs references
- Memory management and avoiding leaks
- Pointer to member functions
- Switch statements and control flow
- File I/O operations
- String manipulation and replacement

## Exercises Overview

### Exercise 00: BraiiiiiiinnnzzzZ
**Directory:** `ex00/`  
**Files:** `Zombie.hpp`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp`, `main.cpp`, `Makefile`

Implementation of a Zombie class demonstrating heap vs stack allocation.

#### Features:
- **Zombie Class:** Represents a zombie with a name
- **newZombie():** Creates zombie on heap (dynamic allocation)
- **randomChump():** Creates zombie on stack (automatic allocation)
- Proper destructor to show when zombies are destroyed

#### Key Concepts:
- **Heap Allocation:** Using `new` operator for dynamic memory
- **Stack Allocation:** Automatic variables with local scope
- **Memory Management:** Proper use of `delete` to avoid leaks
- **Constructor/Destructor:** Object lifecycle management

#### Usage:
```bash
make
./zombie
```

#### Expected Output:
```
Heap-Zombie: BraiiiiiiinnnzzzZ...
Stack-Zombie: BraiiiiiiinnnzzzZ...
Stack-Zombie: destroyed
Heap-Zombie: destroyed
```

#### Memory Management Pattern:
```cpp
// Heap allocation - must be deleted
Zombie* heapZombie = newZombie("Name");
delete heapZombie;

// Stack allocation - automatically destroyed
randomChump("Name"); // zombie destroyed at end of function
```

### Exercise 01: Moar brainz!
**Directory:** `ex01/`  
**Files:** `Zombie.hpp`, `Zombie.cpp`, `zombieHorde.cpp`, `main.cpp`, `Makefile`

Extension of zombie concept with array allocation and initialization.

#### Features:
- **zombieHorde():** Creates array of N zombies on heap
- **Array Management:** Single allocation for multiple objects
- **Name Assignment:** Setting names after allocation
- Proper cleanup of entire array

#### Key Function:
```cpp
Zombie* zombieHorde(int N, std::string name);
```

#### Usage:
```bash
make
./zombieHorde
```

#### Key Concepts:
- **Array Allocation:** `new Zombie[N]` syntax
- **Array Deletion:** `delete[]` for proper cleanup
- **Post-allocation Initialization:** Setting member values after creation
- **Bulk Memory Management:** Handling multiple objects efficiently

### Exercise 02: HI THIS IS BRAIN
**Directory:** `ex02/`  
**Files:** `main.cpp`, `Makefile`

Simple demonstration of pointers vs references.

#### Features:
- Creates a string variable
- Shows pointer to the string
- Shows reference to the string
- Compares memory addresses and values

#### Key Concepts:
- **Pointers:** Variables that store memory addresses
- **References:** Aliases to existing variables
- **Address-of Operator:** `&` to get memory addresses
- **Dereference Operator:** `*` to access pointed-to values

#### Expected Output:
```
Memory address of the string variable: 0x...
Memory address held by stringPTR: 0x...
Memory address held by stringREF: 0x...
Value of the string variable: HI THIS IS BRAIN
Value pointed to by stringPTR: HI THIS IS BRAIN
Value pointed to by stringREF: HI THIS IS BRAIN
```

### Exercise 03: Unnecessary violence
**Directory:** `ex03/`  
**Files:** `Weapon.hpp`, `Weapon.cpp`, `HumanA.hpp`, `HumanA.cpp`, `HumanB.hpp`, `HumanB.cpp`, `main.cpp`, `Makefile`

Demonstrates the difference between references and pointers through a combat scenario.

#### Classes:
- **Weapon:** Has a type (string) that can be changed
- **HumanA:** Always has a weapon (reference member)
- **HumanB:** May or may not have a weapon (pointer member)

#### Key Concepts:
- **Reference Members:** Must be initialized in constructor initializer list
- **Pointer Members:** Can be null, can be reassigned
- **Constructor Initializer Lists:** Proper member initialization
- **Const Correctness:** Proper use of const methods and parameters

#### Design Pattern:
```cpp
class HumanA {
private:
    Weapon& weapon; // Reference - always has a weapon
public:
    HumanA(std::string name, Weapon& weapon);
};

class HumanB {
private:
    Weapon* weapon; // Pointer - might not have a weapon
public:
    HumanB(std::string name);
    void setWeapon(Weapon& weapon);
};
```

### Exercise 04: Sed is for losers
**Directory:** `ex04/`  
**Files:** `main.cpp`, `Makefile`

File processing program that replaces all occurrences of a string in a file.

#### Features:
- Takes filename, string to find, and replacement string as parameters
- Reads entire file content
- Performs string replacement
- Writes result to new file (filename + ".replace")
- Handles file I/O errors gracefully

#### Usage:
```bash
make
./replace filename s1 s2
```

#### Key Concepts:
- **File I/O:** `std::ifstream` and `std::ofstream`
- **String Operations:** `find()`, `substr()`, `replace()` methods
- **Error Handling:** Checking file operations success
- **Command Line Arguments:** Processing program parameters

#### File Operations Pattern:
```cpp
std::ifstream inputFile(filename);
std::ofstream outputFile(filename + ".replace");
// Process content...
```

### Exercise 05: Harl 2.0
**Directory:** `ex05/`  
**Files:** `Harl.hpp`, `Harl.cpp`, `main.cpp`, `Makefile`

Implementation of a complaint system using pointers to member functions.

#### Features:
- **Harl Class:** Character that makes complaints at different levels
- **Complaint Levels:** DEBUG, INFO, WARNING, ERROR
- **Method Selection:** Using function pointers to call appropriate method
- **Dynamic Dispatch:** Runtime method selection based on level string

#### Key Concepts:
- **Pointers to Member Functions:** Advanced function pointer usage
- **Function Arrays:** Mapping strings to function pointers
- **Method Dispatch:** Runtime method selection
- **Encapsulation:** Private complaint methods with public interface

#### Method Signature Pattern:
```cpp
typedef void (Harl::*HarlFunction)(void);
HarlFunction functions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
```

### Exercise 06: Harl filter
**Directory:** `ex06/`  
**Files:** `Harl.hpp`, `Harl.cpp`, `main.cpp`, `Makefile`

Enhanced version of Harl using switch statements for level filtering.

#### Features:
- **Level Filtering:** Only show complaints at or above specified level
- **Switch Statement:** Proper use of switch for control flow
- **Fall-through Behavior:** Using switch fall-through intentionally
- **Command Line Interface:** Accept log level as parameter

#### Usage:
```bash
make
./harlFilter DEBUG
./harlFilter WARNING
```

#### Key Concepts:
- **Switch Statements:** Proper switch/case usage
- **Fall-through Logic:** Using break statements strategically
- **Log Level Hierarchy:** DEBUG < INFO < WARNING < ERROR
- **Enum Usage:** Mapping strings to numeric values

## Compilation

All exercises use standardized Makefiles:
```makefile
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

### Compile All Exercises:
```bash
# Individual exercises
cd ex00 && make
cd ex01 && make
cd ex02 && make
cd ex03 && make
cd ex04 && make
cd ex05 && make
cd ex06 && make
```

## Key C++ Concepts

### 1. Dynamic Memory Management
```cpp
// Allocation
Zombie* zombie = new Zombie("name");
Zombie* horde = new Zombie[10];

// Deallocation  
delete zombie;
delete[] horde;
```

### 2. References vs Pointers
```cpp
// Reference (must be initialized, cannot be null)
Weapon& weaponRef = weapon;

// Pointer (can be null, can be reassigned)
Weapon* weaponPtr = &weapon;
weaponPtr = nullptr;
```

### 3. Constructor Initializer Lists
```cpp
class HumanA {
    Weapon& weapon;
public:
    HumanA(std::string name, Weapon& w) : name(name), weapon(w) {}
};
```

### 4. Pointers to Member Functions
```cpp
class MyClass {
    void method();
public:
    void (MyClass::*ptr)() = &MyClass::method;
};
```

### 5. File I/O Operations
```cpp
std::ifstream input("file.txt");
std::string line;
while (std::getline(input, line)) {
    // Process line
}
```

## Memory Management Best Practices

### 1. RAII (Resource Acquisition Is Initialization)
- Acquire resources in constructors
- Release resources in destructors
- Use stack allocation when possible

### 2. Matching New/Delete
```cpp
// Single object
Zombie* z = new Zombie();
delete z;

// Array
Zombie* array = new Zombie[10];
delete[] array;
```

### 3. Avoiding Memory Leaks
- Always pair `new` with `delete`
- Use `delete[]` for arrays allocated with `new[]`
- Consider smart pointers (not available in C++98)

## Common Patterns

### 1. Factory Functions
```cpp
Zombie* newZombie(std::string name) {
    return new Zombie(name);
}
```

### 2. Stack vs Heap Decision
- **Stack:** Small objects, known lifetime, automatic cleanup
- **Heap:** Large objects, dynamic size, manual cleanup required

### 3. Reference Member Initialization
```cpp
class MyClass {
    int& ref;
public:
    MyClass(int& r) : ref(r) {} // Must use initializer list
};
```

## Testing Guidelines

### Memory Leak Testing
Use tools like Valgrind to check for memory leaks:
```bash
valgrind --leak-check=full ./program
```

### Expected Behaviors
- **ex00:** Demonstrate heap vs stack destruction order
- **ex01:** Proper array allocation and cleanup
- **ex02:** Same addresses for pointer and reference
- **ex03:** Different behavior between HumanA and HumanB
- **ex04:** Accurate string replacement in files
- **ex05:** Correct method dispatch based on level
- **ex06:** Proper switch fall-through behavior

## Common Pitfalls

1. **Memory Leaks:** Forgetting to `delete` heap-allocated objects
2. **Double Delete:** Calling `delete` on already-deleted pointers
3. **Array Delete:** Using `delete` instead of `delete[]` for arrays
4. **Dangling Pointers:** Using pointers after the object is deleted
5. **Reference Initialization:** Forgetting initializer lists for reference members
6. **File Handling:** Not checking if file operations succeed

## Resources

- C++ Reference: [cppreference.com](https://en.cppreference.com/)
- Memory Management Best Practices
- RAII Pattern Documentation
- File I/O Tutorials
- Function Pointer Usage Guides