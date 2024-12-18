/*
  oop2.cpp
  CS2124
  24F - Sec A
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// class Date {
//     friend ostream& operator<<(ostream& os, const Date& rhs);
// public:
//     Date(int m, int d, int y) : month(m), day(d), year(y) {}

// private:
//     int month, day, year;
// };

class Person {
    friend ostream& operator<<(ostream& os, const Person& rhs);
public:
    // publicly nested
    class Date {
        friend ostream& operator<<(ostream& os, const Date& rhs);
    public:
        Date(int m, int d, int y) : month(m), day(d), year(y) {}

    private:
        int month, day, year;
    };

    //Person(const string& name) : name(name) { }
    //Person(const string& name) : name(name), bday() { }
    Person(const string& name, int m, int d, int y)
        //: name(name) { }
        //: name(name), bday(Date(m,d,y)) { }
        : name(name), bday(m,d,y)[p;ppp-0[p-0-p]] { }
private:    
    string name;
    Date bday;
};

int main()
{
    //Person john("John");
    Person john("John", 3, 15, 2004);
    cout << john << endl;

    //Date independenceDay(7, 4, 1776);
    Person::Date independenceDay(7, 4, 1776);
    cout << independenceDay << endl;
} // main

ostream& operator<<(ostream& os, const Person& rhs)
{
    //os << "Person: " << rhs.name; //  << ", dob: " << rhs.bday;
    os << "Person: " << rhs.name  << ", dob: " << rhs.bday;
    return os;
}

//ostream& operator<<(ostream& os, const Date& rhs)
ostream& operator<<(ostream& os, const Person::Date& rhs)
{
    os << rhs.month << '/' << rhs.day << '/' << rhs.year;
    return os;
} // Date op<<

