/*
  Name: Maddhav Suneja
  rec08_single.cpp
  Starter Code for required functionality

  Yes, of course, you may add other methods.

  And no, this won't compile. You have to fix the cyclic association
  and implement the methods.
  
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student;

class Course {
    friend ostream& operator<<(ostream& os, const Course& rhs);
public:
    // Course methods needed by Registrar
    Course(const string& courseName);
    const string& getName() const;
    bool addStudent(Student*);

    // Tell the students that they are no longer in the course
    void removeStudentsFromCourse(); 

private:
    string name;
    vector<Student*> students;
}; // Course

class Student {
    friend ostream& operator<<(ostream& os, const Student& rhs);
public:
    // Student methods needed by Registrar
    Student(const string& name);
    const string& getName() const;
    bool addCourse(Course*);

    // Student method needed by Course::removeStudentsFromCourse
    void removedFromCourse(Course*);

private:
    string name;
    vector<Course*> courses;
}; // Student

class Registrar {
    friend ostream& operator<<(ostream& os, const Registrar& rhs);
public:
    Registrar();

    // Creates a new course, if none with that name
    bool addCourse(const string&);
    // Creates a new student, if none with that name
    bool addStudent(const string&);

    // If the student and the course exist, then enroll the student.
    bool enrollStudentInCourse(const string& studentName,
                               const string& courseName);

    // Unenroll the students from the course and remove the course
    // from the Registrar.
    bool cancelCourse(const string& courseName);

    // Get rid of everything!!!
    void purge();

private:
    size_t findStudent(const string&) const;
    size_t findCourse(const string&) const;

    vector<Course*> courses;
    vector<Student*> students;
}; // Registrar

int main()
{

    Registrar registrar;

    cout << "No courses or students added yet\n";
    cout << registrar << endl;
     
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    cout << registrar << endl;

    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    cout << registrar << endl;

    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout << "Should fail, i.e. do nothing, "
         << "since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    cout << registrar << endl;

    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    cout << registrar << endl;
   
    cout << "Purge for start of next semester\n";
    registrar.purge();
    cout << registrar << endl;
} // main
  
// Course class definitions
Course::Course(const string& courseName) : name(courseName) {}

const string& Course::getName() const { return name; }

bool Course::addStudent(Student* studentp) {
    if (studentp->addCourse(this)) {
        students.push_back(studentp);
        return true;
    }
    return false;
}

void Course::removeStudentsFromCourse() {
    for (Student* studentp : students) {
        studentp->removedFromCourse(this);
    }
    students.clear();
}

ostream& operator<<(ostream& os, const Course& rhs) {
    os << rhs.name << ": ";
    if (rhs.students.empty()) {
        os << "No Students";
    } else {
        for (const Student* studentp : rhs.students) {
            os << studentp->getName() << " ";
        }
    }
    return os;
}

// Student class definitions
Student::Student(const string& studentName) : name(studentName) {}

const string& Student::getName() const { return name; }

bool Student::addCourse(Course* coursep) {
    for (const Course* c : courses) {
        if (c == coursep) return false;  // Already enrolled
    }
    courses.push_back(coursep);
    return true;
}

void Student::removedFromCourse(Course* coursep) {
    for (size_t i = 0; i < courses.size(); ++i) {
        if (courses[i] == coursep) {
            courses[i] = courses.back(); // if order matters shift down
            courses.pop_back();
            return;
        }
    }
}

ostream& operator<<(ostream& os, const Student& rhs) {
    os << rhs.name << ": ";
    if (rhs.courses.empty()) {
        os << "No Courses";
    } else {
        for (const Course* coursep : rhs.courses) {
            os << coursep->getName() << " ";
        }
    }
    return os;
}

// Registrar class definitions
Registrar::Registrar() {}

bool Registrar::addCourse(const string& courseName) {
    if (findCourse(courseName) == courses.size()) {
        courses.push_back(new Course(courseName));
        return true;
    }
    return false;
}

bool Registrar::addStudent(const string& studentName) {
    if (findStudent(studentName) == students.size()) {
        students.push_back(new Student(studentName));
        return true;
    }
    return false;
}

bool Registrar::enrollStudentInCourse(const string& studentName, const string& courseName) {
    size_t studentIndex = findStudent(studentName);
    size_t courseIndex = findCourse(courseName);
    if (studentIndex < students.size() && courseIndex < courses.size()) {
        return courses[courseIndex]->addStudent(students[studentIndex]);
    }
    return false;
}

bool Registrar::cancelCourse(const string& courseName) {
    size_t courseIndex = findCourse(courseName);
    if (courseIndex < courses.size()) {
        courses[courseIndex]->removeStudentsFromCourse();
        delete courses[courseIndex];
        courses[courseIndex] = courses.back();
        courses.pop_back();
        return true;
    }
    return false;
}

void Registrar::purge() {
    for (Student* studentp : students) {
        delete studentp;
    }
    students.clear();
    for (Course* coursep : courses) {
        delete coursep;
    }
    courses.clear();
}

size_t Registrar::findStudent(const string& studentName) const {
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i]->getName() == studentName) {
            return i;
        }
    }
    return students.size();
}

size_t Registrar::findCourse(const string& courseName) const {
    for (size_t i = 0; i < courses.size(); ++i) {
        if (courses[i]->getName() == courseName) {
            return i;
        }
    }
    return courses.size();
}

ostream& operator<<(ostream& os, const Registrar& rhs) {
    os << "Registrar's Report\nCourses:\n";
    for (const Course* coursep : rhs.courses) {
        os << *coursep << endl;
    }
    os << "Students:\n";
    for (const Student* studentp : rhs.students) {
        os << *studentp << endl;
    }
    return os;
}
