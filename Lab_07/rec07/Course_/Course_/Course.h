//
//  main.cpp
//  Course_
//
//  Created by Sarah Xiao on 3/19/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#ifndef Course_h
#define Course_h

#include "Student.h"
#include "Registrar.h"
#include <string>
#include <ostream>
#include <vector>

namespace BrooklynPoly {
    class Student;
    class Registrar;
    class Course {
        friend std::ostream& operator<<(std::ostream& os, const Course& rhs);
    public:
        Course(const std::string& courseName);
        const std::string& getName() const;
        bool addStudent(Student*);
        void removeStudentsFromCourse();

    private:
        std::string name;
        std::vector<Student*> students;
    };
}
#endif
