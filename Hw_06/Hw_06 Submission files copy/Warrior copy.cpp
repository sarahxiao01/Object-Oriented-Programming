//
//  main.cpp
//  Warrior
//
//  Created by Sarah Xiao on 3/29/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#include "Warrior.h"
#include "Noble.h"
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


namespace WarriorCraft {
    class Noble;
    class Warrior {
        //helps display warrior status
        friend ostream& operator<< (ostream& os, const Warrior& warror) {
            os << warror.Warriornamegetter() << ':' << warror.Warriorstrengthgetter() << endl;
            return os;
        }

    public:
        Warrior(const string& Name, int Strength) : warsname(Name), warsstrength(Strength), mynob(nullptr) {}
        const string& Warriornamegetter() const {
            return warsname;
        }
        const int Warriorstrengthgetter() const {
            return warsstrength;
        }
    //    updates warrior strengths
        void reStrength(int newstrength) {
            warsstrength = newstrength;
        }
        
    //checks if the warrior is hired to avoid hiring repeatedly
        bool ishired () {
            if (mynob != nullptr) {
                return true;
            }
            else {
                return false;
            }
        }
    //sets pointer to null when warrior is fired or runs away
        void setfree () {
                mynob = nullptr;
            }
        Noble* getlord() {
            return mynob;
            }
            
        Noble* setlord (Noble* lord) {
            mynob = lord;
            return mynob;
            }
        
        bool runaway() {
            if (mynob!= nullptr) {
                mynob->removehim(*this);
            }
            cout << name << " flees in terror, aboandoning his lord, " << mynob->getNobleName() << endl;
            return true;
            else {
                return false;
            }
        }
        
    //makes name, strength and his lord private
    private:
        string warsname;
        int warsstrength;
        Noble* mynob = nullptr;
    };
}



