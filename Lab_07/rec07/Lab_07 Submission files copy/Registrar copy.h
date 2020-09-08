//
//  main.cpp
//  Registrar_
//
//  Created by Sarah Xiao on 3/19/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#ifndef Registrar_h
#define Registrar_h
#include "Course.h"
#include "Student.h"
#include <iostream>
#include <vector>
#include <string>

namespace BrooklynPoly {
    class Student;
    class Course;
    class Registrar {
        friend std::ostream& operator<<(std::ostream& os, const Registrar& rhs);
    public:
        Registrar();
        bool addCourse(const std::string&);
        bool addStudent(const std::string&);
        bool enrollStudentInCourse(const std::string& studentName,
            const std::string& courseName);
        bool cancelCourse(const std::string& courseName);
        void purge();
    private:
        size_t findStudent(const std::string&) const;
        size_t findCourse(const std::string&) const;
        std::vector<Course*> courses;
        std::vector<Student*> students;
     };
}
#endif
