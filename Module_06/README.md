# C++ Module 06: C++ Casts

This module focuses on different types of C++ casts and type conversions, demonstrating the proper use of `static_cast`, `reinterpret_cast`, and `dynamic_cast`.

## Learning Objectives

- Understanding different types of C++ casts
- Implementing type conversion systems
- Working with serialization and deserialization
- Runtime type identification without `std::typeinfo`
- Proper use of `reinterpret_cast` and `dynamic_cast`

## Exercises Overview

### Exercise 00: Conversion of Scalar Types
**Directory:** `ex00/`  
**Files:** `ScalarConverter.hpp`, `ScalarConverter.cpp`, `main.cpp`, `Makefile`

Implements a `ScalarConverter` class that can detect and convert between different scalar types:

#### Features:
- **Non-instantiable class** with private constructors
- **Static method** `convert(std::string literal)` that:
  - Detects input type (char, int, float, double)
  - Converts to all four scalar types
  - Handles special values (`nan`, `+inf`, `-inf`, etc.)
  - Displays results with proper formatting

#### Usage:
```bash
make
./convert 42
./convert 42.0f
./convert 'a'
./convert nan
```

#### Example Output:
```
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert 'a'
char: 'a'
int: 97
float: 97.0f
double: 97.0
```

### Exercise 01: Serialization
**Directory:** `ex01/`  
**Files:** `Data.hpp`, `Serializer.hpp`, `Serializer.cpp`, `main.cpp`, `Makefile`

Implements a serialization system using `reinterpret_cast`:

#### Components:
- **Data struct:** Contains multiple fields (id, name, value)
- **Serializer class:** Non-instantiable with static methods:
  - `uintptr_t serialize(Data* ptr)` - converts pointer to integer
  - `Data* deserialize(uintptr_t raw)` - converts integer back to pointer

#### Key Concept:
Demonstrates that serialization/deserialization preserves pointer identity:
```cpp
Data* original = &data;
uintptr_t serialized = Serializer::serialize(original);
Data* deserialized = Serializer::deserialize(serialized);
// original == deserialized (same address)
```

#### Usage:
```bash
make
./serializer
```

### Exercise 02: Identify Real Type
**Directory:** `ex02/`  
**Files:** `Base.hpp`, `A.hpp`, `B.hpp`, `C.hpp`, `functions.hpp`, all `.cpp` files, `main.cpp`, `Makefile`

Implements runtime type identification using `dynamic_cast`:

#### Components:
- **Base class:** Abstract base with virtual destructor
- **Derived classes:** A, B, C inheriting from Base
- **Functions:**
  - `Base* generate()` - randomly creates A, B, or C instances
  - `void identify(Base* p)` - identifies type using pointer
  - `void identify(Base& p)` - identifies type using reference

#### Key Concepts:
- **Pointer version:** Uses `dynamic_cast<Type*>` and checks for null
- **Reference version:** Uses `dynamic_cast<Type&>` with exception handling
- **No `std::typeinfo`** - pure `dynamic_cast` approach

#### Usage:
```bash
make
./identify
```

## Compilation

Each exercise includes a Makefile with standard flags:
- `c++ -Wall -Wextra -Werror -std=c++98`

To compile all exercises:
```bash
# Exercise 00
cd ex00 && make

# Exercise 01
cd ex01 && make

# Exercise 02
cd ex02 && make
```

## Key C++ Cast Types Used

### 1. static_cast (Exercise 00)
- Safe conversions between related types
- Numeric type conversions (int ↔ float ↔ double)
- Compile-time type checking

### 2. reinterpret_cast (Exercise 01)
- Low-level cast between unrelated types
- Pointer ↔ integer conversions
- No safety checks - developer responsibility

### 3. dynamic_cast (Exercise 02)
- Runtime type identification
- Works with polymorphic types (virtual functions)
- Safe downcasting with null/exception on failure

## Important Notes

- **C++98 Standard:** All code follows C++98 specifications
- **Memory Management:** Proper destructors and no memory leaks
- **Orthodox Canonical Form:** All classes follow proper C++ conventions
- **Error Handling:** Robust handling of edge cases and invalid inputs
- **Non-instantiable Classes:** Uses private constructors to prevent instantiation

## Testing

Each exercise includes comprehensive test programs that demonstrate:
- Normal operation with valid inputs
- Edge case handling
- Error conditions
- Special value processing (NaN, infinity)
- Type safety verification

## Common Pitfalls to Avoid

1. **Using C-style casts** - Always use explicit C++ casts
2. **Memory leaks** - Ensure proper cleanup in dynamic allocation
3. **Unsafe reinterpret_cast** - Only use when absolutely necessary
4. **Missing virtual destructors** - Required for proper polymorphism
5. **Exception safety** - Handle dynamic_cast exceptions properly

## Resources

- C++98 Standard Reference
- Effective C++ by Scott Meyers
- C++ Primer by Stanley Lippman
- 42 School C++ Module Guidelines