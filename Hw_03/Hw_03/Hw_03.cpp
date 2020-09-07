//
//  main.cpp
//  hw03
//
//  Created by Sarah Xiao on 2/18/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Warrior {
public:
    
    //Warrior consructor
    Warrior(const string& warname, const string& weaponname, int& weaponstrength) :
        name(warname), weaponsName(weaponname), Strength(weaponstrength) {}
    
    //methods for getting name of warrior, name of their weapon and the strength in the weapon. Returns them in types string and integer respectively.
    string getName()const {
        return name;
    }
    string getweaponName()const {
        return myWeapon.getweaponName();
    }
    int getStrength()const {
        return myWeapon.getStrength();
    }
    //   to update the strength of a warrior in his weapon, takes type int of change in strength and returns nothing
    void changeStrength(int strengthchange) {
        myWeapon.changeStrength(strengthchange);
    }
    //  to determine different outcomes when two warriors battle, takes two type Warrior as input and returns nothing (displays results of battle)
    void battles(Warrior& myenemy) {
        cout << name << " battles " << myenemy.getName() << endl;
        if ((myWeapon.getStrength()) == 0 && (myenemy.getStrength() == 0)) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        // a warrior is dead during the battle
        else if (myenemy.getStrength() == 0) {
            cout << "He's dead, " << name << endl;
        }
        else if (myWeapon.getStrength() == 0) {
            cout << "He's dead, " << myenemy.name << endl;
        }
        //the warrior defeats his enemy
        else if (myWeapon.getStrength() > myenemy.getStrength()) {
            int strengthchange = myWeapon.getStrength() - myenemy.getStrength();
            int remaining = 0;
            myWeapon.changeStrength(strengthchange);
            myenemy.changeStrength(remaining);
            cout << name << " defeats " << myenemy.getName() << endl;
        }
        //the warrior is defeated by the enemy
        else if ((myWeapon.getStrength() < myenemy.getStrength())
            && (myWeapon.getStrength() == 0)) {
            cout << "He's dead, " << myenemy.name << endl;
        }
        else if (myWeapon.getStrength() < myenemy.getStrength()) {
            int strengthchange = myenemy.getStrength() - myWeapon.getStrength();
            int remaining = 0;
            myenemy.changeStrength(strengthchange);
            myWeapon.changeStrength(remaining);
            cout << myenemy.name << " defeats " << name << endl;
        }
        // when both are dead, cout "Mutual Annihilation"
        else if (myWeapon.getStrength() == myenemy.getStrength()) {
            myenemy.changeStrength(0);
            myWeapon.changeStrength(0);
            cout << "Mutual Annihilation: " << name << " and " << myenemy.name
                << " die at each other's hands" << endl; ;
        }
    }
private:
    class Weapon {
    public:
        
        Weapon(const string& weaponname, int weaponstrength) :
            weaponName(weaponname), weaponsStrength(weaponstrength) {}
        //methods for getting name of warrior, name of their weapon and the strength in the weapon. Returns them in types string and integer respectively.
        string getweaponName()const {
            return weaponName;
        }
        int getStrength()const {
            return weaponsStrength;
        }
        void changeStrength(int strengthchange) {
            weaponsStrength = strengthchange;
        }
        //  name and strength of the weapon are both private
    private:
        string weaponName;
        int weaponsStrength;
        
    };
    string name;
    int Strength;
    string weaponsName;
    Weapon myWeapon{ weaponsName, Strength };
};
    // displays the status of every warrior by printing out the name, weapon name and strength.
ostream& operator <<(ostream& os, Warrior& warrior) {
    
    os << "Warrior: " << warrior.getName() << ", weapon: "
            << warrior.getweaponName() << ", " << warrior.getStrength() << endl;
    return os;
    
}
//  reads the file, check the first commandword and returns different displays differenntly according to the command being read. Also responsible for creating of new warriors by reading in the name, name of weapon and strength within the file, the function returns nothing.
void fileread(ifstream& fname) {
    string commandword;
    string warr1;
    string warr2;
    string name;
    string weaponsName;
    int mystrength;
    vector<Warrior> myWarriors;
    while (fname >> commandword) {
        //new Warrior is added to collection of warriors

        if (commandword == "Warrior") {
            fname >> name;
            fname >> weaponsName;

            fname >> mystrength;
            Warrior Warrior1{name, weaponsName, mystrength };
            myWarriors.push_back(Warrior1);
        }
        //display status of collection of warriors
        else if (commandword == "Status") {
            cout << "There are " << myWarriors.size() << " warriors" << endl;
            for (size_t i = 0; i < myWarriors.size(); ++i) {
                cout << myWarriors[i];
            }
        }
        // upon reading the battle command, call the two battling warriors and modify warriors
        else if (commandword == "Battle") {
            fname >> warr1;
            fname >> warr2;
            
            for (Warrior& Warrior1 : myWarriors) {
                if (Warrior1.getName() == warr1) {
                    for (Warrior& Warrior2 : myWarriors) {
                        if (Warrior2.getName() == warr2) {
                            Warrior1.battles(Warrior2);
                        }
                    }
                }
            }
        }
    }
}
int main() {
    //read in file and check errors
    ifstream fname("warriors.txt");
    
    if (!fname) {
        cerr << "Failed to open the file!";
        exit(1);
    }
    
    fileread(fname);
    
    fname.close();
}
