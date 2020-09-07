//
//  main.cpp
//  Hw_02
//
//  Created by Sarah Xiao on 2/11/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//
// purpose of the code: to read from a file of warriors with name and strengths and put them to battble or display status according to commands within the file. Battles would alter the strengths of warriors, and change would be reflected when status command is read.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Warrior; {
    string warname;
    int warstrength;
};

//This function opens the file by taking ifstream and the type string of file name. It returns nothing.
void Openfile (ifstream& fname, const string& filename) {
    fname.open(filename);
    
}

//This function finds the position of a warrior which names are read in the file within the Warriors vector. It takes the type vector of Warrior and tyope string of warrior names as input, and returns a type size_t of the position of the warrior.
size_t findmyWarrs (const vector<Warrior>& Warrvec, const string& name) {
    for (size_t i = 0; i< Warrvec.size(); ++i) {
        if (Warrvec[i].warname == name) {
            return i;
    }
    }
    return Warrvec.size();
}

//This function is called in the case of one warrior defeating the other to help display the result of battle. It takes the inputs type Warrior and returns nothing.
void oneWarriorwins (Warrior& winner, Warrior& loser) {
    winner.warstrength -= loser.warstrength;
    loser.warstrength = 0;
    cout << winner.warname << "defeats" << loser.warname << endl;
}

//This function is called in the case of both warriors losing (same strength) to help display the result of battle. It takes the inputs type Warrior and returns nothing.
void WarriorsBothLose (Warrior& loser1, Warrior& loser2) {
    loser1.warstrength = 0;
    loser2.warstrength = 0;
    cout << "Mutual Annihilation:" << loser1.warname << "and" << loser2.warname << "die at each other's hands" << endl;
}

//This function is used to determine the result of battle according to two participating warriors' strengths by printing out the battle results. It takes the input type vector of Warrior and constant strings of the warriors' names. It returns nothing.
void ResultOfbattle (vector<Warrior>& myWarr,const string& warr1, const string& warr2){
    Warrior Warrior1;
    Warrior Warrior2;
    size_t Warrior1loc = findmyWarrs (myWarr, warr1);
    size_t Warrior2loc = findmyWarrs (myWarr, warr2);
    Warrior1 = myWarr[Warrior1loc];
    Warrior2 = myWarr[Warrior2loc];
    if (Warrior1.warstrength == 0 && Warrior2.warstrength == 0 ){
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
    }
    else if (Warrior2.warstrength == 0){
        cout << "He's dead," << Warrior1.warname << endl;
    }
    else if (Warrior1.warstrength == 0){
        cout << "He's dead," << Warrior2.warname << endl;
    }
    else if (Warrior1.warstrength > Warrior2.warstrength){
        oneWarriorwins (Warrior1, Warrior2);
    }
    else if (Warrior1.warstrength < Warrior2.warstrength){
        oneWarriorwins (Warrior2, Warrior1);
    }
    else {
        WarriorsBothLose (Warrior1, Warrior2);
    }
}

//This function displays the status of warriors as in how many warriors there are and for each warrior their strengths as of now.It takes the input type vector of Warrior and returns nothing.
void displayWarriors (const vector<Warrior>& Warrvec) {
    cout << "There are:" << Warrvec.size() << "warriors" << endl;
       for (const Warrior& warr: Warrvec) {
           cout << "Warrior:" << warr.warname << "strength:" << warr.warstrength << endl;
    }
}

//This function takes input typeifstream to print the output according to the file commands. It takes the input type ifstream and returns nothing.
void readfileCommands (ifstream& readCommand) {
    string myCommand;
    vector<Warrior> Warriors;
    while (readCommand >> myCommand){
        if (myCommand == "Warrior"){
            string name;
            int strength;
            readCommand >> name >> strength;
            Warrior myWarrior;
            myWarrior.warname = name;
            myWarrior.warstrength = strength;
            Warriors.push_back(myWarrior);
            }

        if (myCommand == "Status"){
        displayWarriors(Warriors);
        }
        else if (myCommand == "Battle") {
            string name1, name2;
            readCommand >> name1 >> name2;
            ResultOfbattle (Warriors, name1, name2);
        }
    }
}

int main() {
    ifstream fname;
    Openfile(fname, "warriors.txt");
    readfileCommands(fname);
    fname.close();
}
