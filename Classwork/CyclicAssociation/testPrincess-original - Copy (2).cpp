/*
    testPrincess-original.cpp
    Cyclic Association
    Sec Base
*/

#include <iostream>
#include <string>
using namespace std;

class Princess {
    friend ostream& operator<<(ostream& os, const Princess& princess)
    {
	os << "Princess: " << princess.name;
	return os;
    } // op<< Princess
public:
    Princess(const string& name) : name(name) {}
private:
    string name;
}; // Princess

class FrogPrince {
    friend ostream& operator<<(ostream& os, const FrogPrince& frog)
    {
	os << "Frog Prince: " << frog.name;
	return os;
    } // op<< FrogPrince
public:
    FrogPrince(const string& name) : name(name) {}
private:
    string name;
}; // FrogPrince

int main()
{
    Princess snowy("Snow White");
    cout << snowy << endl;
    FrogPrince froggy("Froggy");
    cout << froggy << endl;
    // snowy.marries(froggy);
    // cout << snowy << endl
    //      << froggy << endl;
} // main
