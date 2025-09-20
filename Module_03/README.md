# C++ Module 03: Inheritance# C++ - Module 03



This module introduces inheritance, one of the fundamental concepts of Object-Oriented Programming, through a progressive series of exercises building a robot combat system.**Inheritance**



## Learning Objectives**Summary:**

This document contains the exercises of Module 03 from C++ modules.

- Understanding inheritance and polymorphism

- Base class and derived class relationships**Version:** 8.0

- Virtual functions and dynamic dispatch

- Multiple inheritance and diamond problem---

- Virtual inheritance solution

- Constructor/destructor chaining## Contents

- Protected access specifier

- Method overriding and overloading* I Introduction

* II General rules

## Exercises Overview* III AI Instructions

* IV Exercise 00: Aaaaand... OPEN!

### Exercise 00: Aaaaand... OPEN!* V Exercise 01: Serena, my love!

**Directory:** `ex00/`  * VI Exercise 02: Repetitive work

**Files:** `ClapTrap.hpp`, `ClapTrap.cpp`, `main.cpp`, `Makefile`* VII Exercise 03: Now it’s weird!

* VIII Submission and Peer-Evaluation

Base class implementation for a simple robot with basic combat capabilities.

---

#### ClapTrap Class Features:

- **Name:** Robot identifier## Chapter I — Introduction

- **Hit Points (10):** Health/durability

- **Energy Points (10):** Action resourceC++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or "C with Classes".

- **Attack Damage (0):** Damage dealt per attack

The goal of these modules is to introduce you to Object-Oriented Programming.

#### Member Functions:Your code must comply with the **C++98 standard**.

```cpp

void attack(const std::string& target);Modern C++ is different, but this is your entry point before going further.

void takeDamage(unsigned int amount);

void beRepaired(unsigned int amount);---

```

## Chapter II — General rules

#### Key Concepts:

- **Class Design:** Basic class structure with private attributes### Compiling

- **Constructor/Destructor:** Proper initialization and cleanup

- **Member Functions:** Public interface for object interaction* Compile with:

- **Encapsulation:** Private data with public methods

- **State Management:** Tracking robot status and resources```bash

c++ -Wall -Wextra -Werror

#### Usage:```

```bash* Must also compile with `-std=c++98`.

make

./claptrap### Formatting & naming

```

* Directories: `ex00`, `ex01`, ...

#### Expected Behavior:* Classes in **UpperCamelCase**.

```* Filenames: `ClassName.hpp`, `ClassName.cpp`, etc.

ClapTrap <name> attacks <target>, causing <damage> points of damage!* Outputs must end with newline.

ClapTrap <name> takes <amount> points of damage!* No coding style enforced — but keep it clean & readable.

ClapTrap <name> is repaired for <amount> hit points!

```### Allowed / Forbidden



### Exercise 01: Serena, my love!* Allowed: most of the **standard library**.

**Directory:** `ex01/`  * Forbidden: C++11+, Boost, `printf()`, `malloc/free`.

**Files:** `ClapTrap.hpp`, `ClapTrap.cpp`, `ScavTrap.hpp`, `ScavTrap.cpp`, `main.cpp`, `Makefile`* No `using namespace` or `friend`.

* No STL until Modules 08–09.

Introduction of inheritance with ScavTrap derived from ClapTrap.

### Design rules

#### ScavTrap Class Features:

- **Inherits from ClapTrap:** All base functionality* Avoid memory leaks.

- **Enhanced Stats:*** Classes must follow **Orthodox Canonical Form** (Module 02–09).

  - Hit Points: 100 (vs ClapTrap's 10)* No function implementations in headers (except templates).

  - Energy Points: 50 (vs ClapTrap's 10)  * Headers must be independent & protected with include guards.

  - Attack Damage: 20 (vs ClapTrap's 0)

- **Special Ability:** `guardGate()` - enters Gate keeper mode---



#### Inheritance Structure:## Chapter III — AI Instructions

```cpp

class ScavTrap : public ClapTrap {* Build strong foundations **without shortcuts**.

public:* Don’t ask AI for direct answers — use reasoning first.

    ScavTrap();* AI is not available during exams, so relying too much on it = fail.

    ScavTrap(const std::string& name);* Peer learning > AI chat.

    ScavTrap(const ScavTrap& other);* Good practice: discuss with peers until it clicks.

    ~ScavTrap();* Bad practice: secretly copy AI code → fail at exam.

    ScavTrap& operator=(const ScavTrap& other);

    ---

    void guardGate();

};## Chapter IV — Exercise 00: Aaaaand... OPEN!

```

* Directory: `ex00/`

#### Key Concepts:* Files: `Makefile`, `main.cpp`, `ClapTrap.{hpp,cpp}`

- **Public Inheritance:** `class Derived : public Base`

- **Constructor Chaining:** Derived constructor calls base constructor### Class `ClapTrap`

- **Destructor Chaining:** Automatic base destructor calling

- **Method Inheritance:** Automatic access to base class methodsPrivate attributes:

- **Attribute Override:** Different default values in derived class

- **Polymorphism Introduction:** Same interface, different behavior* `Name` (from constructor param)

* `Hit points = 10`

#### Constructor/Destructor Order:* `Energy points = 10`

```* `Attack damage = 0`

// Construction: Base → Derived

ClapTrap constructor### Public functions:

ScavTrap constructor

```cpp

// Destruction: Derived → Base  void attack(const std::string& target);

ScavTrap destructorvoid takeDamage(unsigned int amount);

ClapTrap destructorvoid beRepaired(unsigned int amount);

``````



### Exercise 02: Repetitive workRules:

**Directory:** `ex02/`  

**Files:** `ClapTrap.hpp`, `ClapTrap.cpp`, `FragTrap.hpp`, `FragTrap.cpp`, `main.cpp`, `Makefile`* Attack reduces target HP by attack damage.

* Repair restores HP.

Second derived class demonstrating parallel inheritance paths.* Each action costs 1 energy.

* Print messages for actions + constructors/destructor.

#### FragTrap Class Features:

- **Inherits from ClapTrap:** Independent inheritance branch---

- **Enhanced Stats:**

  - Hit Points: 100## Chapter V — Exercise 01: Serena, my love!

  - Energy Points: 100

  - Attack Damage: 30* Directory: `ex01/`

- **Special Ability:** `highFivesGuys()` - positive interaction* Files: previous + `ScavTrap.{hpp,cpp}`



#### Class Hierarchy:### Class `ScavTrap` (inherits ClapTrap)

```

    ClapTrap* Hit points = 100

   /        \* Energy points = 50

ScavTrap   FragTrap* Attack damage = 20

```* Different messages in constructors, destructor, attack.

* Special ability:

#### Key Concepts:

- **Multiple Derived Classes:** Different children from same parent```cpp

- **Independent Evolution:** Each derived class has unique characteristicsvoid guardGate();

- **Specialization:** Each class serves different combat roles```

- **Code Reuse:** Common functionality inherited from base

---

### Exercise 03: Now it's weird!

**Directory:** `ex03/`  ## Chapter VI — Exercise 02: Repetitive work

**Files:** `ClapTrap.hpp`, `ClapTrap.cpp`, `ScavTrap.hpp`, `ScavTrap.cpp`, `FragTrap.hpp`, `FragTrap.cpp`, `DiamondTrap.hpp`, `DiamondTrap.cpp`, `main.cpp`, `Makefile`

* Directory: `ex02/`

Multiple inheritance and diamond problem resolution using virtual inheritance.* Files: previous + `FragTrap.{hpp,cpp}`



#### DiamondTrap Class Features:### Class `FragTrap` (inherits ClapTrap)

- **Multiple Inheritance:** Inherits from both ScavTrap and FragTrap

- **Diamond Problem:** Both parents inherit from ClapTrap* Hit points = 100

- **Virtual Inheritance:** Solves diamond problem* Energy points = 100

- **Attribute Selection:** Cherry-picks best attributes from each parent* Attack damage = 30

- **Unique Ability:** `whoAmI()` - displays both names* Special ability:



#### Final Stats:```cpp

- **Name:** FragTrap's name conventionvoid highFivesGuys(void);

- **Hit Points:** 100 (from FragTrap)```

- **Energy Points:** 50 (from ScavTrap)

- **Attack Damage:** 30 (from FragTrap)---

- **Attack Method:** ScavTrap's attack implementation

## Chapter VII — Exercise 03: Now it’s weird!

#### Diamond Problem:

```* Directory: `ex03/`

       ClapTrap* Files: previous + `DiamondTrap.{hpp,cpp}`

      /        \

  ScavTrap   FragTrap### Class `DiamondTrap` (inherits **FragTrap + ScavTrap**)

      \        /

     DiamondTrapPrivate:

```

* Attribute `name` (same variable name as ClapTrap’s `name`).

#### Virtual Inheritance Solution:

```cpp### Attributes & functions

class ScavTrap : virtual public ClapTrap { /* ... */ };

class FragTrap : virtual public ClapTrap { /* ... */ };* Own `name` from constructor

class DiamondTrap : public ScavTrap, public FragTrap { /* ... */ };* `ClapTrap::name = <name> + "_clap_name"`

```* Hit points (from FragTrap)

* Energy points (from ScavTrap)

#### Key Concepts:* Attack damage (from FragTrap)

- **Multiple Inheritance:** `class D : public A, public B`* Uses `attack()` from ScavTrap

- **Diamond Problem:** Ambiguous base class members

- **Virtual Inheritance:** `virtual public` keywordSpecial ability:

- **Constructor Complexity:** Managing multiple inheritance construction

- **Name Hiding:** Using specific parent methods```cpp

- **Attribute Selection:** Choosing which parent's attributes to usevoid whoAmI();

```

## Compilation

Displays both its name and its ClapTrap name.

All exercises use standardized Makefiles:

```makefile---

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98## Chapter VIII — Submission & Peer-Evaluation

```

* Submit in your Git repo.

### Compile All Exercises:* Evaluators may ask for small modifications live.

```bash* Goal: check you **understand** the code, not just wrote it.

cd ex00 && make

cd ex01 && make---

cd ex02 && make
cd ex03 && make
```

## Key C++ Inheritance Concepts

### 1. Basic Inheritance Syntax
```cpp
class Base {
protected:
    int protectedMember;    // Accessible to derived classes
private:
    int privateMember;      // Not accessible to derived classes
public:
    int publicMember;       // Accessible to everyone
};

class Derived : public Base {
    // Has access to protectedMember and publicMember
    // No access to privateMember
};
```

### 2. Access Specifiers in Inheritance
- **public inheritance:** `class D : public B` - IS-A relationship
- **protected inheritance:** `class D : protected B` - rarely used
- **private inheritance:** `class D : private B` - HAS-A relationship

### 3. Constructor/Destructor Chaining
```cpp
class Derived : public Base {
public:
    Derived() : Base() {  // Explicit base constructor call
        // Derived constructor body
    }
    
    ~Derived() {
        // Derived destructor body
        // Base destructor called automatically
    }
};
```

### 4. Virtual Functions (Preview)
```cpp
class Base {
public:
    virtual void method() { /* base implementation */ }
    virtual ~Base() { }  // Virtual destructor for proper cleanup
};

class Derived : public Base {
public:
    void method() override { /* derived implementation */ }
};
```

### 5. Multiple Inheritance
```cpp
class A { /* ... */ };
class B { /* ... */ };
class C : public A, public B {  // Inherits from both A and B
    // Must resolve any naming conflicts
};
```

### 6. Virtual Inheritance
```cpp
class Base { /* ... */ };
class A : virtual public Base { /* ... */ };  // Virtual inheritance
class B : virtual public Base { /* ... */ };  // Virtual inheritance
class C : public A, public B {  // Only one Base subobject
    // Diamond problem resolved
};
```

## Common Pitfalls

1. **Missing Virtual Destructors:** Can cause resource leaks
2. **Diamond Problem:** Forgetting virtual inheritance
3. **Constructor Initialization:** Not calling base constructors properly
4. **Access Levels:** Confusion between public/protected/private inheritance
5. **Multiple Inheritance:** Name conflicts and ambiguous calls
6. **Slicing Problem:** Assigning derived object to base variable
7. **Constructor Order:** Understanding construction/destruction sequence

## Resources

- C++ Reference: [cppreference.com](https://en.cppreference.com/)
- Effective C++ by Scott Meyers (Item 32-40 on inheritance)
- Design Patterns: Elements of Reusable Object-Oriented Software
- C++ Core Guidelines on Class Hierarchies
- Virtual Inheritance Explained: Technical articles and tutorials