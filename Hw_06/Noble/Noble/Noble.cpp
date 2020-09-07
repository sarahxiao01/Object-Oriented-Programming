//
//  main.cpp
//  Noble
//
//  Created by Sarah Xiao on 3/29/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//
#include "Noble.h"
#include "Warrior.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace WarriorCraft{

    class Warrior;
    class Noble{
        
        friend ostream& operator<< (ostream& os, const Noble& thenoble) {
            cout << thenoble.noblename << "has an army of" << thenoble.myWarrsvec.size() << endl;
            for (size_t ind = 0; ind < thenoble.myWarrsvec.size(); ++ind) {
                cout << thenoble.myWarrsvec[ind]->operator<<();
            }
            return os;
        }
        
    public:
        Noble (const string& mynobsname): noblename(mynobsname) {nobledead = false;  Totalstrengths = 0; }
        
        const string& Noblenamegetter() const {
            return noblename;
        }
    //  helps nobles hire warriors. Checks if he is dead first, because dead nobles cannot hire warriors. Also checks if warrior is already hired, and if not, hires him by adding him into vector of warriors.
        bool hire (Warrior& hirwarr) {
            if (hirwarr.Warriorstrengthgetter() == 0) {
                cout << "The dead warrior cannot be hired." << endl;
            }
            else if (nobledead == false){
                if (hirwarr.ishired() == false){
                    hirwarr.setlord->(this);
                    myWarrsvec.push_back(&hirwarr);
                    Totalstrengths += hirwarr.Warriorstrengthgetter();
                    return true;
                }
                else {
                    cout << "He's hired; hiring failed. " << endl;
                    return false;
                }
            }
            else {
                cout << "Dead nobles cannot hire warriors; hiring failed.";
                return false;
                }
        }
//            when the warrior runs away or is fired, helps remove him from the vector of pointers
        bool removehim(Warrior& him) {
            size_t j;
            Warrior* warrptr = nullptr;
            for (size_t ind1 = 0; ind1 < myWarrsvec.size(); ++ind1) {
                if (myWarrsvec[ind1] == &him)
                    {j = ind1;
                    warrptr = myWarrsvec[myWarrsvec.size()-1];
                    myWarrsvec[myWarrsvec.size()-1] = myWarrsvec[j];
                    myWarrsvec[j]= warrptr;
                    myWarrsvec.pop_back();
                    Totalstrengths -= hirwarr.Warriorstrengthgetter();
                    him.setfree();
                    return true;
                    }
                }
            return false;
        }
        void fire (Warrior& hirwarr) {
            if (nobledead == false) && (hirwarr.getlord() != nullptr) {
                for (size_t i = 0; i < myWarrsvec.size(); ++i){
                if (myWarrsvec[i] == &hirwarr)
                    {
                        removehim(myWarrsvec[i]);
                    }
                    }
            cout << "You don't work for me anymore" << hirwarr.Warriornamegetter() << "! -- " << noblename << '.' << endl;
                }
            else{
                cout << "Dead nobles cannot fire warriors; firing failed." << endl;
                    }
            }

    //        helps display battle results and update noble status and their warrior strengths
        void battle (Noble& enemynob){
            cout << noblename << " battles " << enemynob.Noblenamegetter() << endl;
            if (Totalstrengths == 0 && enemynob.Totalstrengths == 0) {
                cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
            }
            else if (Totalstrengths - enemynob.Totalstrengths == 0){
                cout << "Mutual Annihalation:" << noblename << "and" << enemynob.noblename << "die at each other's hands" << endl;
                Totalstrengths = 0;
                nobledead = true;
                enemynob.nobledead = true;
                enemynob.Totalstrengths = 0;
                for (size_t ind = 0; ind < myWarrsvec.size(); ++ind) {
                    myWarrsvec[ind]->reStrength(0);
                }
                for (size_t ind2 = 0; ind2 < enemynob.myWarrsvec.size(); ++ind2) {
                    enemynob.myWarrsvec[ind2]->reStrength(0);
                
                }
            }
            else if (Totalstrengths == 0){
                cout << "He's dead," << enemynob.Noblenamegetter() << endl;
            }
            else if (enemynob.Totalstrengths == 0){
                cout << "He's dead," << noblename << endl;
            }
            else if (Totalstrengths - enemynob.Totalstrengths > 0){
                cout << noblename << "defeats" << enemynob.noblename;
                Totalstrengths -= enemynob.Totalstrengths;
                enemynob.nobledead = true;
                int mynewstrengths;
                enemynob.Totalstrengths = 0;
                for (size_t ind = 0; ind < myWarrsvec.size(); ++ind) {
                    mynewstrengths = myWarrsvec[ind]->Warriorstrengthgetter() * (1 - (enemynob.Totalstrengths)/ Totalstrengths);
                    myWarrsvec[ind]->reStrength(mynewstrengths);
                }
                for (size_t ind2 = 0; ind2 < enemynob.myWarrsvec.size(); ++ind2) {
                    enemynob.myWarrsvec[ind2]->reStrength(0);
                }
                    
            }
            else if (Totalstrengths - enemynob.Totalstrengths < 0){
                cout << enemynob.noblename << "defeats" << noblename;
                enemynob.Totalstrengths -= Totalstrengths;
                nobledead = true;
                int hisnewstrength;
                Totalstrengths = 0;
                for (size_t ind = 0; ind < myWarrsvec.size(); ++ind) {
                    myWarrsvec[ind]->reStrength(0);
                }
                for (size_t ind2 = 0; ind2 < enemynob.myWarrsvec.size(); ++ind2) {
                    hisnewstrength = enemynob.myWarrsvec[ind2]->Warriorstrengthgetter() * (1 - Totalstrengths/ (enemynob.Totalstrengths));
                    enemynob.myWarrsvec[ind2]->reStrength(hisnewstrength);
                }
                }
        }
    private:
        string noblename;
        bool nobledead = false;
        vector <Warrior*> myWarrsvec;
        int Totalstrengths = 0;
    };
            }


    


