//
//  main.cpp
//  Polynomial_
//
//  Created by Sarah Xiao on 5/1/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <string>
#include <iostream>
#include <vector>

class Polynomial{
//    embedded node struct which is used to build up lists
    struct Node {
        Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
        int data;
        Node* next;
    };
//    output operator
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& rhs);
    
// operator== for polynomial equality check
    friend bool operator== (Polynomial& lhs, Polynomial& rhs);
    
// inequality
    friend bool operator!= (Polynomial& lhs, Polynomial& rhs);
    
    public:
// constructor
    Polynomial(std::vector<int> polys);
    
//             default constructor
//    Polynomial(vector<int> polys): degree(0),headptr(nullptr) {}
//  for evaluating polynomials when passed in an x value
    int evaluate(int x);
    
//helper function to evaluate, helps evaluate powers of integers
    int power(int base, int index);
    
//    Big 3
    //        destructor
    ~Polynomial();
//  copy constructor
    Polynomial(const Polynomial& rhs);
        
//    assignment operator
    Polynomial& operator= (const Polynomial& rhs);
    
//recursive helper function for printing individual terms in polynomial
    void recurr(std::ostream& os, Node* ptr, int index)const;
    
//operator+= for adding operators
    Polynomial& operator+=(Polynomial& rhs);
    
//  operator+ for adding operators
    Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
    
    private:
    int degree;
    Node* headptr;
    };
#endif

