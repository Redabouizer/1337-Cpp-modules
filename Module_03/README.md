# C++ - Module 03

**Inheritance**

**Summary:**
This document contains the exercises of Module 03 from C++ modules.

**Version:** 8.0

---

## Contents

* I Introduction
* II General rules
* III AI Instructions
* IV Exercise 00: Aaaaand... OPEN!
* V Exercise 01: Serena, my love!
* VI Exercise 02: Repetitive work
* VII Exercise 03: Now it’s weird!
* VIII Submission and Peer-Evaluation

---

## Chapter I — Introduction

C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or "C with Classes".

The goal of these modules is to introduce you to Object-Oriented Programming.
Your code must comply with the **C++98 standard**.

Modern C++ is different, but this is your entry point before going further.

---

## Chapter II — General rules

### Compiling

* Compile with:

```bash
c++ -Wall -Wextra -Werror
```
* Must also compile with `-std=c++98`.

### Formatting & naming

* Directories: `ex00`, `ex01`, ...
* Classes in **UpperCamelCase**.
* Filenames: `ClassName.hpp`, `ClassName.cpp`, etc.
* Outputs must end with newline.
* No coding style enforced — but keep it clean & readable.

### Allowed / Forbidden

* Allowed: most of the **standard library**.
* Forbidden: C++11+, Boost, `printf()`, `malloc/free`.
* No `using namespace` or `friend`.
* No STL until Modules 08–09.

### Design rules

* Avoid memory leaks.
* Classes must follow **Orthodox Canonical Form** (Module 02–09).
* No function implementations in headers (except templates).
* Headers must be independent & protected with include guards.

---

## Chapter III — AI Instructions

* Build strong foundations **without shortcuts**.
* Don’t ask AI for direct answers — use reasoning first.
* AI is not available during exams, so relying too much on it = fail.
* Peer learning > AI chat.
* Good practice: discuss with peers until it clicks.
* Bad practice: secretly copy AI code → fail at exam.

---

## Chapter IV — Exercise 00: Aaaaand... OPEN!

* Directory: `ex00/`
* Files: `Makefile`, `main.cpp`, `ClapTrap.{hpp,cpp}`

### Class `ClapTrap`

Private attributes:

* `Name` (from constructor param)
* `Hit points = 10`
* `Energy points = 10`
* `Attack damage = 0`

### Public functions:

```cpp
void attack(const std::string& target);
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);
```

Rules:

* Attack reduces target HP by attack damage.
* Repair restores HP.
* Each action costs 1 energy.
* Print messages for actions + constructors/destructor.

---

## Chapter V — Exercise 01: Serena, my love!

* Directory: `ex01/`
* Files: previous + `ScavTrap.{hpp,cpp}`

### Class `ScavTrap` (inherits ClapTrap)

* Hit points = 100
* Energy points = 50
* Attack damage = 20
* Different messages in constructors, destructor, attack.
* Special ability:

```cpp
void guardGate();
```

---

## Chapter VI — Exercise 02: Repetitive work

* Directory: `ex02/`
* Files: previous + `FragTrap.{hpp,cpp}`

### Class `FragTrap` (inherits ClapTrap)

* Hit points = 100
* Energy points = 100
* Attack damage = 30
* Special ability:

```cpp
void highFivesGuys(void);
```

---

## Chapter VII — Exercise 03: Now it’s weird!

* Directory: `ex03/`
* Files: previous + `DiamondTrap.{hpp,cpp}`

### Class `DiamondTrap` (inherits **FragTrap + ScavTrap**)

Private:

* Attribute `name` (same variable name as ClapTrap’s `name`).

### Attributes & functions

* Own `name` from constructor
* `ClapTrap::name = <name> + "_clap_name"`
* Hit points (from FragTrap)
* Energy points (from ScavTrap)
* Attack damage (from FragTrap)
* Uses `attack()` from ScavTrap

Special ability:

```cpp
void whoAmI();
```

Displays both its name and its ClapTrap name.

---

## Chapter VIII — Submission & Peer-Evaluation

* Submit in your Git repo.
* Evaluators may ask for small modifications live.
* Goal: check you **understand** the code, not just wrote it.

---
