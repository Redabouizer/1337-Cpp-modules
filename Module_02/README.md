# C++ Module 02: Ad-hoc Polymorphism, Operator Overloading and Orthodox Canonical Form

This module focuses on operator overloading, the Orthodox Canonical Form, and implementing a fixed-point number class to understand ad-hoc polymorphism.

## Learning Objectives

- Understanding Orthodox Canonical Form (OCF)
- Operator overloading in C++
- Fixed-point number representation
- Copy constructor and assignment operator
- Stream insertion operator overloading
- Comparison and arithmetic operators
- Geometric calculations and algorithms

## Orthodox Canonical Form

Every class should implement the "Big Four":
1. **Default Constructor**
2. **Copy Constructor** 
3. **Assignment Operator**
4. **Destructor**

## Exercises Overview

### Exercise 00: My First Class in Orthodox Canonical Form
**Directory:** `ex00/`  
**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, `Makefile`

Basic implementation of a fixed-point number class following Orthodox Canonical Form.

#### Features:
- **Fixed Class:** Represents fixed-point numbers with 8 fractional bits
- **Orthodox Canonical Form:** All four required methods implemented
- **Basic Operations:** Get/set raw bits functionality
- **Debug Output:** Constructor/destructor call tracking

#### Class Structure:
```cpp
class Fixed {
private:
    int value;                    // Fixed-point value
    static const int fractBits = 8; // Number of fractional bits
public:
    Fixed(void);                     // Default constructor
    Fixed(const Fixed& other);       // Copy constructor  
    ~Fixed(void);                    // Destructor
    Fixed& operator=(const Fixed& other); // Assignment operator
    
    int getRawBits(void) const;
    void setRawBits(const int raw);
};
```

#### Key Concepts:
- **Fixed-Point Arithmetic:** Alternative to floating-point
- **Static Member Variables:** Shared across all instances
- **Const Member Functions:** Functions that don't modify object state
- **Copy Operations:** Deep vs shallow copying

#### Usage:
```bash
make
./fixed
```

#### Expected Output:
```
Default constructor called
Copy constructor called
Copy assignation operator called
getRawBits member function called
Default constructor called
Copy assignation operator called
getRawBits member function called
getRawBits member function called
Destructor called
Destructor called
Destructor called
```

### Exercise 01: Towards a more useful fixed-point number class
**Directory:** `ex01/`  
**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, `Makefile`

Enhanced Fixed class with type conversion constructors and output streaming.

#### New Features:
- **Integer Constructor:** `Fixed(const int val)`
- **Float Constructor:** `Fixed(const float val)`
- **Type Conversion:** `toInt()` and `toFloat()` methods
- **Stream Operator:** `operator<<` for easy output
- **Improved Functionality:** More practical fixed-point operations

#### Additional Methods:
```cpp
Fixed(const int val);        // Convert from int
Fixed(const float val);      // Convert from float
int toInt(void) const;       // Convert to int
float toFloat(void) const;   // Convert to float
```

#### Stream Operator:
```cpp
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
```

#### Key Concepts:
- **Type Conversion Constructors:** Implicit type conversions
- **Bit Shifting:** Efficient fixed-point arithmetic
- **Stream Operator Overloading:** Custom output formatting
- **Friend Functions:** External operators accessing private members

#### Fixed-Point Conversion:
```cpp
// Integer to fixed-point: multiply by 2^fractBits
value = intValue << fractBits;

// Float to fixed-point: multiply by 2^fractBits and round
value = roundf(floatValue * (1 << fractBits));

// Fixed-point to float: divide by 2^fractBits
return float(value) / (1 << fractBits);
```

### Exercise 02: Now we're talking
**Directory:** `ex02/`  
**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, `Makefile`

Complete Fixed class with arithmetic and comparison operators.

#### New Operators:
**Comparison Operators:**
- `>`, `<`, `>=`, `<=`, `==`, `!=`

**Arithmetic Operators:**
- `+`, `-`, `*`, `/`

**Increment/Decrement:**
- `++` (pre and post-increment)
- `--` (pre and post-decrement)

**Min/Max Functions:**
- `static const Fixed& min(const Fixed& a, const Fixed& b)`
- `static const Fixed& max(const Fixed& a, const Fixed& b)`
- Overloaded versions for non-const references

#### Operator Implementation Examples:
```cpp
// Comparison
bool operator>(const Fixed& other) const {
    return this->value > other.value;
}

// Arithmetic  
Fixed operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->value + other.value);
    return result;
}

// Pre-increment
Fixed& operator++() {
    this->value++;
    return *this;
}

// Post-increment
Fixed operator++(int) {
    Fixed temp(*this);
    this->value++;
    return temp;
}
```

#### Key Concepts:
- **Operator Overloading:** Making custom types behave like built-in types
- **Return Types:** When to return by value vs by reference
- **Pre vs Post Increment:** Different semantics and performance
- **Static Member Functions:** Class-level utility functions
- **Const Correctness:** Proper const method declarations

### Exercise 03: BSP (Binary Space Partitioning)
**Directory:** `ex03/`  
**Files:** `Fixed.hpp`, `Fixed.cpp`, `Point.hpp`, `Point.cpp`, `bsp.cpp`, `main.cpp`, `Makefile`

Geometric algorithm using Fixed-point numbers to determine if a point is inside a triangle.

#### New Classes:
**Point Class:**
```cpp
class Point {
private:
    const Fixed x;
    const Fixed y;
public:
    Point();
    Point(const float x, const float y);
    Point(const Point& other);
    ~Point();
    Point& operator=(const Point& other);
    
    Fixed getX() const;
    Fixed getY() const;
};
```

#### BSP Function:
```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);
```

#### Features:
- **Immutable Coordinates:** Point coordinates are const
- **Geometric Algorithm:** Point-in-triangle testing
- **BSP Algorithm:** Binary Space Partitioning approach
- **Mathematical Precision:** Using fixed-point for consistent results

#### Algorithm Approach:
Multiple methods can be used:
1. **Barycentric Coordinates:** Check if point can be expressed as weighted sum
2. **Cross Product Method:** Check orientation of point relative to triangle edges
3. **Area Method:** Compare triangle areas

#### Key Concepts:
- **Const Member Variables:** Immutable object properties
- **Geometric Algorithms:** Computational geometry basics
- **Binary Space Partitioning:** Spatial subdivision techniques
- **Mathematical Precision:** Avoiding floating-point errors

#### Usage:
```bash
make
./bsp
```

## Compilation

All exercises use standardized Makefiles:
```makefile
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

### Compile All Exercises:
```bash
cd ex00 && make
cd ex01 && make  
cd ex02 && make
cd ex03 && make
```

## Key C++ Concepts

### 1. Orthodox Canonical Form
Essential for proper resource management:
```cpp
class MyClass {
public:
    MyClass();                           // Default constructor
    MyClass(const MyClass& other);       // Copy constructor
    MyClass& operator=(const MyClass& other); // Assignment operator
    ~MyClass();                          // Destructor
};
```

### 2. Operator Overloading Syntax
```cpp
// Member function operators
ReturnType operator+(const Type& other) const;
Type& operator++();        // Pre-increment
Type operator++(int);      // Post-increment

// Non-member operators (often friends)
std::ostream& operator<<(std::ostream& os, const Type& obj);
```

### 3. Fixed-Point Arithmetic
```cpp
// Representation: integer with implied decimal point
// For 8 fractional bits: 1.0 = 256, 0.5 = 128, etc.
class Fixed {
    int value;                    // Actual stored value
    static const int fractBits = 8; // Fractional bit count
    
    // Convert float to fixed: multiply by 2^fractBits
    Fixed(float f) : value(roundf(f * (1 << fractBits))) {}
    
    // Convert fixed to float: divide by 2^fractBits  
    float toFloat() const { return float(value) / (1 << fractBits); }
};
```

### 4. Static Member Functions
```cpp
class Fixed {
public:
    static const Fixed& min(const Fixed& a, const Fixed& b) {
        return (a < b) ? a : b;
    }
};

// Usage: Fixed::min(f1, f2)
```

## Common Operator Overloading Patterns

### 1. Comparison Operators
```cpp
bool operator==(const Fixed& other) const {
    return this->value == other.value;
}

bool operator<(const Fixed& other) const {
    return this->value < other.value;
}

// Implement others in terms of these
bool operator!=(const Fixed& other) const { return !(*this == other); }
bool operator>(const Fixed& other) const { return other < *this; }
```

### 2. Arithmetic Operators  
```cpp
Fixed operator+(const Fixed& other) const {
    Fixed result;
    result.value = this->value + other.value;
    return result;
}

Fixed& operator+=(const Fixed& other) {
    this->value += other.value;
    return *this;
}
```

### 3. Stream Operators
```cpp
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
```

## Fixed-Point vs Floating-Point

### Advantages of Fixed-Point:
- **Deterministic:** Same results across different platforms
- **Performance:** Faster on systems without FPU
- **Precision:** No rounding errors in decimal representation
- **Embedded Systems:** Common in real-time systems

### Disadvantages:
- **Limited Range:** Fixed precision allocation
- **Complexity:** Manual implementation required
- **Overflow:** Easier to exceed range limits

## Testing Strategies

### Exercise 00:
- Test copy constructor and assignment operator
- Verify constructor/destructor call order
- Check getRawBits/setRawBits functionality

### Exercise 01:
- Test int/float conversions
- Verify stream output formatting
- Check conversion precision

### Exercise 02:
- Test all comparison operators
- Verify arithmetic operations
- Test increment/decrement operators
- Check min/max functions

### Exercise 03:
- Test point inside triangle (true cases)
- Test point outside triangle (false cases)  
- Test edge cases (point on triangle boundary)
- Test degenerate triangles

## Common Pitfalls

1. **Assignment vs Copy Constructor:** Understanding when each is called
2. **Return Types:** Returning references vs values appropriately
3. **Const Correctness:** Proper const method declarations
4. **Precision Loss:** Understanding fixed-point limitations
5. **Overflow Handling:** Managing arithmetic overflow
6. **Edge Cases:** Triangle boundary conditions in BSP

## Advanced Topics

### 1. Template Version (Not in C++98)
Modern C++ would use templates for generic fixed-point:
```cpp
template<int FractionalBits>
class Fixed { /* ... */ };
```

### 2. Optimization Techniques
- Use bit operations for multiplication/division by powers of 2
- Implement specialized fast square root for fixed-point
- Consider lookup tables for trigonometric functions

### 3. Extended Precision
- Use 64-bit integers for intermediate calculations
- Implement double-width arithmetic for multiplication

## Resources

- Fixed-Point Arithmetic: [Wikipedia](https://en.wikipedia.org/wiki/Fixed-point_arithmetic)
- Operator Overloading Guidelines: C++ Core Guidelines
- Computational Geometry Algorithms: CGAL documentation
- Binary Space Partitioning: Computer Graphics texts