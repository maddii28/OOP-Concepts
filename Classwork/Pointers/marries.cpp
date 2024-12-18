/*
  marries.cpp
  CS2124
  24F - Sec A
 */

#include <iostream>
#include <string>
using namespace std;

class Person {
    friend ostream& operator<<(ostream& os, const Person& rhs);

public:
    //Person(const string& name) : name(name) {}
    Person(const string& name) : name(name), spouse(nullptr) {}
    //Person() {}

    //john.marries(mary);
    //void marries(Person betrothed) {
    //void marries(Person& betrothed) {
    bool marries(Person& betrothed) {
        if (spouse == nullptr && betrothed.spouse == nullptr) {
            spouse = &betrothed;
            betrothed.spouse = this;
            return true;
        }
        return false;
    }

private:
    string name;
    //string spouse;
    //Person spouse;
    Person* spouse;  // Association
};

int main()
{
    Person john("John");
    Person mary("Mary");
    cout << john << endl
         << mary << endl;
    john.marries(mary); // fails silently
    cout << john << endl
         << mary << endl;

    int x = 17;

    // Where is x?
    cout << "x: " << x << "; &x: "  << &x << endl;  // address-of operator
                                                  
    int* p = &x; // Pointer type
    // int *p = &x; // Pointer type
    // int * p = &x; // Pointer type
    cout << "x: " << x << "; &x: "  << &x << "; p: " << p << endl;

    cout << "x: " << x << "; &x: "  << &x
         << "; p: " << p << "; *p: " << *p << endl; // dereference operator

    x = 6;
    cout << "x: " << x << "; &x: "  << &x
         << "; p: " << p << "; *p: " << *p << endl; // dereference operator

    *p = 28;
    cout << "x: " << x << "; &x: "  << &x
         << "; p: " << p << "; *p: " << *p << endl; // dereference operator

    //int* q;
    int* q = nullptr;
    //    cout << *q << endl; // Segmentation fault. Crashes!

} // main

ostream& operator<<(ostream& os, const Person& rhs)
{
    os << "Name: " << rhs.name;
    // if single print
    if (rhs.spouse == nullptr) {
        os << "; Single";
    }
    // if married print ..
    else {
        //os << "; Married";
        //os << "; Married: " << *rhs.spouse; // infinite recursion
        //os << "; Married: " << *rhs.spouse.name; // fails to compile
        //os << "; Married: " << (*rhs.spouse).name; // works but...
        os << "; Married: " << rhs.spouse->name; // best!!!
    }
    return os;
} // operator<<
