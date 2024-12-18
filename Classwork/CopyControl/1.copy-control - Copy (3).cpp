/*
  Copy Control (start)
  CS2124 - 2020 Fall
  Inclass Base
 */

#include <iostream>
using namespace std;

// Thing class has just one field, a pointer an an int on the heap
class Thing {
    friend ostream& operator<<(ostream& os, const Thing& rhs);
public:
    Thing(int x) { p = new int(x); }
    void setValue(int val) { *p = val; }
    int getValue() const { return *p; }

    //
    // Copy Control / BIG 3
    //
    //void cleanUp() {
    ~Thing() { // destructor
        delete p;
        p = nullptr; // optional
    }

    //Thing(Thing another) { // copy constructor
    Thing(const Thing& another) { // copy constructor
        //p = another.p;
        //int val = another.getValue();
        int val = *another.p;
        p = new int(val);
    }

    //aThing = andAnother; // assignment
    //aThing.operator=(andAnother);
    Thing& operator=(const Thing& rhs) {
        if (this != &rhs) { // 0. self assignment check
            // 1. Free up
            delete this->p; 

            // 2. Allocate and 3. copy
            int val = *rhs.p;
            p = new int(val);
        }
        // 4. return yourself
        return *this;
    }


private:
    int* p;
};


void doNothing(Thing something) {}

void simpleFunc() {
    Thing aThing(17);
    cout << aThing << endl;
    //    aThing.cleanUp();

    doNothing(aThing);

    Thing yetAnother(aThing);
    Thing yetAnother2 = aThing;

    Thing andAnother(6);

    aThing = andAnother; // assignment
    // operator=(aThing, andAnother); // Will not compile
    aThing.operator=(andAnother);
}

int main() {
    simpleFunc();
}

ostream& operator<<(ostream& os, const Thing& rhs) { 
    os << *rhs.p;
    return os;
}
