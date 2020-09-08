//
//  main.cpp
//  Protector
//
//  Created by Sarah Xiao on 4/16/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//
#include "Protector.h"
#include "Noble.h"
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace WarriorCraft {
    class Noble;
        //helps display protector status
        friend ostream& operator<< (ostream& os, const Protector& warror) {
            os << warror.Protectornamegetter() << ':' << warror.Protectorstrengthgetter() << endl;
            return os;
        }
        Protector::Protector(const string& Name, int Strength) : warsname(Name), warsstrength(Strength), mynob(nullptr) {}
        const string& Protectornamegetter() const {
            return warsname;
        }
        const int Protector::Protectorstrengthgetter() const {
            return warsstrength;
        }
    //    updates protector strengths
        void Protector::reStrength(int newstrength) {
            warsstrength = newstrength;
        }
        
    //checks if the protector is hired to avoid hiring repeatedly
        bool Protector::ishired () {
            if (mynob != nullptr) {
                return true;
            }
            else {
                return false;
            }
        }
    //sets pointer to null when protector is fired or runs away
        void Protector::setfree () {
                mynob = nullptr;
            }
        Noble* Protector::getlord() {
            return mynob;
            }
        Noble* Protector::setlord (Noble* lord) {
            mynob = lord;
            return mynob;
            }
        
        bool Protector::runaway() {
            if (mynob!= nullptr) {
                mynob->removehim(*this);
            }
            cout << name << " flees in terror, aboandoning his lord, " << mynob->Noblenamegetter() << endl;
            return true;
            else {
                return false;
            }
        }
            
    Wizard::Wizard(const std::string& Name, int Strength): Protector(warsname, warsstrength) {}
    void Wizard::warCry{
        cout << "POOF" << endl;
    }

    Warrior::Warrior(const std::string& Name, int Strength): Protector(warsname, warsstrength) {}
    void Warrior::warCry{
        cout << warsname << " says: Take that in the name of my lord, " << mynob->Noblenamegetter() << endl;
    }

    Swordsman::Swordsman(const std::string& Name, int Strength): Warrior(warsname, warsstrength) {}
    void Swordsman::warCry{
        cout << "CLANG! ";
        Warrior::warCry();
    }

    Archer::Archer(const std::string& Name, int Strength): Warrior(warsname, warsstrength) {}
    void Archer::warCry{
        cout << "TWANG! ";
        Warrior::warCry();
    }
}
