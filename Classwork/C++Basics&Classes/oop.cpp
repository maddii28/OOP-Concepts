/*
  oop.cpp
  24F Sec A

  Starting with a struct and a function that is passed an instance of
  that struct.
 */

#include <iostream>
#include <string>
using namespace std;

//struct Person {
class Person {
private:
    string name;

public:

    // Constructor
    //    Person(const string& theName) {
    Person(const string& theName) : name(theName) { // Initialization list
        //name = theName; // Need to improve on this
    }

    // Could be written as
    // Person(const string& theName) : name(theName) {  } // Initialization list

    //void personEating() {
    void eating() {
        cout << name << " eating\n";
    }

    // Getter / Accessor
    //string getName() {
    //string getName() const {
    //string& getName() const { // Compilation error
    const string& getName() const {
        //name = "fred";
        return name;
    }

    // Setter / Mutator
    // void setName(const string& aName) {
    //     name = aName;
    // }
    
};

void personEating(const Person& somebody) {
    //cout << somebody.name << endl;
    cout << somebody.getName() << " eating\n";
}

ostream& operator<<(ostream& os, const Person& rhs) {
    os << "Person: " << rhs.getName();
    return os;
}

int main() {
    //Person john;
    Person john("John");
    //john.name = "John";
    //john.setName("John");

    personEating(john);

    john.eating();
    //john.eating("John");

    //Person mary;

    cout << john << endl;

    //operator<<(cout, john);
}
