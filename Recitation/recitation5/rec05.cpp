/*
FileName: rec05.cpp
Name: Maddhav Suneja
Program: Student record management
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Section {

    class TimeSlot;
    class StudentRecord;
    friend ostream& operator<<(ostream& os, const Section& section);
    friend ostream& operator<<(ostream& os, const TimeSlot& ts);
    friend ostream& operator<<(ostream& os, const StudentRecord& sr);

public:
    Section(const string& sectionName, const string& dy, int hr)
        : name(sectionName), timeSlot(dy, hr) {}

    
    Section(const Section& other) 
        : name(other.name), timeSlot(other.timeSlot) {
        for (const StudentRecord* student : other.students) {
            students.push_back(new StudentRecord(*student)); 
        }
    }

    void addStudent(const string& studentName) {
        students.push_back(new StudentRecord(studentName));
    }

    void addGrade(const string& studentName, int grade, size_t week) {
        for (StudentRecord* student : students) {
            if (student->getName() == studentName) {
                student->addGrade(grade, week);
                break;
            }
        }
    }

    
    ~Section() {
        cout << "Section " << name << " is deleted" << endl;
        for (StudentRecord* student : students) {
            cout << "Deleting " << student->getName() << endl;
            delete student;
        }
        students.clear();
    }

private:
    class TimeSlot {
      friend ostream& operator<<(ostream& os, const TimeSlot& ts);
    public:
        TimeSlot(const string& day, int hour) : day(day), hour(hour) {}
        const string& getDay() const { return day; }
        int getHour() const { return hour; }
    private:
        string day;
        int hour;
    };

    class StudentRecord {
      friend ostream& operator<<(ostream& os, const StudentRecord& sr);
    public:
        StudentRecord(const string& name) : name(name), grades(14, -1) {}
        const string& getName() const { return name; }
        void addGrade(int grade, size_t week) { grades[week - 1] = grade; }
    private:
        string name;
        vector<int> grades;
    };

    string name;
    TimeSlot timeSlot;
    vector<StudentRecord*> students;
};

class LabWorker {
    friend ostream& operator<<(ostream& os, const LabWorker& lw);
public:
    LabWorker(const string& name) : name(name), sec(nullptr) {}

    void addSection(Section& newSection) {
        sec = &newSection;
    }

    void addGrade(const string& studentName, int grade, size_t week) {
        if (sec) {
            sec->addGrade(studentName, grade, week);
        }
    }

private:
    string name;
    Section* sec;
};

void doNothing(Section sec) { cout << sec << endl; }

int main()
{

    cout << "Test 1: Defining a section\n";
     Section secA2("A2", "Tuesday", 16);
     cout << secA2 << endl;

    cout << "\nTest 2: Adding students to a section\n";
     secA2.addStudent("John");
     secA2.addStudent("George");
     secA2.addStudent("Paul");
     secA2.addStudent("Ringo");
     cout << secA2 << endl;

    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    cout << moe << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);  
    moe.addGrade("Paul", 19, 1);  
    moe.addGrade("George", 16, 1);  
    moe.addGrade("Ringo", 7, 1);  
    cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);  
    moe.addGrade("Paul", 20, 3);  
    moe.addGrade("Ringo", 0, 3);  
    moe.addGrade("George", 16, 3);  
    cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";

    cout << "\nTest 9: Copy Constructor: make sure the following calls work:\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n" << secA2 << endl;

} // main

ostream& operator<<(ostream& os, const Section::TimeSlot& ts) {
    os << "Time slot: [Day: " << ts.getDay() << ", Start time: ";
    if (ts.getHour() >= 12) {
        os << ((ts.hour == 12 ? 12 : ts.hour) - 12) << "PM";
    } else {
        os << (ts.getHour() == 0 ? 12 : ts.getHour()) << "AM";
    }
    return os;
}

ostream& operator<<(ostream& os, const Section::StudentRecord& sr) {
    os << "Student: " << sr.getName() << ", Grades: ";
    for (int grade :sr.grades) {
        os << grade << " ";
    }
    return os;
}

ostream& operator<<(ostream& os, const Section& section) {
    os << "Section: " << section.name << ", " << section.timeSlot << endl;
    os << "Students: " << endl;
    for (const Section::StudentRecord* student : section.students) {
        os << *student << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, const LabWorker& lw) {
    os << "Lab Worker: " << lw.name << endl;
    if (lw.sec) {
        os << *lw.sec;
    }
    return os;
}