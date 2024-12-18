/*
  rec07_begin.cpp
  CS2124
  Name: Maddhav Suneja
  Implement the class Rational, so that the following program works.
*/

#include <iostream>
using namespace std;

int greatestCommonDivisor(int x, int y);

// Put your Rational class here.
class Rational {
    friend ostream& operator<<(ostream& os, const Rational& rhs ){
        os << rhs.num << "/" << rhs.denom;
        return os;
    }

    friend istream& operator>>(istream& is,  Rational& rhs){
        char skip;
        is >> rhs.num >> skip >> rhs.denom;
        rhs.normalize();
        return is;
    }


    friend bool operator==(const Rational& rat1, const Rational& rat2);
    friend bool operator<(const Rational& rat1, const Rational& rat2);

    public:
       Rational(int num = 0, int denom = 1) : 
       num(num),denom(denom) {normalize();}
       

       Rational& operator+=(const Rational& rhs){
        num = rhs.num * denom + rhs.denom * num;
        denom *= rhs.denom;
        normalize();
        return *this;
       }

       Rational& operator++() {
        num += denom;
        return *this;
        }
        
       Rational operator++(int dum) {
        Rational original(*this);
        ++(*this);
        return original;
        }

       explicit operator bool() const { 
        return num != 0; 
       }


    private:
       int num;
       int denom;

       void normalize() {
          int gcd = greatestCommonDivisor(abs(num), abs(denom));
          num /= gcd;
          denom /= gcd;
          if (denom < 0) {
             num *= -1;
             denom *= -1;
          }
        }

};

int greatestCommonDivisor(int x, int y)
{
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}



// Any functions that are not members and not friends should have
// prototypes here and their definitions after main.

Rational operator+(const Rational& rat1, const Rational& rat2);
bool operator!=(const Rational& rat1, const Rational& rat2);
bool operator<=(const Rational& rat1, const Rational& rat2);
bool operator>(const Rational& rat1, const Rational& rat2);
bool operator>=(const Rational& rat1, const Rational& rat2);
Rational& operator--(Rational& thang);
Rational operator--(Rational& thang, int);

int main()
{
    Rational a, b;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "a: ";
    cin >> a;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "b: ";
    cin >> b;
    const Rational one = 1;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;	// Implement as member
    cout << "a = " << a << endl;
    
    // Implement + as non-member, but not a friend
    cout << "a + one: " << (a + one) << endl;
    cout << "a == one: " << boolalpha << (a == one) << endl;
    
    // How does this manage to work?
    // It does NOT require writing another == operator. 
    cout << "1 == one: " << boolalpha << (1 == one) << endl;
    
    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;

    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;
    // a.operator--()
    //operator--(a)
    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;

    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;

    // Even though the above example, (a++ ++), compiled, the
    // following shouldn't.
    // But some compiler vendors might let it...  Is your compiler
    // doing the right thing? Why shouldn't it compile?
    //cout << "a-- -- = " << (a-- --) << endl;
    cout << "a = " << a << endl;


    // Should report that 1 is true
    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    } 

    // Should report that 0 is false
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    } 

    cout << "Comparisons\n";
    Rational twoFifths(2, 5);
    Rational threeHalves(3, 2);
    Rational minusFive(-5);
    cout << twoFifths << " < " << threeHalves << " : " 
         << (twoFifths < threeHalves) << endl;
    cout << twoFifths << " <= " << 1 << " : " << (twoFifths <= 1) << endl;
    cout << threeHalves << " < " << twoFifths << " : "
         << (threeHalves < twoFifths) << endl;
    cout << threeHalves << " > " << threeHalves << " : "
         << (threeHalves > threeHalves) << endl;
    cout << threeHalves << " >= " << threeHalves << " : "
         << (threeHalves >= threeHalves) << endl;
    cout << minusFive << " >= " << threeHalves << " : "
         << (minusFive >= threeHalves) << endl;
}


// Any functions that are not members and not friends should have
// their definitions here...

bool operator==(const Rational& rat1, const Rational& rat2){
    return rat1.num == rat2.num && rat1.denom == rat2.denom;
}

Rational operator+(const Rational& rat1, const Rational& rat2){
    Rational result(rat1);
    result += rat2;
    return result;
}

bool operator<(const Rational& rat1, const Rational& rat2){
    return rat1.num * rat2.denom < rat2.num * rat1.denom;
}

bool operator!=(const Rational& rat1, const Rational& rat2){
    return !(rat1 == rat2);
}

bool operator<=(const Rational& rat1, const Rational& rat2){
    return (rat1 < rat2 || rat1 == rat2);
}

bool operator>(const Rational& rat1, const Rational& rat2){
    return !(rat1 <= rat2);
}

bool operator>=(const Rational& rat1, const Rational& rat2){
    return !(rat1 < rat2);
}

Rational& operator--(Rational& thang){
    thang += -1;
    return thang;
}

Rational operator--(Rational& thang, int) {
    Rational original(thang);
    --(thang);
    return original;
}