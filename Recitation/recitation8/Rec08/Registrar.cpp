#include <iostream>
#include <string>
#include <vector>
#include "Course.hpp"
#include "Registrar.hpp"
#include "Student.hpp"
using namespace std;

namespace BrooklynPoly {
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

}