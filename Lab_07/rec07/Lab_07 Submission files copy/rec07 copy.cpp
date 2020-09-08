//
//  main.cpp
//  rec07
//
//  Created by Sarah Xiao on 3/16/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

/*
  rec07
  Starter Code for required functionality
  Yes, you may add other methods.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student;
class Course {
    friend ostream& operator<<(ostream& os, const Course& rhs);
public:
    Course(const string& courseName);
    const string& getName() const;
    bool addStudent(Student*);
    void removeStudentsFromCourse();

private:
    string name;
    vector<Student*> students;
};

class Student {
    friend ostream& operator<<(ostream& os, const Student& rhs);
public:
    Student(const string& name);
    const string& getName() const;
    bool addCourse(Course*);
    void removedFromCourse(Course*);

private:
    string name;
    vector<Course*> courses;
};

class Registrar {
    friend ostream& operator<<(ostream& os, const Registrar& rhs);
public:
    Registrar();
    bool addCourse(const string&);
    bool addStudent(const string&);
    bool enrollStudentInCourse(const string& studentName,
        const string& courseName);
    bool cancelCourse(const string& courseName);
    void purge();

private:
    size_t findStudent(const string&) const;
    size_t findCourse(const string&) const;

    vector<Course*> courses;
    vector<Student*> students;
};
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
    
    
    Registrar::Registrar() {}
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
    
    
    


int main() {

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

    /*
    // [OPTIONAL - do later if time]
    cout << "ChangeStudentName FritzTheCat MightyMouse\n";
    registrar.changeStudentName("FritzTheCat", "MightyMouse");
    cout << registrar << endl;
    cout << "DropStudentFromCourse MightyMouse CS101.001\n";
    registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
    cout << registrar << endl;
    cout << "RemoveStudent FritzTheCat\n";
    registrar.removeStudent("FritzTheCat");
    cout << registrar << endl;
    */

    cout << "Purge for start of next semester\n";
    registrar.purge();
    cout << registrar << endl;
}
