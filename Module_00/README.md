# C++ Module 00: Namespaces, Classes, Member Functions, stdio streams, Initialization Lists, Static, Const, and other basics

This is the first module in the C++ series, introducing fundamental C++ concepts including classes, member functions, and basic I/O operations.

## Learning Objectives

- Understanding C++ namespaces and scope resolution
- Introduction to classes and objects
- Member functions and encapsulation
- C++ I/O streams (iostream)
- Static members and functions
- Const correctness
- Basic C++ syntax and conventions
- Difference between C and C++

## Exercises Overview

### Exercise 00: Megaphone
**Directory:** `ex00/`  
**Files:** `megaphone.cpp`, `Makefile`

A simple program that converts command line arguments to uppercase.

#### Features:
- Takes command line arguments and converts them to uppercase
- If no arguments provided, outputs: `* LOUD AND UNBEARABLE FEEDBACK NOISE *`
- Demonstrates basic C++ I/O with `std::cout`
- Uses `std::toupper()` for character conversion

#### Usage:
```bash
make
./megaphone "shhhhh... I think the students are asleep..."
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
./megaphone
```

#### Expected Output:
```
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

#### Key Concepts:
- C++ I/O streams (`std::cout`, `std::endl`)
- Character manipulation (`std::toupper`)
- Command line argument processing
- Basic control structures in C++

### Exercise 01: My Awesome PhoneBook
**Directory:** `ex01/`  
**Files:** `contact.hpp`, `contact.cpp`, `phonebook.hpp`, `phonebook.cpp`, `main.cpp`, `utils.cpp`, `Makefile`

A console-based phonebook application demonstrating classes, objects, and user interaction.

#### Features:
- **Contact Class:** Stores contact information (first name, last name, nickname, phone number, darkest secret)
- **PhoneBook Class:** Manages up to 8 contacts with circular replacement
- **Commands:**
  - `ADD`: Add a new contact
  - `SEARCH`: Display contacts table and search by index
  - `EXIT`: Quit the program

#### Contact Fields:
- First Name
- Last Name  
- Nickname
- Phone Number
- Darkest Secret

#### Display Rules:
- Table format with 10-character width columns
- Text longer than 10 characters is truncated with a dot (.)
- Right-aligned display
- Index-based contact retrieval

#### Usage:
```bash
make
./phonebook
```

#### Interactive Commands:
```
Enter command (ADD/SEARCH/EXIT): ADD
Enter command (ADD/SEARCH/EXIT): SEARCH
Enter command (ADD/SEARCH/EXIT): EXIT
```

#### Key Concepts:
- Class design and encapsulation
- Private and public member variables/functions
- Constructor and destructor
- String manipulation and formatting
- User input validation
- Array management (fixed size)
- Object lifecycle

### Exercise 02: The Job Of Your Dreams
**Directory:** `ex02/`  
**Files:** `Account.hpp`, `Account.cpp`, `tests.cpp`, `Makefile`

Recreation of a missing `Account.cpp` file based on the header file and test output.

#### Features:
- **Account Class:** Bank account simulation
- **Static Members:** Track total accounts, deposits, withdrawals
- **Member Functions:**
  - `makeDeposit()`: Add money to account
  - `makeWithdrawal()`: Remove money (if sufficient funds)
  - `displayStatus()`: Show account information
  - `displayAccountsInfos()`: Show global statistics

#### Static Functions:
- `getNbAccounts()`: Returns total number of accounts
- `getTotalAmount()`: Returns sum of all account balances  
- `getNbDeposits()`: Returns total number of deposits made
- `getNbWithdrawals()`: Returns total number of withdrawals made

#### Key Features:
- Timestamp display for all operations
- Proper initialization and destruction logging
- Static member management
- Const correctness for getter functions

#### Usage:
```bash
make
./account
```

#### Key Concepts:
- Static member variables and functions
- Const member functions
- Constructor initialization
- Destructor cleanup
- Time/date manipulation
- Private helper functions (`_displayTimestamp`)
- Global state management

## Compilation

Each exercise includes a Makefile with C++98 compliance:
```makefile
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

### Compile All Exercises:
```bash
# Exercise 00
cd ex00 && make

# Exercise 01  
cd ex01 && make

# Exercise 02
cd ex02 && make
```

## Key C++ Concepts Introduced

### 1. Classes and Objects
- Class declaration with `class` keyword
- Public and private access specifiers
- Member variables and member functions
- Object instantiation and destruction

### 2. Constructors and Destructors
- Default constructors
- Parameterized constructors
- Destructor cleanup (`~ClassName()`)
- Object lifecycle management

### 3. Static Members
- Static member variables (shared across all instances)
- Static member functions (class-level functions)
- Global state management

### 4. Const Correctness
- Const member functions (don't modify object state)
- Const variables and parameters
- Read-only access patterns

### 5. C++ I/O Streams
- `std::cout` for output
- `std::cin` for input  
- `std::endl` for newlines and buffer flushing
- String stream manipulation

### 6. Encapsulation
- Private member variables
- Public interface functions
- Data hiding and access control

## Common Patterns

### Orthodox Canonical Form (Introduction)
While not fully required in Module 00, these exercises introduce concepts that lead to:
- Default constructor
- Copy constructor (implied)
- Assignment operator (implied)  
- Destructor

### Input Validation
```cpp
// Example pattern from phonebook
while (getline(std::cin, input)) {
    if (input.empty()) {
        std::cout << "Field cannot be empty!" << std::endl;
        continue;
    }
    break;
}
```

### Static Member Management
```cpp
class Account {
private:
    static int _nbAccounts;
    static int _totalAmount;
    
public:
    static int getNbAccounts(void) { return _nbAccounts; }
    static int getTotalAmount(void) { return _totalAmount; }
};
```

## Important Guidelines

### C++98 Standard
- Use `std::` prefix for standard library functions
- No C++11 features (auto, nullptr, etc.)
- Traditional for-loops and iterators

### Memory Management
- No dynamic allocation in these exercises
- Stack-based object management
- Proper constructor/destructor patterns

### Code Style
- Use meaningful variable and function names
- Consistent indentation and formatting
- Header guards in all `.hpp` files
- Separate declaration and implementation

## Testing Tips

### Exercise 00 Testing:
```bash
./megaphone
./megaphone "hello world"
./megaphone "HELLO" "world" "123"
```

### Exercise 01 Testing:
- Test all three commands (ADD/SEARCH/EXIT)
- Try adding more than 8 contacts (should replace oldest)
- Test empty inputs and validation
- Test display formatting with long names

### Exercise 02 Testing:
- Compare output with expected logs
- Verify timestamp format
- Check static member calculations
- Test withdrawal edge cases (insufficient funds)

## Common Pitfalls

1. **Missing `std::`** - Always use `std::cout`, `std::cin`, etc.
2. **Header Guards** - Use `#ifndef/#define/#endif` in headers
3. **Const Correctness** - Mark getter functions as `const`
4. **Static Initialization** - Initialize static members outside class
5. **Input Validation** - Handle empty inputs and edge cases
6. **Memory Leaks** - Ensure proper cleanup (though not dynamic allocation)

## Resources

- C++ Reference: [cppreference.com](https://en.cppreference.com/)
- C++98 Standard Documentation
- Effective C++ by Scott Meyers (advanced concepts)
- 42 School C++ Module Guidelines