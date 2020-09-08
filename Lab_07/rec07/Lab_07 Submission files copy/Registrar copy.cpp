//
//  main.cpp
//  Registrar
//
//  Created by Sarah Xiao on 3/19/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#include "Student.h"
#include "Course.h"
#include "Registrar.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


namespace BrooklynPoly {
    ostream& operator<<(ostream& os, const Registrar& rhs) {
        os << "Registrar's Report" << endl;
        os << "Courses:" << endl;
        for (size_t ind = 0; ind < rhs.courses.size(); ++ind ) {
            os << *(rhs.courses[ind]) << endl;
        }
        os << "Students:" << endl;
        for (size_t ind = 0; ind < rhs.students.size(); ++ind ) {
            os << *(rhs.students[ind]) << endl;
    }
        return os;
    }
    Registrar::Registrar() {}
    bool Registrar::addCourse(const string& courseName) {
        for (size_t i = 0; i < courses.size(); ++i) {
            if (courseName == courses[i]->getName() ) {
                return false;
            }
        }
        Course* ptr = new Course(courseName);
        courses.push_back(ptr);
        
        return true;
    }
    bool Registrar::addStudent(const string& studentName) {
        for (size_t j = 0; j < students.size(); ++j) {
            if (studentName == students[j]->getName()) {
                return false;
        }
    }
        Student* pointer = new Student(studentName);
        students.push_back(pointer);
        return true;
        
    }
        
    bool Registrar::enrollStudentInCourse(const string& studentName,
        const string& courseName) {
        for (size_t ind = 0; ind < courses.size(); ++ind) {
            if (courses[ind]->getName() == courseName) {
                for (size_t j = 0; j < students.size(); ++j) {
                if (students[j]->getName() == studentName) {
                        students[j]->addCourse(courses[ind]);
                        currCourse->addStudent(students[j]);
                        return true;
        }
            }
        }
    }
        return false;
    }
    bool Registrar::cancelCourse(const string& courseName) {
        size_t Ind = this->findCourse(courseName);
        if (Ind != courses.size()) {
            courses[Ind]->removeStudentsFromCourse();
            courses[Ind], courses[courses.size()- 1] = courses[courses.size()- 1], courses[Ind];
            courses.pop_back();
            return true;
        }
        else {
        return false;
        }
    }

    void Registrar::purge() {
        for (size_t i = 0; i < courses.size(); ++i) {
            courses[i]->removeStudentsFromCourse();
            courses[i], courses[courses.size()- 1] = courses[courses.size()- 1], courses[i];
            courses.pop_back();
        }
        students.clear();
        courses.clear();
    }

    size_t Registrar::findStudent(const string& studentName) const {
        for (size_t ind = 0; ind < students.size(); ++ind) {
            if (students[ind]->getName() == studentName) {
                return ind;
    }
    }
            else {
        return students.size();
        }
    }

    size_t Registrar::findCourse(const string& courseName) const {
        for (size_t ind = 0; ind < courses.size(); ++ind) {
            if (courses[ind]->getName() == courseName) {
                return ind;
        }
        }
            else {
        return courses.size();
        }
    }
        }
        

