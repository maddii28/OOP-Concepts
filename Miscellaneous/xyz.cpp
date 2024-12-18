
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A { 
public: 
    A(string& aString) : name(aString) {} 
    A() : name() {} 
    virtual void getName() const { 
        cout << name << endl; 
    } 
private: 
    string name; 
}; 

class B : public A { 
public: 
    B() {} 
}; 

class C : public B {}; 

int main() { 
    A a("a");    // line A 
    B b("b");    // line B 
    b.getName(); // line C 
    a.getName(); // line D
}
