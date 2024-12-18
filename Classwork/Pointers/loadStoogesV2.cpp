/*
  loadStooges2.cpp
  Inclass Base

  Here we are loading a vector of instances of Person
  Modify it to load a vector of pointers to Person instancess
  
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Person {
    friend ostream& operator<<(ostream& os, const Person& someone);
public:
    Person(const string& name, int age) : name(name), age(age) {}
    const string& getName() const { return name; }
private:
    string name;
    int age;
}; // Person

int main()
{
    ifstream ifs("stooges.txt");
    if (!ifs) {
	cerr << "Failed to open stooges.txt\n";
	exit(1);
    }

    //vector<Person> stooges;
    vector<Person*> stooges;
    
    string name;
    int age;
    while (ifs >> name >> age) {
	// Person aPerson(name, age);
	// stooges.push_back(&aPerson);
        Person* aPointer = new Person(name, age);
        stooges.push_back(aPointer);
    }

    //for (const Person& per : stooges) {
    //for (Person* per : stooges) {
    for (const Person* per : stooges) {
	cout << *per << ' ' << per << endl;
    }

    int* pi = new int(42);

    cout << *pi << ' ' << pi << endl;
    delete pi;

    for (Person* per : stooges) {
	delete per;
    }
    

} // main

ostream& operator<<(ostream& os, const Person& someone)
{
    os << "Person: " << someone.name << ", " << someone.age;
    return os;
} // operator<<
