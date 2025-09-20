# C++ Module 05: Repetition and Exceptions# Module 05 – Bureaucracy & Exceptions (C++98)



This module introduces exception handling in C++ through a bureaucratic system, demonstrating proper exception usage, custom exception classes, and the factory pattern.Exercises recap:



## Learning Objectivesex00: Bureaucrat class with grade bounds (1..150), increment/decrement, exceptions, operator<<.

ex01: Form class added, signing logic, Bureaucrat::signForm.

- Understanding C++ exception handling (`try`, `catch`, `throw`)ex02: Abstract AForm + three concrete forms (Shrubbery, Robotomy, Presidential Pardon) with execute(), Bureaucrat::executeForm.

- Creating custom exception classesex03: Intern capable of creating forms by name (factory pattern with array of function pointers).

- Exception safety and RAII principles

- Factory design pattern implementationBuild (from inside each exercise directory):

- Function pointers and arrays of function pointersmake

- File I/O operations and error handling

- Abstract classes with concrete implementationsRun:

- Bureaucratic hierarchy and form processing simulation./bureaucrat

./forms

## Exercises Overview./forms2

./intern

### Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!

**Directory:** `ex00/`  All code follows: -std=c++98 -Wall -Wextra -Werror.

**Files:** `Bureaucrat.hpp`, `Bureaucrat.cpp`, `main.cpp`, `Makefile`No STL containers beyond basics, no using namespace std.



Basic bureaucrat class with grade validation and exception handling.Tree form produced by ShrubberyCreationForm writes to <target>_shrubbery file.

Robotomy is 50% success. Presidential Pardon prints the required message.

#### Bureaucrat Class Features:

```cppIntern supports names:

class Bureaucrat {- "shrubbery creation"

private:- "robotomy request"

    const std::string name;- "presidential pardon"

    int grade; // 1 (highest) to 150 (lowest)

Unknown form returns NULL after message.

public:
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& other);

    const std::string& getName() const;
    int getGrade() const;
    
    void incrementGrade(); // Decreases grade number (improves grade)
    void decrementGrade(); // Increases grade number (worsens grade)

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
```

#### Grade System:
- **Grade 1:** Highest possible grade
- **Grade 150:** Lowest possible grade
- **Invalid Grades:** < 1 or > 150 throw exceptions

#### Key Concepts:
- **Exception Classes:** Nested exception classes inheriting from `std::exception`
- **Exception Specification:** `throw()` specification (C++98 style)
- **Const Correctness:** Const member variables and functions
- **RAII:** Resource management through constructors/destructors
- **Stream Operations:** Custom `operator<<` implementation

#### Usage:
```bash
make
./bureaucrat
```

#### Exception Handling Pattern:
```cpp
try {
    Bureaucrat bob("Bob", 0); // Throws GradeTooHighException
} catch (const Bureaucrat::GradeTooHighException& e) {
    std::cout << "Exception: " << e.what() << std::endl;
} catch (const std::exception& e) {
    std::cout << "Standard exception: " << e.what() << std::endl;
}
```

### Exercise 01: Form up, maggots!
**Directory:** `ex01/`  
**Files:** Previous files + `Form.hpp`, `Form.cpp` (modified main.cpp)

Introduction of Form class with signing mechanisms and grade requirements.

#### Form Class Features:
```cpp
class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    ~Form();
    Form& operator=(const Form& other);

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    
    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& f);
```

#### Enhanced Bureaucrat:
```cpp
class Bureaucrat {
    // Previous members...
public:
    void signForm(Form& form);
};
```

#### Key Concepts:
- **State Management:** Form signing state tracking
- **Access Control:** Grade-based permission system
- **Exception Propagation:** Exceptions thrown from Form to Bureaucrat
- **Const Immutable Data:** Form properties that cannot change after creation
- **Bidirectional Relationships:** Bureaucrat can sign Form, Form validates Bureaucrat

### Exercise 02: No, you need form 28B, not 28C...
**Directory:** `ex02/`  
**Files:** Previous files + `AForm.hpp`, `AForm.cpp`, `ShrubberyCreationForm.hpp`, `ShrubberyCreationForm.cpp`, `RobotomyRequestForm.hpp`, `RobotomyRequestForm.cpp`, `PresidentialPardonForm.hpp`, `PresidentialPardonForm.cpp`

Abstract form system with concrete form implementations and execution logic.

#### Abstract AForm Class:
```cpp
class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    virtual ~AForm();
    AForm& operator=(const AForm& other);

    // Getters...
    void beSigned(const Bureaucrat& bureaucrat);
    
    virtual void execute(const Bureaucrat& executor) const = 0;

protected:
    virtual void action() const = 0; // Pure virtual implementation method

    class GradeTooHighException : public std::exception { /* ... */ };
    class GradeTooLowException : public std::exception { /* ... */ };
    class FormNotSignedException : public std::exception { /* ... */ };
};
```

#### Concrete Form Classes:

**1. ShrubberyCreationForm:**
- **Grade to sign:** 145
- **Grade to execute:** 137
- **Action:** Creates ASCII art trees in `<target>_shrubbery` file

**2. RobotomyRequestForm:**
- **Grade to sign:** 72  
- **Grade to execute:** 45
- **Action:** Makes drilling noises, 50% success rate for robotomy

**3. PresidentialPardonForm:**
- **Grade to sign:** 25
- **Grade to execute:** 5
- **Action:** Announces that target has been pardoned by Zaphod Beeblebrox

#### Enhanced Bureaucrat:
```cpp
class Bureaucrat {
    // Previous members...
public:
    void executeForm(const AForm& form);
};
```

#### Key Concepts:
- **Abstract Base Classes:** Pure virtual functions defining interface
- **Template Method Pattern:** `execute()` calls protected `action()`
- **File I/O Operations:** Writing ASCII art to files
- **Randomization:** Probabilistic success in robotomy
- **Exception Hierarchy:** Multiple exception types for different error conditions

### Exercise 03: At least this beats coffee-making
**Directory:** `ex03/`  
**Files:** Previous files + `Intern.hpp`, `Intern.cpp`

Factory pattern implementation for creating forms by name.

#### Intern Class:
```cpp
class Intern {
public:
    Intern();
    Intern(const Intern& other);
    ~Intern();
    Intern& operator=(const Intern& other);

    AForm* makeForm(const std::string& formName, const std::string& target);

private:
    // Array of function pointers for form creation
    typedef AForm* (*FormCreator)(const std::string& target);
    
    static AForm* createShrubberyForm(const std::string& target);
    static AForm* createRobotomyForm(const std::string& target);
    static AForm* createPresidentialForm(const std::string& target);
    
    struct FormType {
        std::string name;
        FormCreator creator;
    };
    
    static const FormType formTypes[];
    static const int numFormTypes;
};
```

#### Supported Form Names:
- `"shrubbery creation"` → ShrubberyCreationForm
- `"robotomy request"` → RobotomyRequestForm  
- `"presidential pardon"` → PresidentialPardonForm

#### Factory Implementation:
```cpp
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    for (int i = 0; i < numFormTypes; i++) {
        if (formTypes[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return formTypes[i].creator(target);
        }
    }
    std::cout << "Intern cannot create " << formName << " form" << std::endl;
    return NULL;
}
```

#### Key Concepts:
- **Factory Pattern:** Centralized object creation based on string parameters
- **Function Pointers:** Arrays of function pointers for dynamic dispatch
- **Static Methods:** Factory methods as static class members
- **Lookup Tables:** String-to-function mapping for form creation
- **Error Handling:** Graceful handling of unknown form types

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

## Key C++ Exception Handling Concepts

### 1. Basic Exception Syntax
```cpp
try {
    // Code that might throw
    riskyOperation();
} catch (const SpecificException& e) {
    // Handle specific exception type
    std::cout << "Specific error: " << e.what() << std::endl;
} catch (const std::exception& e) {
    // Handle any standard exception
    std::cout << "Standard error: " << e.what() << std::endl;
} catch (...) {
    // Handle any other exception
    std::cout << "Unknown error occurred" << std::endl;
}
```

### 2. Custom Exception Classes
```cpp
class MyException : public std::exception {
private:
    std::string message;
public:
    MyException(const std::string& msg) : message(msg) {}
    virtual ~MyException() throw() {} // C++98 style
    virtual const char* what() const throw() {
        return message.c_str();
    }
};

// Usage
throw MyException("Something went wrong");
```

### 3. Exception Specifications (C++98)
```cpp
void noThrow() throw(); // Promises not to throw any exceptions
void mayThrow() throw(std::runtime_error); // May throw specific types
void anyThrow(); // May throw any exception (default)
```

### 4. RAII and Exception Safety
```cpp
class SafeResource {
private:
    Resource* resource;
public:
    SafeResource() : resource(new Resource()) {
        if (!resource->isValid()) {
            delete resource;
            throw std::runtime_error("Invalid resource");
        }
    }
    
    ~SafeResource() {
        delete resource; // Always cleaned up
    }
    
    // Copy operations should be carefully designed
    SafeResource(const SafeResource& other) = delete; // C++11 syntax
    SafeResource& operator=(const SafeResource& other) = delete;
};
```

### 5. Factory Pattern with Function Pointers
```cpp
class ProductFactory {
public:
    typedef Product* (*Creator)();
    
    static Product* createProduct(const std::string& type) {
        static std::map<std::string, Creator> creators;
        static bool initialized = false;
        
        if (!initialized) {
            creators["TypeA"] = &createTypeA;
            creators["TypeB"] = &createTypeB;
            initialized = true;
        }
        
        std::map<std::string, Creator>::iterator it = creators.find(type);
        if (it != creators.end()) {
            return it->second();
        }
        return NULL;
    }
    
private:
    static Product* createTypeA() { return new ProductA(); }
    static Product* createTypeB() { return new ProductB(); }
};
```

## Design Patterns Demonstrated

### 1. Factory Pattern
Central creation point for related objects:
```cpp
class FormFactory {
public:
    static AForm* createForm(const std::string& type, const std::string& target);
private:
    static const FormCreationInfo forms[];
};
```

### 2. Template Method Pattern
Abstract interface with concrete implementations:
```cpp
class AForm {
public:
    void execute(const Bureaucrat& executor) const {
        validateExecution(executor);
        action(); // Implemented by derived classes
    }
protected:
    virtual void action() const = 0;
private:
    void validateExecution(const Bureaucrat& executor) const;
};
```

### 3. Strategy Pattern (Implicit)
Different form types provide different execution strategies:
```cpp
ShrubberyCreationForm form1("garden"); // File creation strategy
RobotomyRequestForm form2("target");   // Robotomy strategy  
PresidentialPardonForm form3("citizen"); // Pardon strategy
```

## Exception Safety Levels

### 1. Basic Exception Safety
Operations don't leak resources and objects remain in valid state:
```cpp
void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}
```

### 2. Strong Exception Safety
Operations are atomic - either completely succeed or leave unchanged:
```cpp
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        // Create temporary copy first
        Bureaucrat temp(other);
        // Swap with temporary (no exceptions possible here)
        std::swap(const_cast<std::string&>(this->name), 
                  const_cast<std::string&>(temp.name));
        this->grade = temp.grade;
    }
    return *this;
}
```

### 3. No-throw Guarantee
Operations guaranteed not to throw exceptions:
```cpp
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}
```

## File I/O Error Handling

```cpp
void ShrubberyCreationForm::action() const {
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file) {
        throw std::runtime_error("Cannot create shrubbery file");
    }
    
    file << "ASCII art tree here..." << std::endl;
    
    if (file.fail()) {
        throw std::runtime_error("Error writing to shrubbery file");
    }
    
    file.close();
    // File automatically closed by destructor even if exception occurs
}
```

## Testing Strategies

### Exercise 00:
- Test valid grade boundaries (1-150)
- Test invalid grades (< 1, > 150)
- Test increment/decrement at boundaries
- Verify exception messages and types

### Exercise 01:
- Test form signing with appropriate grades
- Test signing attempts with insufficient grades
- Verify form state changes after signing
- Test bureaucrat's signForm method

### Exercise 02:
- Test each concrete form's specific behavior
- Verify execution grade requirements
- Test file creation for ShrubberyCreationForm
- Test randomization in RobotomyRequestForm
- Verify execution without signing throws exception

### Exercise 03:
- Test all supported form names
- Test case sensitivity in form names
- Test unknown form name handling
- Verify created forms have correct properties

## Common Exception Handling Pitfalls

1. **Exception Specification Violations:** Throwing exceptions not in specification
2. **Resource Leaks:** Not cleaning up in presence of exceptions
3. **Catching by Value:** Should catch by const reference
4. **Generic Catch-All:** Catching `(...)` without specific handling
5. **Exception in Destructors:** Destructors should not throw
6. **Memory Leaks:** Not using RAII principles
7. **Exception Safety:** Not considering all exception scenarios

## Advanced Exception Topics

### 1. Exception Hierarchies
```cpp
class BureaucratException : public std::exception { };
class GradeException : public BureaucratException { };
class GradeTooHighException : public GradeException { };
class GradeTooLowException : public GradeException { };
```

### 2. Exception Translation
```cpp
void safeOperation() {
    try {
        dangerousSystemCall();
    } catch (const SystemException& e) {
        throw BureaucratException("System error in bureaucratic operation");
    }
}
```

### 3. Stack Unwinding
When exception is thrown:
1. Local objects destroyed in reverse order of construction
2. Destructors called automatically
3. Stack frames unwound until matching catch handler found
4. If no handler found, `std::terminate` called

## Real-World Applications

### 1. Error Handling Systems
- Network communication errors
- File system operations
- Database connection failures
- Input validation errors

### 2. Business Logic Validation
- User permission systems
- Workflow validation
- State machine transitions
- Business rule enforcement

### 3. Resource Management
- Memory allocation failures
- File handle exhaustion
- Network timeout handling
- Thread synchronization errors

## Best Practices

1. **Use RAII:** Resource management through constructors/destructors
2. **Catch Specific Exceptions:** Avoid generic catch-all handlers
3. **Exception Safety:** Design for exception scenarios
4. **Custom Exceptions:** Create meaningful exception hierarchies
5. **Don't Throw in Destructors:** Avoid double exceptions
6. **Document Exception Behavior:** Clearly specify what exceptions functions throw
7. **Prefer References:** Catch exceptions by const reference

## Resources

- Effective C++ by Scott Meyers (Items 13-15 on exceptions)
- More Effective C++ by Scott Meyers (Items 9-15 on exceptions)
- C++ Core Guidelines on Error Handling
- Exception Safety in Generic Components
- RAII and Exception Safety tutorials