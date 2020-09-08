//
//  main.cpp
//  rec05
//
//  Created by Sarah Xiao on 2/28/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Section {
    friend ostream& operator << (ostream& os, const Section& mySection);

    class Studentrecord {
    public:
        Studentrecord(const string& studentname, vector<int> grades): myname (studentname), mygrades ({-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}) {}
//        getter functions of name and grade records in sections
        const string& getstudentname()const {
            return myname;
            }
        const vector<int>& getmygrades() const {
            return mygrades;
            }
        void displaymygrades () {
            for (size_t i = 0; i < mygrades.size(); ++i) {
            cout << mygrades[i]<< " ";
            }
        void gradeupdate (int newgrade, int week){
            mygrades[week] = newgrade;
            }
            
    private:
        string myname;
        vector<int> mygrades;
        };
     class Timeslot {

        public:
         Timeslot(const string& day, int time): myDay(day), myTime(time) {};

            const string& getday() const {
                return myDay;
            }
            const int& gettime()const {
                return myTime;
            }
        private:
            string myDay;
            int myTime;
            };
public:
    Section (const string& sectionname, const string& theday, const int& thetime): thename(sectionname), theslot(theday, thetime) {};
    void addStudent (const string& newname){
        Studentrecord* newpt = new Studentrecord(newname);
        recordvec.push_back(newpt);
        }
        
    void studentGrade (const string& stuname, int hisgrade, int hisweek){
        for (Studentrecord* hisrec: thegraderecords) {
            if (hisrec.getstudentname() == stuname) {
                hisrec.gradeupdate(hisgrade, hisweek)
            }
                }
        }

        
    const string& getname() const {
        return thename;
    }
    const string& getslotday()const {
        return theslot.getday();
    }
    const string& getslottime()const {
        return theslot.gettime();
    }
    
        ~Section(){
            cout << "Section" << thename << "is being deleted" << endl;
            for (Studentrecord* hisrec: thegraderecords) {
                cout << "Deleting" << hisrec << endl;
                delete record;
        }
        }
        
private:
   
        
    


        string thename;
        Timeslot theslot;
        vector<Studentrecord*> thegraderecords;
};
    
    ostream& operator <<(ostream& os, Section& mySection) {
    os << "Section:" << mySection.getname() << ", Time slot:" << "[Day:" << mySection.getday() << ", Start time:" << mySection.gettime() << "], Students:" << mySection.ifstudents() << endl;
        if (mySection.gettime()>12) {
            os << mySection.gettime() -12 << "pm]" << endl;
        }
        else {
            os << mySection.gettime() << "am]" << endl;
        }
    
        return os;
        }


class LabWorker {
    friend ostream& operator << (ostream& os, const Labworker& theworker);
    
public:
    LabWorker (string const& Workername): hisname(Workername), hispointer(nullptr){};
    string getworkername () const {
        return hisname;
    }
    void addSection (Section& mySection){
        this->hispointer = &mySection;
    }
    void addGrade (const string& somename, int somegrade, int someweek){
        hispointer->studentGrade (somename, int somegrade, int someweek);
    }
    

private:
    string hisname;
    Section* hispointer;
};
    ostream& operator <<(ostream& os, LabWorker& theworker) {
        os << theworker.getworkername();
        if (theworker.hispointer == mullptr){
            os << "does not have a lab section";
        }
        else {
            os << "has"<<  *theworker.hispointer;
            
        }
        return os;
    }
        


// Test code
void doNothing(Section sec) { cout << sec << endl; }

int main() {
    cout << "Test 1: Defining a section\n";
    // Section secA2("A2", "Tuesday", 16);
    // cout << secA2 << endl;

    cout << "\nTest 2: Adding students to a section\n";
    // secA2.addStudent("John");
    // secA2.addStudent("George");
    // secA2.addStudent("Paul");
    // secA2.addStudent("Ringo");
    // cout << secA2 << endl;

    cout << "\nTest 3: Defining a lab worker.\n";
    // LabWorker moe( "Moe" );
    // cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    // moe.addSection( secA2 );
    // cout << moe << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    // LabWorker jane( "Jane" );
    // Section secB3( "B3", "Thursday", 11 );
    // secB3.addStudent("Thorin");
    // secB3.addStudent("Dwalin");
    // secB3.addStudent("Balin");
    // secB3.addStudent("Kili");
    // secB3.addStudent("Fili");
    // secB3.addStudent("Dori");
    // secB3.addStudent("Nori");
    // secB3.addStudent("Ori");
    // secB3.addStudent("Oin");
    // secB3.addStudent("Gloin");
    // secB3.addStudent("Bifur");
    // secB3.addStudent("Bofur");
    // secB3.addStudent("Bombur");
    // jane.addSection( secB3 );
    // cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
    // moe.addGrade("John", 17, 1);
    // moe.addGrade("Paul", 19, 1);
    // moe.addGrade("George", 16, 1);
    // moe.addGrade("Ringo", 7, 1);
    // cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    // moe.addGrade("John", 15, 3);
    // moe.addGrade("Paul", 20, 3);
    // moe.addGrade("Ringo", 0, 3);
    // moe.addGrade("George", 16, 3);
    // cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
         << "then make sure the following call works:\n";
    // doNothing(secA2);
    // cout << "Back from doNothing\n\n";

} // main

1. Defining a section
2. Adding students to a section
3. Defining a lab worker.
4. Adding a section to a lab worker.
5. Adding a second section and lab worker.
6. Adding some grades for week one
7. Adding some grades for week three (skipping week 2)
8. We're done
9. IF you have covered copy constructors in lecture, then make sure the following call works


cout << "Section:" << sectionname << ", Time slot:" << "[Day:" << Tuesday << ", Start time:" << 4pm << "], Students:" << endl;
if Students is empty {
    cout << "None"
}
else
for i in range size_t Students {
cout << "Name:" << name << ", Grades:" << grade = -1 << students << endl;
}

if worker has a Section
worker.Section != nullptr;
cout << Moename << " has Section:" << name << ", Time slot: [Day:" << Tuesday << ", Start time:" <<  4pm << "], Students:" << endl;

for i in range size_t Students {
cout << "Name:" << name << ", Grades:" << grade = -1 << students << endl;
}

else {
cout << worker << "does not have a section" << endl;
}



What should happen to all those students (or rather their records?)



