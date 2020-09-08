//
//  main.cpp
//  Noble
//
//  Created by Sarah Xiao on 4/16/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//
#include "Noble.h"
#include "Protector.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace WarriorCraft{
        friend ostream& operator<< (ostream& os, const Noble& thenoble) {
            cout << thenoble.noblename << "has an army of" << thenoble.myWarrsvec.size() << endl;
            for (size_t ind = 0; ind < thenoble.myWarrsvec.size(); ++ind) {
                cout << thenoble.myWarrsvec[ind]->operator<<();
            }
            return os;
        }
        Noble::Noble (const string& mynobsname): noblename(mynobsname) {nobledead = false;}
        const string& Noble::Noblenamegetter() const {
            return noblename;
            }
    //        helps display battle results and update noble status and their protector strengths
        void Noble::battle (Noble& enemynob){
            cout << noblename << " battles " << enemynob.noblename << endl;
            if (Noblestrengthgetter() == 0 && enemynob.Noblestrengthgetter() == 0) {
                cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
            }
            else if (Noblestrengthgetter() == 0){
                enemynob.Cry();
                cout << "He's dead," << enemynob.noblename << endl;
            }
            else if (enemynob.Noblestrengthgetter() == 0){
                Cry();
                cout << "He's dead," << noblename << endl;
            }
            else {
                Cry();
                enemynob.Cry();
                int remaining;
                if (Noblestrengthgetter() - enemynob.Noblestrengthgetter() == 0){
                    cout << "Mutual Annihalation:" << noblename << "and" << enemynob.noblename << "die at each other's hands" << endl;
                    nobledead = true;
                    enemynob.nobledead = true;
                    Noblestrengthsetter(0);
                    enemynob.Noblestrengthsetter(0);
            }
                if (Noblestrengthgetter() - enemynob.Noblestrengthgetter() > 0){
                    cout << noblename << "defeats" << enemynob.noblename;
                    remaining = (Noblestrengthgetter()- enemynob.Noblestrengthgetter());
                    Noblestrengthsetter(remaining);
                    enemynob.nobledead = true;
                    enemynob.Noblestrengthsetter(0);
                }
                else if (Noblestrengthgetter() - enemynob.Noblestrengthgetter() < 0){
                    cout << enemynob.noblename << "defeats" << noblename;
                    remaining = (enemynob.Noblestrengthgetter()- Noblestrengthgetter());
                    enemynob.Noblestrengthsetter(remaining);
                    nobledead = true;
                    Noblestrengthsetter(0);
                    }
        }
    };
        Lord::Lord (const std::string& mynobsname): noblename(mynobsname), myStrength(nobsstrength) {}
        const int Lord::Noblestrengthgetter()const{
//            int strengthcount = 0;
//            for (size_t ind = 0; ind < myWarrsvec.size(); ind++) {
//                strengthcount += (myWarrsvec[ind])->Protectorstrengthgetter();
//                }
//            Totalstrengths = strengthcount;
            return Totalstrengths;
                }
        void Lord::Noblestrengthsetter(int remaining) {
            for (size_t ind = 0; ind < myWarrsvec.size(); ind++) {
                hisnewstrength = enemynob.myWarrsvec[ind]->Protectorstrengthgetter() * (remaining/ Totalstrengths);
                enemynob.myWarrsvec[ind]->reStrength(hisnewstrength);
            }
            Totalstrengths = remaining;
            }
    //  helps nobles hire protectors. Checks if he is dead first, because dead nobles cannot hire protectors. Also checks if protector is already hired, and if not, hires him by adding him into vector of protectors.
        bool Lord::hire (Protector& hirwarr) {
            if (hirwarr->Protectorstrengthgetter() == 0) {
                cout << "The dead protector cannot be hired." << endl;
                }
            else if (nobledead == false){
                if (hirwarr.ishired() == false){
                    hirwarr.setlord->(this);
                    myWarrsvec.push_back(&hirwarr);
                    Totalstrengths += hirwarr.Protectorstrengthgetter();
                    return true;
                    }
                else {
                    cout << "He's hired; hiring failed. " << endl;
                    return false;
                }
                }
            else {
                cout << "Dead nobles cannot hire protectors; hiring failed.";
                return false;
                    }
            }
    //            when the protector runs away or is fired, helps remove him from the vector of pointers
        bool Lord::removehim(Protector& him) {
            size_t j;
            Protector* warrptr = nullptr;
            for (size_t ind1 = 0; ind1 < myWarrsvec.size(); ++ind1) {
                if (myWarrsvec[ind1] == &him)
                    {j = ind1;
                    warrptr = myWarrsvec[myWarrsvec.size()-1];
                    myWarrsvec[myWarrsvec.size()-1] = myWarrsvec[j];
                    myWarrsvec[j]= warrptr;
                    myWarrsvec.pop_back();
                    Totalstrengths -= hirwarr.Protectorstrengthgetter();
                    him.setfree();
                    return true;
                    }
                }
            return false;
            }
        bool Lord::fire (Protector& hirwarr) {
            bool fired;
            if (nobledead == false) && (hirwarr.getlord() != nullptr) {
                for (size_t i = 0; i < myWarrsvec.size(); ++i){
                if (myWarrsvec[i] == &hirwarr)
                    {
                        fired = removehim(myWarrsvec[i]);
                    }
                    }
            cout << "You don't work for me anymore" << hirwarr.Protectornamegetter() << "! -- " << noblename << '.' << endl;
            return fired;
                }
            else{
                cout << "firing failed." << endl;
                return fired;
                    }
            }
        void Lord::Cry const (){
            if (myWarrsvec.size() != 0){
                for (size_t ind = 0; ind < myWarrsvec.size(); ind++) {
                    if (myWarrsvec[ind]->Protectorstrengthgetter() != 0) {
                        myWarrsvec[ind]->warCry();
                }
            }
                    }
            }
    PersonWithStrengthToFight::PersonWithStrengthToFight(const string& mynobsname, int theStrength): noblename(mynobsname), myStrength(theStrength) {}
        const int PersonWithStrengthToFight::Noblestrengthgetter() const{
            return myStrength;
            }
        void PersonWithStrengthToFight::Noblestrengthsetter(int strengthen){
            myStrength = strengthen;
            }
        bool PersonWithStrengthToFight::removehim() const{
            return false;
            }
        void PersonWithStrengthToFight::Cry() const{
            cout << "UGH!" << endl;
            }
            }
