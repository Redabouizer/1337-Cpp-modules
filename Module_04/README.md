# C++ Module 04: Subtype Polymorphism, Abstract Classes, Interfaces

This module explores advanced Object-Oriented Programming concepts including polymorphism, abstract classes, and interfaces through an animal hierarchy system.

## Learning Objectives

- Understanding virtual functions and polymorphism
- Abstract classes and pure virtual functions
- Interface design patterns
- Deep vs shallow copying with polymorphic classes
- Memory management with inheritance
- Virtual destructors importance
- Brain class and composition patterns
- RAII (Resource Acquisition Is Initialization)

## Exercises Overview

### Exercise 00: Polymorphism
**Directory:** `ex00/`  
**Files:** `Animal.hpp`, `Animal.cpp`, `Dog.hpp`, `Dog.cpp`, `Cat.hpp`, `Cat.cpp`, `WrongAnimal.hpp`, `WrongAnimal.cpp`, `WrongCat.hpp`, `WrongCat.cpp`, `main.cpp`, `Makefile`

Introduction to polymorphism with proper and improper inheritance examples.

#### Animal Hierarchy:
```cpp
class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal& other);
    virtual ~Animal();
    Animal& operator=(const Animal& other);
    
    virtual void makeSound() const;
    std::string getType() const;
};

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& other);
    ~Dog();
    Dog& operator=(const Dog& other);
    
    void makeSound() const override; // "Woof!"
};

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat& other);
    ~Cat();
    Cat& operator=(const Cat& other);
    
    void makeSound() const override; // "Meow!"
};
```

#### Wrong Implementation Example:
```cpp
class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal();
    ~WrongAnimal(); // Non-virtual destructor
    
    void makeSound() const; // Non-virtual function
};

class WrongCat : public WrongAnimal {
public:
    void makeSound() const; // Shadows parent method
};
```

#### Key Concepts:
- **Virtual Functions:** Enable runtime polymorphism
- **Virtual Destructors:** Ensure proper cleanup in inheritance
- **Method Overriding:** Derived classes provide specific implementations
- **Dynamic Dispatch:** Correct method called based on actual object type
- **Polymorphic Behavior:** Same interface, different implementations

### Exercise 01: I don't want to set the world on fire
**Directory:** `ex01/`  
**Files:** Previous files + `Brain.hpp`, `Brain.cpp` (modified Dog and Cat classes)

Enhanced animal classes with brain composition and deep copying.

#### Brain Class:
```cpp
class Brain {
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain& other);
    ~Brain();
    Brain& operator=(const Brain& other);
    
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};
```

#### Enhanced Animal Classes:
```cpp
class Dog : public Animal {
private:
    Brain* brain;
public:
    Dog();
    Dog(const Dog& other);     // Deep copy constructor
    ~Dog();
    Dog& operator=(const Dog& other); // Deep assignment operator
    
    void makeSound() const override;
    Brain* getBrain() const;
};

class Cat : public Animal {
private:
    Brain* brain;
public:
    // Similar implementation to Dog
};
```

#### Key Concepts:
- **Composition:** Classes containing other class instances
- **Deep Copying:** Copying pointed-to objects, not just pointers
- **Resource Management:** Proper allocation and deallocation
- **RAII Pattern:** Resource management through constructors/destructors
- **Memory Ownership:** Clear ownership semantics

### Exercise 02: Abstract class
**Directory:** `ex02/`  
**Files:** Modified Animal class as abstract base class

Transform Animal into abstract base class that cannot be instantiated.

#### Abstract Animal Class:
```cpp
class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal& other);
    virtual ~Animal();
    Animal& operator=(const Animal& other);
    
    virtual void makeSound() const = 0; // Pure virtual function
    std::string getType() const;
};
```

#### Key Concepts:
- **Pure Virtual Functions:** `virtual function() = 0;`
- **Abstract Classes:** Classes with at least one pure virtual function
- **Cannot Instantiate:** Abstract classes cannot be instantiated directly
- **Interface Design:** Defining contracts for derived classes
- **Polymorphic Interfaces:** Common interface, multiple implementations

### Exercise 03: Interface & recap
**Directory:** `ex03/`  
**Files:** `AMateria.hpp`, `AMateria.cpp`, `Ice.hpp`, `Ice.cpp`, `Cure.hpp`, `Cure.cpp`, `ICharacter.hpp`, `Character.hpp`, `Character.cpp`, `IMateriaSource.hpp`, `MateriaSource.hpp`, `MateriaSource.cpp`, `main.cpp`, `Makefile`

Complex system demonstrating interfaces, abstract classes, and design patterns.

#### Interface Definitions:
```cpp
class ICharacter {
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

class IMateriaSource {
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};
```

#### Abstract Materia Class:
```cpp
class AMateria {
protected:
    std::string type;
public:
    AMateria(std::string const & type);
    AMateria(const AMateria& other);
    virtual ~AMateria();
    AMateria& operator=(const AMateria& other);
    
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;
};
```

#### Concrete Implementations:
```cpp
class Ice : public AMateria {
public:
    Ice();
    Ice(const Ice& other);
    ~Ice();
    Ice& operator=(const Ice& other);
    
    AMateria* clone() const override;
    void use(ICharacter& target) override;
};

class Cure : public AMateria {
public:
    // Similar to Ice
    void use(ICharacter& target) override; // Different effect
};
```

#### Key Concepts:
- **Interface Segregation:** Small, focused interfaces
- **Prototype Pattern:** `clone()` method for object copying
- **Factory Pattern:** MateriaSource creates specific materia types
- **Inventory Management:** Character equip/unequip system
- **Memory Management:** Proper cleanup of dynamic objects

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

## Key C++ Polymorphism Concepts

### 1. Virtual Functions
```cpp
class Base {
public:
    virtual void method() { std::cout << "Base method" << std::endl; }
    virtual ~Base() { } // Always virtual destructor in base classes
};

class Derived : public Base {
public:
    void method() override { std::cout << "Derived method" << std::endl; }
};

// Usage
Base* ptr = new Derived();
ptr->method(); // Calls Derived::method() due to polymorphism
delete ptr;    // Calls Derived destructor then Base destructor
```

### 2. Abstract Classes and Pure Virtual Functions
```cpp
class AbstractBase {
public:
    virtual void pureVirtualMethod() = 0; // Pure virtual function
    virtual ~AbstractBase() = 0;          // Pure virtual destructor
};

// Even pure virtual destructors need implementation
AbstractBase::~AbstractBase() { }

class ConcreteClass : public AbstractBase {
public:
    void pureVirtualMethod() override {
        // Must implement all pure virtual functions
    }
    ~ConcreteClass() { }
};
```

### 3. Interface Design Pattern
```cpp
class IInterface {
public:
    virtual ~IInterface() { }
    virtual void method1() = 0;
    virtual int method2(int param) = 0;
    // Only pure virtual functions - no data members
};

class Implementation : public IInterface {
public:
    void method1() override { /* implementation */ }
    int method2(int param) override { return param * 2; }
};
```

### 4. Deep vs Shallow Copying
```cpp
class Container {
private:
    int* data;
    int size;
public:
    // Shallow copy (wrong)
    Container(const Container& other) : data(other.data), size(other.size) {
        // Both objects point to same memory - dangerous!
    }
    
    // Deep copy (correct)
    Container(const Container& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    
    ~Container() { delete[] data; }
};
```

### 5. RAII Pattern
```cpp
class ResourceManager {
private:
    Resource* resource;
public:
    ResourceManager() : resource(new Resource()) { }
    
    ~ResourceManager() { 
        delete resource; // Automatic cleanup
    }
    
    // Rule of Three: if you need custom destructor,
    // you probably need custom copy constructor and assignment operator
    ResourceManager(const ResourceManager& other) {
        resource = new Resource(*other.resource);
    }
    
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            delete resource;
            resource = new Resource(*other.resource);
        }
        return *this;
    }
};
```

## Design Patterns Demonstrated

### 1. Template Method Pattern
```cpp
class Algorithm {
public:
    void execute() {
        step1();
        step2();
        step3();
    }
protected:
    virtual void step1() = 0;
    virtual void step2() = 0;
    void step3() { /* common implementation */ }
};
```

### 2. Strategy Pattern
```cpp
class Context {
private:
    Strategy* strategy;
public:
    void setStrategy(Strategy* s) { strategy = s; }
    void executeStrategy() { strategy->execute(); }
};
```

### 3. Factory Pattern
```cpp
class Factory {
public:
    virtual Product* createProduct(const std::string& type) = 0;
};

class ConcreteFactory : public Factory {
public:
    Product* createProduct(const std::string& type) override {
        if (type == "A") return new ProductA();
        if (type == "B") return new ProductB();
        return nullptr;
    }
};
```

### 4. Prototype Pattern
```cpp
class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual ~Prototype() { }
};

class ConcretePrototype : public Prototype {
public:
    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }
};
```

## Memory Management Best Practices

### 1. Rule of Three (C++98)
If a class needs:
- Custom destructor
- Custom copy constructor  
- Custom assignment operator

Then it needs all three.

### 2. Virtual Destructor Rule
Always make base class destructors virtual when using inheritance:
```cpp
class Base {
public:
    virtual ~Base() { } // Virtual destructor
};
```

### 3. RAII Principles
- Acquire resources in constructors
- Release resources in destructors
- Use stack allocation when possible
- Prefer smart pointers (not available in C++98)

### 4. Exception Safety
```cpp
class SafeClass {
private:
    Resource* resource1;
    Resource* resource2;
public:
    SafeClass() : resource1(nullptr), resource2(nullptr) {
        resource1 = new Resource();
        resource2 = new Resource(); // If this throws, resource1 is leaked
    }
    
    // Better approach:
    SafeClass() try : resource1(new Resource()), resource2(new Resource()) {
        // Constructor body
    } catch (...) {
        delete resource1; // Cleanup on exception
        throw;
    }
};
```

## Testing Strategies

### Exercise 00:
- Test polymorphic behavior with Animal pointers
- Compare virtual vs non-virtual method calls
- Verify proper destructor chaining
- Test with arrays of different animal types

### Exercise 01:
- Test deep copying of Brain objects
- Verify independent brain modifications
- Check memory leak detection tools
- Test copy constructor and assignment operator

### Exercise 02:
- Verify Animal cannot be instantiated
- Test that derived classes work correctly
- Ensure abstract interface is properly defined

### Exercise 03:
- Test materia creation and cloning
- Verify character inventory management
- Test materia effects on different targets
- Check proper memory cleanup

## Common Pitfalls

1. **Non-Virtual Destructors:** Leading to resource leaks
2. **Shallow Copying:** Multiple objects sharing same memory
3. **Memory Leaks:** Forgetting to delete dynamically allocated objects
4. **Slicing:** Assigning derived object to base class variable
5. **Pure Virtual Destructor:** Forgetting to provide implementation
6. **Interface Bloat:** Making interfaces too large and complex
7. **Premature Abstraction:** Creating interfaces before understanding requirements

## Advanced Topics

### 1. Virtual Function Tables (VTables)
- Runtime mechanism for polymorphism
- Each polymorphic class has a vtable
- Objects contain pointer to class vtable
- Function calls resolved through vtable lookup

### 2. Multiple Inheritance with Interfaces
```cpp
class IDrawable {
public:
    virtual void draw() = 0;
    virtual ~IDrawable() { }
};

class IMovable {
public:
    virtual void move() = 0;
    virtual ~IMovable() { }
};

class Sprite : public IDrawable, public IMovable {
public:
    void draw() override { /* implementation */ }
    void move() override { /* implementation */ }
};
```

### 3. Covariant Return Types
```cpp
class Base {
public:
    virtual Base* clone() const = 0;
};

class Derived : public Base {
public:
    Derived* clone() const override { // Covariant return type
        return new Derived(*this);
    }
};
```

## Real-World Applications

### 1. Game Development
- Entity component systems
- Behavior trees
- State machines
- Rendering pipelines

### 2. GUI Frameworks
- Widget hierarchies
- Event handling
- Draw commands
- Layout managers

### 3. Plugin Systems
- Interface-based plugins
- Dynamic loading
- Extensible architectures
- Abstract factories

## Resources

- Effective C++ by Scott Meyers (Items 7, 14, 32-40)
- Design Patterns: Gang of Four book
- C++ Core Guidelines on Class Hierarchies
- Modern C++ Design by Andrei Alexandrescu
- Polymorphism tutorials and documentation