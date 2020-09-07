//
//  main.cpp
//  hw6_
//
//  Created by Sarah Xiao on 3/31/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#include "Noble.h"
#include "Warrior.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Noble;
    class Warrior {
        friend ostream& operator << (ostream& os, const Warrior& warror);
    public:
//  function definitions only
//        for creating a warrior
        Warrior(const string& Name, int Strength);
//        getter/setter methods
        const string& Warriornamegetter() const;
        const int Warriorstrengthgetter() const;
        void reStrength(int newstrength);
        const bool ishired (Noble& thenoble);
        void setfree();
//        new runaway method with employment methds
        bool runaway();

    private:
        string warsname;
        int warsstrength;
        Noble* mynob;
};

class Noble{
        friend ostream& operator << (ostream& os, const Noble& thenoble);
        public:
//        function definitions only
//        creating a noble
            Noble (const string& mynobsname);
            const string& Noblenamegetter() const;
        //  helps nobles hire warriors. Checks if he is dead first, because dead nobles cannot hire warriors. Also checks if warrior is already hired, and if not, hires him by adding him into vector of warriors.
            bool hire (Warrior& hirwarr);
//      fires warriors, removes him from army
            void fire (Warrior& hirwarr);
        //        helps display battle results and update noble status and their warrior strengths
        void battle (Noble& enemynob);
        bool removehim(Warrior& him);
        private:
            string noblename;
            bool nobledead = false;
            vector <Warrior*> myWarrsvec;
            int Totalstrengths = 0;
        };

Warrior::Warrior() {}
    //helps display warrior status
    friend ostream& operator << (ostream& os, const Warrior& warror) {
        os << warror.Warriornamegetter() << ':' << warror.Warriorstrengthgetter() << endl;
        return os;
    }

public:
    Warrior::Warrior(const string& Name, int Strength) : warsname(Name), warsstrength(Strength), mynob(nullptr) {}
    const string& Warrior::Warriornamegetter() const {
        return warsname;
    }
    const int Warrior::Warriorstrengthgetter() const {
        return warsstrength;
    }
//    updates warrior strengths
    void Warrior::reStrength(int newstrength) {
        warsstrength = newstrength;
    }
    
//checks if the warrior is hired to avoid hiring repeatedly
    bool Warrior::ishired () {
        if (mynob != nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
//sets pointer to null when warrior is fired or runs away
    void Warrior::setfree () {
            mynob = nullptr;
        }
    
    bool Warrior::runaway() {
        if (mynob!= nullptr) {
            mynob->removehim(*this);
        }
        if (mynob->removehim(*this)) == true){
            cout << name << " flees in terror, aboandoning his lord, " << mynob->getNobleName() << endl;
        return true;
            }
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
        Noble::Noble() {}
        
        friend ostream& operator << (ostream& os, const Noble& thenoble) {
            cout << thenoble.noblename << "has an army of" << thenoble.myWarrsvec.size() << endl;
            for (size_t ind = 0; ind < thenoble.myWarrsvec.size(); ++ind) {
                cout << thenoble.myWarrsvec[ind];
            }
            return os;
        }
        
    public:
        Noble::Noble (const string& mynobsname): noblename(mynobsname) {nobledead = false;  Totalstrengths = 0; }
        
        const string& Noble::Noblenamegetter() const {
            return noblename;
        }
    //  helps nobles hire warriors. Checks if he is dead first, because dead nobles cannot hire warriors. Also checks if warrior is already hired, and if not, hires him by adding him into vector of warriors.
        bool Noble::hire (Warrior& hirwarr) {
            if (hirwarr.Warriorstrengthgetter() == 0) {
                cout << "The dead warrior cannot be hired." << endl;
            }
            else if (nobledead == false){
                if (hirwarr.ishired() == false){
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
        bool Noble::removehim(Warrior& him) {
            size_t j;
            Warrior* warrptr = nullptr;
            for (size_t ind1 = 0; ind1 < myWarrsvec.size(); ++ind1) {
                if (myWarrsvec[ind1]->Warriornamegetter() == him.Warriornamegetter())
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
        void Noble::fire (Warrior& hirwarr) {
            if (nobledead == false){
                for (size_t i = 0; i < myWarrsvec.size(); ++i){
                if (myWarrsvec[i]->Warriornamegetter() == hirwarr.Warriornamegetter())
                    {
                        removehim(myWarrsvec[i]);
                    }
                    }
            hirwarr.setfree();
            cout << "You don't work for me anymore" << hirwarr.Warriornamegetter() << "! -- " << noblename << '.' << endl;
                }
            else{
                cout << "Dead nobles cannot fire warriors; firing failed." << endl;
                    }
            }

    //        helps display battle results and update noble status and their warrior strengths
        void Noble::battle (Noble& enemynob){
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

        int main() {
            Noble art("King Arthur");
            Noble lance("Lancelot du Lac");
            Noble jim("Jim");
            Noble linus("Linus Torvalds");
            Noble billie("Bill Gates");
            
            Warrior cheetah("Tarzan", 10);
            Warrior wizard("Merlin", 15);
            Warrior theGovernator("Conan", 12);
            Warrior nimoy("Spock", 15);
            Warrior lawless("Xena", 20);
            Warrior mrGreen("Hulk", 8);
            Warrior dylan("Hercules", 3);
            
            jim.hire(nimoy);
            lance.hire(theGovernator);
            art.hire(wizard);
            lance.hire(dylan);
            linus.hire(lawless);
            billie.hire(mrGreen);
            art.hire(cheetah);
            
            cout << jim << endl;
            cout << lance << endl;
            cout << art << endl;
            cout << linus << endl;
            cout << billie << endl;

            cheetah.runaway();
            cout << art << endl;
            
            art.battle(lance);
            jim.battle(lance);
            linus.battle(billie);
            billie.battle(lance);
        }
