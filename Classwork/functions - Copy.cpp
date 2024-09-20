/*
  Defining functions and using parameter passing
  24F Sec C
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// function prototype
void addOne(int someInt);

int addOneV2(int someInt) { // pass by value
    ++someInt;  // Same effect as: someInt += 1;
    return someInt;
}

void addOneRef(int& someInt) { // pass by reference
    ++someInt;  // Same effect as: someInt += 1;
}

//void printVec(vector<int> myVec) {
//void printVec(vector<int>& myVec) { // pass by reference
void printVec(const vector<int>& myVec) { // pass by constant reference
    //for (int i = 0; i < myVec.size(); ++i) {
    for (size_t i = 0; i < myVec.size(); ++i) {
        cout << myVec[i] << ' ';
        //myVec[i] = 17;
    }
    cout << endl;
}

void printVecOfString(const vector<string>& vs) {
    for (const string& s: vs) {
        cout << s << ' ';
    }
    cout << endl;
}

int main() {

    int x = 17;

    addOne(x);
    cout << x << endl;

    x = addOneV2(x);
    cout << x << endl;

    addOneRef(x);
    cout << x << endl;

    vector<int> v { 2, 3, 5, 7, 11 };
    //cout << v << endl;

    printVec(v);
    printVec(v);

    vector<string> vs { "Twas", "brillig", "and" };
    printVecOfString(vs);
}

void addOne(int someInt) { // pass by value
    ++someInt;  // Same effect as: someInt += 1;
}

