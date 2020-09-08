//
//  main.cpp
//  cpp
//
//  Created by Sarah Xiao on 2/7/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//
// purpose of the code: to read from a file of chemical formulae and sort them according to number of hydrogen atoms and number of carbon atoms in their molecular formula. Print them in an ordered output where chemicals of the same exact molecular formula are put together.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// a new class, Chemical, is created as a struct of two ints and a vector. 
struct Chemical{
    int ccount ;
    int hcount ;
    vector<string> formname ;
    };

//the Openfile function opens the file by asking the user to input the file name. It takes the stream as input type and returns nothing.
void Openfile (ifstream& fname) {
    string mystr;
    do {
        cout << "Please enter file name:";
        cin >> mystr;
        fname.open(mystr);
        if(!fname){
            cerr << "Could not open the file. \n";
            fname.clear();
        }
    }while(!fname);
}

//The findFromula function loctaes a formula object that matches the number of hydrogene and carbons for a new entry. It takes a vector of the Struct Chemical and the new entry of Chemical struct to be searched for. The return type is size_t
size_t findFormula (vector<Chemical>& myvec, Chemical myChemical) {
    for (size_t i = 0; i < myvec.size(); ++i) {
        if  (myvec[i].ccount == myChemical.ccount && myvec[i].hcount == myChemical.hcount) {
            return i;
        }
    }
    return myvec.size();
}

//The VectorFill function takes the type file stream and vector of Chemical as an input. It creates a struct Chemical every time it reads a line from the file, and fills the vector with structs Chemical with the help of findFormula function.It returns nothing.
void VectorFill (ifstream& fname, vector<Chemical>& myvec) {
    string name;
    char C, H;
    int c_count, h_count;
    while (fname >> name >> C >> c_count >> H >> h_count) {
        Chemical myChemical;
        myChemical.ccount = c_count;
        myChemical.hcount = h_count;
        myChemical.formname.push_back(name);
        size_t myloc;
        myloc = findFormula (myvec, myChemical);
        if (myloc == myvec.size()) {
            myvec.push_back(myChemical);
        }
        else {
            myvec[myloc].formname.push_back(name);
        }
}
}

//the VectorSort function VectorSort takes a vector of Chemical as input. It sorts the vector according to the number of carbon and hydrogen items. It returns nothing.
void VectorSort (vector<Chemical>& myvec) {
    size_t min_index;
    Chemical value;
    for (size_t i = 0; i < myvec.size(); ++i) {
        min_index = i;
        for (size_t j = i+1; j < myvec.size(); ++j) {
            if (myvec[j].ccount < myvec[min_index].ccount){
                min_index = j;
                }
            else if ((myvec[j].ccount == myvec[min_index].ccount) && (myvec[j].hcount < myvec[min_index].hcount)) {
                           min_index = j;
                       }
        }
        value = myvec[min_index];
        myvec[min_index]= myvec[i];
        myvec[i] = value;
    }
}

//This displayVector function takes a constant type vector of Chemical and prints it in the desired format when called in main. It returns nothing.
void displayVector (const vector<Chemical>& myvec) {
   for (const Chemical& elem : myvec) {
        cout << 'C' << elem.ccount;
        cout << 'H'<< elem.hcount << ' ';
       for (const string& elemName : elem.formname) {
           cout << elemName << " ";
       }
       cout << endl;
    }
}

int main() {
    //cout << "Hello" ;
    ifstream fname;
    Openfile(fname);
    vector<Chemical> myVec;
    VectorFill (fname, myVec);
    VectorSort (myVec);
    fname.close();
    displayVector (myVec);
}
