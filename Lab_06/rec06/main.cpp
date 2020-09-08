//
//  main.cpp
//  rec06
//
//  Created by Sarah Xiao on 3/6/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#include <string>
#include <iostream>
using namespace std;

class Position {
    friend ostream& operator<<(ostream& os, const Position& rhs) {
        os << '[' << rhs.title << ',' << rhs.salary << ']';
        return os;
    }
public:
    Position(const string& aTitle, double aSalary)
        : title(aTitle), salary(aSalary) {}
    const string& getTitle() const { return title; }
    double getSalary() const { return salary; }
    void changeSalaryTo(double d) { salary = d; }
private:
    string title;
    double salary;
}; // class Position

class Entry {
    friend ostream& operator<<(ostream& os, const Entry& rhs) {
        os << rhs.name << ' ' << rhs.room
           << ' ' << rhs.phone << ", " << *rhs.pos;
        return os;
    }
public:
    Entry(const string& name, unsigned room, unsigned phone, Position& position)
        : name(name), room(room), phone(phone), pos(&position) {
    }
    const string& getName() const { return name; }
    unsigned getPhone() const { return phone; }
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // class Entry

class Directory {
    // Overload output operator
    friend ostream& operator <<(ostream& os, const Directory& dir) {
        for (size_t ind=0; ind < dir.size; ++ind){
            os << *dir.entries[ind] << endl;
        }
        return os;
    }
public:
    Directory() {
        entries = new Entry* [1];
        size = 0;
        capacity = 1;
        
    }

    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if (size == capacity)    {
            Entry** oldData = entries;
            entries = new Entry*[2* capacity];
            for (size_t i = 0; i < size; ++i) {
                entries[i] = oldData[i];
            }
            delete [] oldData;
            capacity *= 2;
        } // if
        entries[size] = new Entry(name, room, ph, pos);
        ++size;
    }
    
    unsigned operator[] (const string& name) const {
        for (size_t ind=0; ind < size; ++ind){
            if (name == entries[ind]->getName()){
                return entries[ind]->getPhone();
            }
        }
        return 9999999;
    } // add
    ~Directory (){
        for (size_t ind=0; ind < size; ++ind){
            delete entries[ind];
            entries[ind] = nullptr;
        }
        delete [] entries;
    } //        destructor
//    copy constructor
    
    Directory(const Directory& dir) {
        size = dir.size;
        capacity = dir.capacity;
        entries = new Entry*[capacity];
        for (size_t i = 0; i < size; ++i) {
            entries[i] = new Entry(*dir.entries[i]);
        }
    }

    Directory& operator=(const Directory& dir) {
        if (this != &dir) {
            for (size_t ind=0; ind < size; ++ind){
                delete entries[ind];
                entries[ind] = nullptr;
            }
            delete [] entries;
            size = dir.size;
            capacity = dir.capacity;
            entries = new Entry*[capacity];
            for (size_t i = 0; i < size; ++i) {
                entries[i] = new Entry(*dir.entries[i]);
            }
        }
        return *this;
    }
private:
    Entry** entries;
    size_t size;
    size_t capacity;
}; // class Directory

void doNothing(Directory dir) { cout << dir << endl; }
    
int main() {
    
    // Note that the Postion objects are NOT on the heap.
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);

    // Create a Directory
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    cout << d << endl;

    Directory d2 = d;    // What function is being used??
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    cout << d << endl;

    cout << "Calling doNothing\n";
    doNothing(d2);
    cout << "Back from doNothing\n";

    Directory d3;
    d3 = d2;

    // Should display 1592
    cout << d2["Carmack"] << endl;
    
} // main
