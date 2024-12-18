#include "Course.hpp"
#include "Student.hpp"
using namespace std;

namespace BrooklynPoly {

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
}