//
//  main.cpp
//  hw08
//
//  Created by Sarah Xiao on 4/30/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "Polynomial.h"
using namespace std;


//    output operator
    ostream& operator<<(ostream& os, const Polynomial& rhs) {
        Node* mynode = rhs.headptr;
        rhs.recurr(os, mynode, 0);
    }
    
// operator== for polynomial equality check
    bool Polynomial::operator== (Polynomial& lhs, Polynomial& rhs){
        if (rhs.degree == lhs.degree){
            Node* header1 = lhs.headptr;
            Node* header2 = rhs.headptr;
            while ((header1 != nullptr) && (header2 != nullptr)){
                if (header1->data != header2->data){
                    return false;
                }
                header1 = header1->next;
                header2 = header2->next;
        }
            if (header1 == nullptr && header2 == nullptr){
                return true;
            }
        return false;
        }
    }
// inequality
    bool Polynomial::operator!= (Polynomial& lhs, Polynomial& rhs){
        return !(lhs == rhs);
    }

// constructor
    Polynomial::Polynomial(vector<int> polys): degree(int(polys.size()-1)),headptr(nullptr) {
        for (size_t index =0; index < polys.size(); ++index) {
            Node* one = new Node (polys[index], headptr);
            headptr = one;
        }
    }
//             default constructor
//    Polynomial(vector<int> polys): degree(0),headptr(nullptr) {}

//helper function to evaluate, helps evaluate powers of integers
int Polynomial::power(int base, int index) {
    int result = 1;
    while (index != 0){
        result *= base;
        index -= 1;
    }
    return result;
}

//  for evaluating polynomials when passed in an x value
    int Polynomial::evaluate(int x){
        int result = 0;
        int count = 0;
        int index;
        int term;
        Node* ptr = headptr;
        while (ptr!= nullptr){
            index = degree - count;
            term = power(x, index);
            result += (headptr->data) * term;
            ptr = ptr->next;
            ++count;
        }
        return result;
    }

//    Big 3
    //        destructor
    Polynomial::~Polynomial(){
        Node* node;
        while (headptr!=nullptr){
            node = headptr->next;
            delete headptr;
            headptr = node;
        }
    }
//  copy constructor
    Polynomial::Polynomial(const Polynomial& rhs) {
        degree = rhs.degree;
        headptr = nullptr;
        if (rhs.headptr != nullptr){
            Node* looper1 = rhs.headptr;
            headptr = new Node(looper1->data);
            looper1 = looper1->next;
            Node* looper2  = headptr;
            while (looper1 != nullptr){
                Node* mynode = new Node(looper1->data);
                while (looper2->next != nullptr){
                    looper2 = looper2->next;
                }
                looper2->next = mynode;
                looper1 = looper1->next;
            }
        }
    }
        
//    assignment operator
    Polynomial& Polynomial::operator= (const Polynomial& rhs) {
        if (this != &rhs) {
            degree = rhs.degree;
            Node* ptr;
            while (headptr!=nullptr){
                ptr= headptr->next;
                delete headptr;
                headptr = ptr;
            }
            headptr = new Node(rhs.headptr->data);
            Node* looper1 = rhs.headptr->next;
            Node* looper2 = headptr;
            while (looper1){
                looper2->next = new Node(looper1->data);
                looper1 = looper1->next;
                looper2 = looper2->next;
            }
        }
        return *this;
    }
//recursive helper function for printing individual terms in polynomial
    void Polynomial::recurr(ostream& os, Node* ptr, int index)const {
        if (ptr != nullptr){
            recurr(os, ptr->next, index+1);
            if (ptr->data != 0){
                if (index == 1){
                    if(ptr->data != 1){
                        cout << ptr->data;
                    }
                    cout << "x + ";
                }
                else if (index == 0){
                    cout << ptr-> data << " ";
                }
                else {
                    if(ptr->data != 1){
                        cout << ptr->data;
                    }
                    cout << "x^"<< index << " + ";
                }
            }
        }
    }
//operator+= for adding polynomials
    Polynomial::Polynomial& operator+=(Polynomial& rhs){
        Node* go1 = headptr;
        Node* go2 = rhs.headptr;
        if (degree >= rhs.degree){
            int counter = degree - rhs.degree;
            while (go1){
                for (int i = 1; i <= counter; ++i){
                    go1 = go1->next;
                }
            go1->data += go2->data;
            go1 = go1->next;
            go2 = go2->next;
            }
            return *this;
        }
        else {
            Polynomial poly(rhs);
            rhs += *this;
            *this = rhs;
            rhs = poly;
            return *this;
        }
    }
//  operator+ for adding polynomials
    Polynomial::Polynomial operator+ (const Polynomial& lhs, const Polynomial& rhs){
           Polynomial poly(lhs);
           return poly += rhs;
    }

void doNothing(Polynomial temp) {}

int main() {

    //test constructor
    Polynomial p1({17});                 // 17
    Polynomial p2({1, 2});               // x + 2
    Polynomial p3({-1, 5});              // -1x + 5
    Polynomial p4({5, 4, 3, 2, 1});      // 5x^4 + 4x^3 + 3x^2 + 2x + 1
    Polynomial has_a_zero({4, 0, 1, 7}); // 4x^3 + x + 7

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;
    cout << "p4: " << p4 << endl;
    cout << "has_a_zero: " << has_a_zero << endl;
    cout << "p2 + p3: " << (p2+p3) << endl;
    cout << "p2 + p4: " << (p2+p4) << endl;
    cout << "p4 + p2: " << (p4+p2) << endl;


    //test copy constructor - the statement below uses the copy constructor
    //to initialize poly3 with the same values as poly4
    Polynomial p5(p4);
    p5 += p3;
    cout << "Polynomial p5(p4);\n"
         << "p5 += p3;\n";

    cout << "p4: " << p4 << endl;
    cout << "p5: " << p5 << endl;

    cout << "Calling doNothing(p5)\n";
    doNothing(p5);
    cout << "p5: " << p5 << endl;

    //tests the assignment operator
    Polynomial p6;
    cout << "p6: " << p6 << endl;
    cout << boolalpha;  // Causes bools true and false to be printed that way.
    cout << "(p4 == p6) is " << (p4 == p6) << endl;
    p6 = p4;
    cout << "p6: " << p6 << endl;
    cout << boolalpha;
    cout << "(p4 == p6) is " << (p4 == p6) << endl;

    //test the evaluaton
    int x = 5;
    cout << "Evaluating p1 at " << x << " yields: " << p1.evaluate(5) << endl;
    cout << "Evaluating p2 at " << x << " yields: " << p2.evaluate(5) << endl;

    Polynomial p7({3, 2, 1});           // 3x^2 + 2x + 1
    cout << "p7: " << p7 << endl;
    cout << "Evaluating p7 at " << x << " yields: " << p7.evaluate(5) << endl;

    cout << boolalpha;
    cout << "(p1 == p2) is " << (p1 == p2) << endl;
    cout << "(p1 != p2) is " << (p1 != p2) << endl;

    /*=================================================================
    NEW TEST CODE - test if cleaning the leading 0s
    ===================================================================*/

    Polynomial p8({ 1, 1 });
    Polynomial p9({ -1, 1 });
    Polynomial p10({ 0, 0, 2 });
    p8 + p9 tests if += does the cleanup()
    p10 tests if constructor does the cleanup()
    cout << "((p8 + p9) == p10) is " << ((p8 + p9) == p10) << endl;
}
