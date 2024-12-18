/*
rec09_assigning.cpp
Name - Maddhav Suneja
Purpose - assignment btw derived and base 
*/

#include <iostream>
using namespace std;

class Base {
    
};

class Derived : public Base {
    
};

int main() {
    // Step 1: Create instances of Base and Derived
    Base baseInstance;
    Derived derivedInstance;

    // Step 2: Create pointers to Base and Derived, initialized to null
    Base* basePtr = nullptr;
    Derived* derivedPtr = nullptr;

    // 1. Trying to assign instances of the classes to each other
    cout << "=== Object Assignments ===" << endl;
    
    // Base baseVar = derivedInstance;
    Base baseVar = derivedInstance;  // Allowed, because Derived "is a" Base
    cout << "Base baseVar = derivedInstance; // Works!" << endl;

    // Derived derivedVar = baseInstance; // This won't work
    // derivedVar = baseInstance; // Error: cannot convert Base to Derived
    cout << "Derived derivedVar = baseInstance; // Doesn't work!" << endl;

    // 2. Now, try the same but with pointers
    cout << "\n=== Pointer Assignments (Null pointers) ===" << endl;

    basePtr = derivedPtr;  // This works because a Derived pointer can be assigned to a Base pointer
    cout << "basePtr = derivedPtr; // Works!" << endl;

    // derivedPtr = basePtr; // This won't work
    // derivedPtr = basePtr; 
    cout << "derivedPtr = basePtr; // Doesn't work!" << endl;

    // 3. Assign addresses of each object to each pointer variable
    cout << "\n=== Assigning Object Addresses to Pointers ===" << endl;

    basePtr = &baseInstance;   // Works(Base pointer to Base instance)
    cout << "basePtr = &baseInstance; // Works!" << endl;

    derivedPtr = &derivedInstance; // Works(Derived pointer to Derived instance)
    cout << "derivedPtr = &derivedInstance; // Works!" << endl;

    basePtr = &derivedInstance; // Works because Derived "is a" Base
    cout << "basePtr = &derivedInstance; // Works!" << endl;

    // derivedPtr = &baseInstance; // This won't work
    // derivedPtr = &baseInstance; // Error: cannot convert Base to Derived
    cout << "derivedPtr = &baseInstance; // Doesn't work!" << endl;

    return 0;
}