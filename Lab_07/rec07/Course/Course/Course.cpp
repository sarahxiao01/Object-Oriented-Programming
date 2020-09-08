//
//  main.cpp
//  Course
//
//  Created by Sarah Xiao on 3/19/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#include "Course.h"
#include "Student.h"
#include "Registrar.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace BrooklynPoly {

    Course::Course(const string& courseName) : name(courseName) {}
    ostream& operator<<(ostream& os, const Course& rhs) {
        os << rhs.name << ":";
        if (rhs.students.size() > 0) {
        for (size_t ind = 0; ind < rhs.students.size(); ++ind ) {
            os << rhs.students[ind]->getName() << endl;
        }
        }
        else {
            os << "No Students" << endl;
            }
        return os;
        }
    const string& Course::getName() const {
        return name;
        }
    bool Course::addStudent(Student* pointer) {
        if (pointer != nullptr) {
            students.push_back(pointer);
            return true;
            }
        else {
            return false;
    }
    }
    void Course::removeStudentsFromCourse() {
        for (size_t ind = 0; ind <students.size(); ++ind){
            students[ind]->removedFromCourse(this);
    }
        students.clear();
}
}
