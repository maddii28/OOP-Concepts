/*
  FileName: hw06.cpp
  Name: Maddhav Suneja
  Description: Writing BigUnsigned class that inputs a num in certain
  condition and operators overloaded for it.
*/

//all the include statements
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Put your class and all function definitions here.

//BigUnsigned manages numbers in a vector and 
//has multiple operators overloaded to perform functions
class BigUnsigned {

     friend ostream& operator<<(ostream& os, const BigUnsigned& rhs){
          for (size_t i = rhs.digits.size(); i!=0; --i){
               os << rhs.digits[i-1];
          }
          return os;
     }

     friend bool operator==(const BigUnsigned& big1, const BigUnsigned& big2);
     friend bool operator<(const BigUnsigned& big1, const BigUnsigned& big2);

public:
     BigUnsigned(int num = 0) {
          if (num == 0) {
               digits.push_back(0);
          } else {
               while (num > 0) {
                    int digit = num % 10;
                    digits.push_back(digit);
                    num /= 10;
               }
          }
     }

     BigUnsigned(const string& snum) {
          bool founddig = false;
          for (size_t i = 0; i < snum.size(); ++i){
               if (snum[i]>= '0' && snum[i] <= '9') {
                    int dig = snum[i] - '0';
                    if (dig != 0  || founddig){
                         digits.push_back(dig);
                         founddig = true;
                    }
               } else if(founddig == false) {
                    digits.push_back(0);
                    break;
               } else if(founddig == true) {
                    break;
               }
          }
          if (digits.size() == 0){
               digits.push_back(0);
          }

          vector<int> reversed_digits;
          for (size_t i = digits.size(); i>0; --i ){
               reversed_digits.push_back(digits[i-1]);
          }
          digits = reversed_digits;

     }

     BigUnsigned& operator+=(BigUnsigned rhs){
          if (digits.size() > rhs.digits.size() || 
          rhs.digits.size() > digits.size() ){
               if (digits.size() > rhs.digits.size()){
                    for (size_t i = 0; i< (digits.size()- rhs.digits.size())+1; 
                    ++i){
                         rhs.digits.push_back(0);
                    }
               }
               if (rhs.digits.size() > digits.size()){
                    for (size_t i = 0; i<(rhs.digits.size()- digits.size())+1; 
                    ++i){
                         digits.push_back(0);
                    }                  
               }
          }
          for (size_t i = 0; i < rhs.digits.size(); ++i){
               digits[i] += rhs.digits[i];
               if (digits[i] >= 10){
                    digits[i] = digits[i] % 10;
                    if (i+1 == digits.size()){
                         digits.push_back(1);
                    }
                    else{
                         digits[i+1] += 1;
                    }
               }
          }
          return *this;
     }

     BigUnsigned& operator++() {
          BigUnsigned one(1);
          *this += one;
          return *this;
     }

     BigUnsigned operator++(int dum) {
          BigUnsigned original(*this);
          ++(*this);
          return original;
     }

     explicit operator bool() const { 
          return !(digits.size() == 1 && digits[0] == 0);
     }


private:
     vector<int> digits;
};

//Function definitions for operators that are non members and non friends
BigUnsigned operator+(const BigUnsigned& big1, const BigUnsigned& big2);
bool operator!=(const BigUnsigned& big1, const BigUnsigned& big2);
bool operator<=(const BigUnsigned& big1, const BigUnsigned& big2);
bool operator>(const BigUnsigned& big1, const BigUnsigned& big2);
bool operator>=(const BigUnsigned& big1, const BigUnsigned& big2);

//All the main code
int main()
{
    BigUnsigned zero;
    BigUnsigned one(1);

    cout << "zero: " << zero << endl;
    cout << "one: " << one << endl;

    BigUnsigned val = 1;
    cout << "val: " << val << endl;
    cout << "++val: " << ++val << endl;
    cout << "val: " << val << endl;
    cout << "val++: " << val++ << endl;
    cout << "val: " << val << endl;

    cout << "(one + zero): " << (one + zero) << endl;
    cout << "(one + one): " <<  (one + one) << endl;

    cout << boolalpha;
    cout << "one < one: " << (one < one) << endl;
    cout << "zero < one: " << (zero < one) << endl;

    BigUnsigned a = 123;
    BigUnsigned b = 1234;
    BigUnsigned c = 124;
    BigUnsigned d = 12345;

    cout << "a: " << a << ", b: " << b 
         << ", c: " << c << ", d: " << d << endl;
    cout << "a + d: " << (a + d) << endl;
    cout << "d + d: " << (d + d) << endl;
    cout << "a < d: " << (a < d) << endl;
    cout << "d < a: " << (d < a) << endl;
    cout << "zero == zero: " << (zero == zero) << endl
         << "zero == one: " << (zero == one) << endl
         << "a == a: " << (a == a) << endl
         << "a == d: " << (a == d) << endl
         << "d == a: " << (d == a) << endl;

    cout << "(zero == 0): " << (zero == 0) << endl
         << "(one == 0): " << (one == 0) << endl
         << "(1 == one): " << (1 == one) << endl;

    // +=
    cout << "b: " << b << ", c: " << c << endl;
    cout << "(c += b): " << (c += b) << endl;
    cout << "b: " << b << ", c: " << c << endl;


    BigUnsigned x = a;
    cout << "x: " << x << ", a: " << a << endl
         << "x == a: " << (x == a) << endl
         << "a == x: " << (a == x) << endl
         << "a < x: " << (a < x) << endl
         << "a > x: " << (a > x) << endl;

    cout << "x > a: " << (x > a) << endl
         << "x >= a: " << (x >= a) << endl
         << "x <= a: " << (x <= a) << endl
         << "x != a: " << (x != a) << endl;


    BigUnsigned big("987654321");
    BigUnsigned big2("  ");
    BigUnsigned big3("felix");
    BigUnsigned big4("00987654321");

    cout << "big: " << big << endl
         << "big2: " << big2 << endl
         << "big3: " << big3 << endl
         << "big4: " << big4 << endl;

    BigUnsigned big5(98765);
    BigUnsigned big6(2457);
    cout << "big5: " << big5  << ", big6: " <<  big6 << endl
         << "(big5 + big6): " << (big5 + big6) << endl
         << "(big6 + big5): " << (big6 + big5) << endl;


    // How does this work?
    cout << zero << " is " << (zero ? "true" : "false") << endl;
    cout << one << " is " << (one ? "true" : "false") << endl;
    cout << big4 << " is " << (big4 ? "true" : "false") << endl;
} // main

//Utilises operator+= to add two BigUnsigned
BigUnsigned operator+(const BigUnsigned& big1, const BigUnsigned& big2){
     BigUnsigned result(big1);
     result += big2;
     return result;
}

//Utilises friend access to check equality
bool operator==(const BigUnsigned& big1, const BigUnsigned& big2){
     return big1.digits == big2.digits;
}

//Utilises operator== to check non-equality
bool operator!=(const BigUnsigned& big1, const BigUnsigned& big2){
     return !(big1 == big2);
}

//Utilises friend access to check less than
bool operator<(const BigUnsigned& big1, const BigUnsigned& big2){
     if (big1.digits.size() < big2.digits.size()) {
          return true;  
     }
     if (big1.digits.size() > big2.digits.size()) {
          return false; 
     }
     for (size_t temp = big1.digits.size(); temp > 0; --temp) {
          if (big1.digits[temp - 1] < big2.digits[temp - 1]) {
               return true;
          }
          if (big1.digits[temp - 1] > big2.digits[temp - 1]) {
               return false; 
          }
     }
     return false; 
}

//Utilises operator< and operator== to check less than or equal to
bool operator<=(const BigUnsigned& big1, const BigUnsigned& big2){
     return (big1 < big2 || big1 == big2);
}

//Utilises operator<= to check greater than
bool operator>(const BigUnsigned& big1, const BigUnsigned& big2){
     return !(big1 <= big2);
}

//Utilises operator< to check greator than or equal to
bool operator>=(const BigUnsigned& big1, const BigUnsigned& big2){
     return !(big1 < big2);
}