/*
NAME: MADDHAV SUNEJA
*/

/*
  rec01_start.cpp
  fall 2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//
// main
//
int main() { // Yes, it has to have an int for the return type
    //
    // Output
    //

    // Task 1. Printing hello ...  No use of "using namespace"
    std::cout << "hello" << std::endl;

    // Task 2  Printing hello ...  Using "using namespace"
    cout << "hello" << endl;


    //
    // Types and variables
    //

    // Task 3  Displaying uninitialized variable
    int x;
    cout << "x: " << x << endl;
    
    // Task 4 Use the sizeof function to see the size in bytes of
    //        different types on your machine.
    int y = 17;
    int z = 2000000017;
    double pie = 3.14159;

    cout << "size of x: " << sizeof(x) << endl;
    cout << "size of y: " << sizeof(y) << endl;
    cout << "size of z: " << sizeof(z) << endl;
    cout << "size of pie: " << sizeof(pie) << endl;

    // Task 5  Attempt to assign the wrong type of thing to a variable
    // x = "felix"; 
    // It is a compilation error with a type mismatch


    //
    // Conditions
    //

    // Task 6  Testing for a range
    if (y>=10 && y<=20) {
      cout << "y is between 10 and 20(inclusive)" << endl;
    } else {
      cout << "y is not between 10 and 20(inclusive)" << endl;
    }

    //
    // Loops and files
    //

    // Task 7  Looping, printing values 10 to 20 inclusive

    // First with a for loop
    for (int num = 10; num < 21; num++) {
      cout << num << " ";
    }
     cout << endl; 


    // Then with a while loop
    int car = 10;
    while (car < 21) {
      cout << car << " ";
      car++;
    }
    cout << endl;


    // Finally with a do-while loop
    int com = 10;
    do {
      cout << com << " ";
      com++;
    } while (com < 21);
    cout << endl;

 
    // Task 8  Looping to successfully open a file, asking user for the name
    ifstream ifs;
    do {
      string filename;

      cout << "Enter the filename: ";
      cin >> filename;

      ifs.open(filename);

      if (!ifs) {
        cout << "Can't open the file, Try again" <<endl;
      }
    } while (!ifs);


    // Task 9  Looping, reading file word by "word".
    string wrd;

    while (ifs >> wrd){
    cout << wrd << endl;
    }

    ifs.close();

    // Task 10 Open a file of integers, read it in, and display the sum.
    int yom;
    int sum = 0;
    ifstream integ("integers.txt");

    if (!integ) {
      cout << "can't open the file" <<endl;
      exit(1);
    }

    while (integ >> yom) {
      sum += yom;
    }
    cout << sum << endl;

    integ.close();


    // Taks 11 Open and read a file of integers and words. Display the sum.
    int yom2;
    int sum2 = 0;
    ifstream intege("integers.txt");

    if (!intege) {
      cout << "can't open the file" <<endl;
      exit(1);
    }

    while (intege >> yom2) {
      sum2 += yom2;
    }
    cout << sum2 << endl;

    intege.close();


    //
    // Vectors
    //

    // Task 12 Filling a vector of ints
   vector<int> vec;

   for (int i=10; i < 101; i++) {

    if (i%2==0) {
      vec.push_back(i);
    }

   }
    // Task 13 Displaying the vector THREE times
    //         a) using the indices,
    for (size_t i = 0; i < vec.size(); ++i) {
    cout << vec[i];
    }
    cout << endl;


    //         b) using a "ranged for"
    for (int x :vec) {
      cout << x;
    }

    cout<<endl;

    //         c) using indices again but backwards
    for (size_t i = vec.size(); i > 0; --i) {
    cout << vec[i-1];
    }
    cout << endl;

    // Task 14. Initialize a vector with the primes less than 20. 
    vector<int> vec2 = {2,3,5,7,11,13,17,19};
    for (int y :vec2) {
      cout << y << " ";
    }



    }
 // main


