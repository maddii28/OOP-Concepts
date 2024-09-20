/*
  structs.cpp
  
  Demonstrate defining and using a struct
  24F Sec C
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Motorcycle {
    string model;
    int cc;
};

//void printBike(Motorcycle aBike) {
//void printBike(Motorcycle& aBike) {
void printBike(const Motorcycle& aBike) {
    cout << "Model: " << aBike.model << "; cc: " << aBike.cc << endl;
}

int main() {
    Motorcycle myBike;

    //cout << myBike << endl;
    cout << "Model: " << myBike.model << "; cc: " << myBike.cc << endl;

    // string s;
    // cout << s << endl;

    myBike.model = "VStrom";
    myBike.cc = 650;
    cout << "Model: " << myBike.model << "; cc: " << myBike.cc << endl;

    Motorcycle dreamBike { "Bonneville", 1000 };
    cout << "Model: " << dreamBike.model 
         << "; cc: " << dreamBike.cc << endl;

    printBike(dreamBike);

    ifstream bikeStream("bikes.txt");
    if (!bikeStream) {
        cout << "Failed to open bikes.txt\n";
        exit(1);
    }

    //vector<string> lines;
    vector<Motorcycle> bikes;

    // string model;
    // int cc;
    // while (bikeStream >> model >> cc) {
    //     // Motorcycle mot { model, cc };
    //     // bikes.push_back(mot);
        
    //     bikes.push_back(Motorcycle{ model, cc });
    // }

    Motorcycle mot;
    while (bikeStream >> mot.model >> mot.cc) {
        bikes.push_back(mot);
    }

    for (size_t index = 0; index < bikes.size(); ++index) {
        printBike(bikes[index]);
    }

    //for (Motorcycle m : bikes) {
    //for (Motorcycle& m : bikes) {
    for (const Motorcycle& m : bikes) {
        printBike(m);
    }

}
