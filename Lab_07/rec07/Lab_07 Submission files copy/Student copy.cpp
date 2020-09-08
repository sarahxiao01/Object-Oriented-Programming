//
//  main.cpp
//  Student
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
    Student::Student(const string& name) : name(name) {}
    ostream& operator<<(ostream& os, const Student& rhs) {
        os << rhs.name << ":";
        if (rhs.courses.size() > 0) {
        for (size_t ind = 0; ind < rhs.courses.size(); ++ind ) {
            os << rhs.courses[ind]->getName() << endl;
        }
        }
        else {
            os << "No Courses" << endl;
            }
        return os;
        }
    const string& Student::getName() const {
        return name;
        }
    bool Student::addCourse(Course* mypointer) {
        if (mypointer != nullptr) {
            courses.push_back(mypointer);
            return true;
            }
        else {
            return false;
        }
        }
    void Student::removedFromCourse(Course* mypointer) {
        for (size_t ind = 0; ind < courses.size(); ++ind) {
            if (mypointer == courses[ind]) {
                *courses[ind], *courses[courses.size() - 1] = *courses[courses.size() - 1], *courses[ind];
        }
        }
        courses.pop_back();
}
}
