//
//  main.cpp
//  Student_
//
//  Created by Sarah Xiao on 3/19/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include "Course.h"
#include "Registrar.h"
#include <iostream>
#include <vector>
#include <string>

namespace BrooklynPoly {
    class Course;
    class Student {
        friend std::ostream& operator<<(std::ostream& os, const Student& rhs);
    public:
        Student(const std::string& name);
        const std::string& getName() const;
        bool addCourse(Course* mycourse);
        void removedFromCourse(Course* mycourse);

    private:
        std::string name;
        std::vector<Course*> courses;
    };

}
#endif
