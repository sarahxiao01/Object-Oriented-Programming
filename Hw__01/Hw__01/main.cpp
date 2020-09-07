//
//  main.cpp
//  hw01
//
//  Created by Sarah Xiao on 2/3/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

// purpose of the code: to decrypt a known file that has been encrypted; Caesar cypher is used where each lowercase alphabetic character has been modified by “rotating” it through the alphabet some number of steps, which is to be read from first character of the file. Only lowercase alphabetic characters have been encrypted. The rest, characters all appear in the encrypted file the same way they did in the original. Order of the lines are also reversed.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
// The changech function takes an encrypted character and the rotation distance, and returns the corresponding decrypted character. Only lowercase characters will result in a change, and the function will return the input value for other characters.
char changech (char& ch, int key){
    if ( islower(ch) ) {  //only modifies lower case characters
        ch -= key;
        if (ch < 'a') {     //makes sure letters only get changed into other letters by rotational distance
            ch += 26;
        }
    }
    return ch;
}
// The modifyline function takes a string and the rotation distance. It will modify the string that is passed in, and changing every character within the string into its unencrypted form using the changech function. Strings in C++ are directly mutated. It has a void return type, so it does not return anything.
void modifyline (string& line, int key) {
    for (size_t position = 0; position < line.size(); ++position) {
        changech(line[position], key);
    }
}

int main (){
    ifstream enc("encrypted.txt");
    if (!enc) {
        cerr << "Could not open the file. \n";
        exit(1);
    }
    int mykey;
    enc >> mykey;
    string myline;
    getline(enc, myline);
    vector <string> vectorOfLines;
    while (getline(enc, myline)) { //This while loop gets each line in the file as a string without white spaces, and modifies each string before pushing them in sequence into the vector containing the lines
        modifyline (myline, mykey);
        vectorOfLines.push_back(myline);
    }
    enc.close();
    for (size_t row = vectorOfLines.size(); row > 0 ; --row) { //Print lines in reversed order
        cout << vectorOfLines[row - 1] << endl;
    }
}
