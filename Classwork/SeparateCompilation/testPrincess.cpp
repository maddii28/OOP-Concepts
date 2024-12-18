/*
    testPrincess.cpp
    Cyclic Association
    24F - Sec A
*/

#include "Princess.h"
#include "Princess.h"
#include "FrogPrince.h"

#include <iostream>
#include <string>
#include <string>
using namespace std;
using namespace Fantasy;

int main() {
    Fantasy::Princess snowy("Snow White");
    cout << snowy << endl;
    FrogPrince froggy("Froggy");
    cout << froggy << endl;
    snowy.marries(froggy);
    cout << snowy << endl
         << froggy << endl;
}


