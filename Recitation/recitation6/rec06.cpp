/*
  rec06.cpp
  CS2124
 
  Focus: Dynamic arrays and copy control
 */

#include <string>
#include <iostream>
using namespace std;

// 
// Position class
// 
class Position {
    friend ostream& operator<<(ostream& os, const Position& rhs)
    {
        os << '[' << rhs.title << ',' << rhs.salary << ']';
        return os;
    } // Position op<<
public:
    Position(const string& aTitle, double aSalary)
        : title(aTitle), salary(aSalary) {}
    const string& getTitle() const { return title; }
    double getSalary() const { return salary; }
    void changeSalaryTo(double d) { salary = d; }
private:
    string title;
    double salary;
}; // class Position


// 
// Directory class
// 
class Directory {
    // 
    // nested Entry class
    // 
    class Entry {
	friend ostream& operator<<(ostream& os, const Entry& rhs)
        {
	    os << rhs.name << ' ' << rhs.room
	       << ' ' << rhs.phone << ", " << *rhs.pos;
	    return os;
	} // Entry op<<
    public:
	Entry(const string& name, unsigned room, unsigned phone, Position& position)
	    : name(name), room(room), phone(phone), pos(&position) {
	}
	const string& getName() const { return name; }
	unsigned getPhone() const { return phone; }
    private:
	string name;
	unsigned room;
	unsigned phone;
	Position* pos;
    }; // class Entry


    // Overload Directory's output operator
    friend ostream& operator<<(ostream& os, const Directory& rhs) {
        os << "Directory: " << rhs.company << endl;
        for (size_t i = 0; i < rhs.size; ++i) {
            os << *rhs.entries[i] << endl;
        }
        return os;
    }

public:
    Directory(const string& compName) 
        : size(0), capacity(1), company(compName) 
    { 
        entries = new Entry*[capacity];
    }

    // Destructor
    ~Directory() {
        for (size_t i = 0; i < size; ++i) {
            delete entries[i]; // Deleting Entry instances
        }
        delete[] entries; // Deleting the array of pointers
        cout << "Destructor called." << endl;
    }

    // Copy Constructor
    Directory(const Directory& other)
        : size(other.size), capacity(other.capacity), company(other.company)
    {
        entries = new Entry*[capacity];
        for (size_t i = 0; i < size; ++i) {
            entries[i] = new Entry(*other.entries[i]); // Deep copy of each Entry
        }
        cout << "Copy constructor called." << endl;
    }

    // Assignment Operator
    Directory& operator=(const Directory& other) {
        if (this != &other) {
            for (size_t i = 0; i < size; ++i) {
                delete entries[i]; // Free existing entries
            }
            delete[] entries; // Free existing array

            size = other.size;
            capacity = other.capacity;
            company = other.company;
            entries = new Entry*[capacity];

            for (size_t i = 0; i < size; ++i) {
                entries[i] = new Entry(*other.entries[i]); // Deep copy of each Entry
            }
        }
        cout << "Assignment operator called." << endl;
        return *this;
    }

    unsigned operator[](const string& name) const {
        for (size_t i = 0; i < size; ++i) {
            if (entries[i]->getName() == name) {
                return entries[i]->getPhone();
            }
        }
        // Handle the case where the name is not found
        cerr << "Name not found: " << name << endl;
        return 999999999; 
    }

    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
    if (size == capacity) {
        // Double the capacity
        capacity = (capacity == 0) ? 1 : 2 * capacity;
        Entry** newEntries = new Entry*[capacity]; // Allocate new array

        // Copy the entries to the new array
        for (size_t i = 0; i < size; ++i) {
            newEntries[i] = entries[i]; 
        }
        entries = newEntries; // Reassign the new array to entries
        delete[] newEntries; // Free the old array memory
        
    }
    entries[size] = new Entry(name, room, ph, pos); // Create a new Entry
    ++size;
}


private:	
    Entry** entries; // Pointer to Entry pointers.
    size_t size;
    size_t capacity;
    string company;
}; // class Directory

void doNothing(Directory dir) { 
    cout << dir << endl; // Output the directory passed to the function
} // doNothing

int main() {
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
    
    Directory d("HAL");
    d.add("Marilyn", 123, 4567, boss);
    cout << d << endl;
    cout << "d[\"Marilyn\"]: " << d["Marilyn"] << endl;
    cout << "======\n\n";

    Directory d2 = d;	// Copy constructor is called
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    cout << "Directory d:\n" << d << endl;
    cout << "Directory d2:\n" << d2 << endl;

    cout << "Calling doNothing\n";
    doNothing(d2); // Calls doNothing with a copy of d2
    cout << "Back from doNothing\n";

    // Should display 1592
    cout << d2["Carmack"] << endl;

    Directory d3("IBM");
    d3.add("Torvalds", 628, 3185, techie);
    d3.add("Ritchie", 123, 5813, techie);
    
    d2 = d3; // Assignment operator is called
    // Should display 5813
    cout << d2["Ritchie"] << endl;

    cout << d2 << endl;

    return 0;
}
