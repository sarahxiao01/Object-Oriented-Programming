//
//  main.cpp
//  Lab_01
//
//  Created by Sarah Xiao on 2/2/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.


#include <iostream>
#include <string>  //q1: iostream and string includes were needed.
#include <vector>
#include <fstream>
using namespace std; //q2: no qualifier needed
int x; //q3: 0 is displayed
int y = 17;
int z = 2000000017;
int pie = 3.14159; // q4: We can find out which takes up more space by using sizeof function
// string x = "felix"; // q5: compilation error of redefining x to a different type
void displayVector(vector<int> myvec) { //q13
    for (size_t i = 0; i < myvec.size(); ++i){
        cout << myvec[i] << " ";
    }
    
}
vector<int> doubleVector(vector<int> myvec) {  //q14
for (size_t i = 0; i < myvec.size(); ++i) {
    myvec[i]= myvec[i]*2;
}
    return myvec;}
vector<int> TruedoubleVector(vector<int>& myvec) {  //q15
for (int& x : myvec) {
    x = x*2;
}
    return myvec;}


int main() {
    cout << "Hello world!\n";
    std::cout << "Hello world!\n"; //q1, returns "Hello world!"
    cout << x;
    cout << sizeof(x);
    cout << sizeof(y);
    cout << sizeof(z);
    cout << sizeof(pie); // q4: displays 4444
    if (y <= 20 && y >= 10){ //q6
        cout << "yes, y is between 10 and 20, inclusive \n";
        }
    else {
        cout << "no, y is not between 10 and 20";
    }
    cout << endl;
    for (int i = 10; i <= 20; ++i) {  //q7
          cout << i;
       }
    int i = 10;
    cout << endl;
    while (i <= 20) {  //q7
        cout << i;
          ++i;
       }
    
    int j = 10;  //q7
    cout << endl;
    do {
       cout << j;
        ++j;
    } while (j <= 20);
    cout << endl;
    vector<int> e = {3, 15, 5};
    displayVector(e);
    cout << endl;
    vector<int> vectorOfInts; //q10
    for (int i = 10; i <= 100; i+=2) {  //filling the vector
        vectorOfInts.push_back(i);
    }
    for (size_t i = 0; i < vectorOfInts.size(); ++i) { //indices
        cout << vectorOfInts[i] << " ";
    }
    cout << endl;
    for (int x : vectorOfInts) {     //ranged for
        cout << x << " ";
    }
    cout << endl;
    for (size_t i = vectorOfInts.size(); i > 0 ; --i) {  //in reverse
        cout << vectorOfInts[i-1] << " ";
    }
    cout << endl;
    vector<int> v1{2, 3, 5, 7, 11, 13, 17, 19}; //q12: prime numbers less than 20
    for (size_t i = 0; i < v1.size(); ++i) {
        cout << v1[i] << endl;
    }
    cout << endl;
    vector<int> f = {1, 23,4}; //q14 test
       vector<int> c = doubleVector(f);
       for (size_t i = 0; i < c.size(); ++i) {
           cout << c[i] << ' ';
    }
    cout << endl;
    vector<int> d = {2, 32,7}; //q15 test
    vector<int>TruedoubleVector(d);
    for (int x : d) {
    cout << x << ' ';
    }
    //question 8 at the end
    string Str;
    cin >> Str;
    ifstream ifs(Str);
    while (!ifs){
        ifs.clear();
        cerr << "Please enter a valid name" << endl;
        cin >> Str;
        ifs.open(Str);
    }
    string anStr;
    while (ifs >> anStr) {
       cout << anStr << endl;
    }
    ifs.close();
}
