//
//  main.cpp
//  hw04
//
//  Created by Sarah Xiao on 2/27/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//warrior constructor, creates warriors
class Warrior {
    
public:
    Warrior(const string& Name, int Strength, Noble* mynoble) : warsname(Name), warsstrength(Strength), mynoble(mynob) {};
    const string Warriornamegetter() const {
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
    bool ishired (Noble& thenoble) {
        if (mynob != nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
//sets pointer to null when warrior is fired
    void isfired () {
            mynob = nullptr;
        }
//makes name, strength and his lord private
private:
    string warsname;
    int warsstrength;
    Noble* mynob = nullptr;
};
    
//helps display warrior status
ostream& operator << (ostream& os, const Warrior& warror) {
    os << warror.Warriornamegetter() << ':' << warror.Warriorstrengthgetter() << endl;
    return os;
}

//Noble class constructor
class Noble{
public:
    Noble (const string& mynobsname): noblename(mynobsname) {};
    
    const string Noblenamegetter() const {
        return noblename;
    }
//  helps nobles hire warriorsl; checks if he is dead first, because dead nobles cannot hire warriors. Also checks if warrior is already hired, and if not, hires him by adding him into vector of warriors.
    bool hire (Warrior& hirwarr) {
        if (nobledead == false){
            if (hirwarr.ishired(*this) == false){
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
//helps fire warriors by removing him from vector of warriors
    void fire (Warrior& hirwarr){
        if (nobledead == false){
            hirwarr.isfired();
            size_t j;
            Warrior* warrptr = nullptr;
            for (size_t i = 0; i < myWarrsVec.size(); ++i){
                if (myWarrsvec[i]->Warriornamegetter() == hirwarr.Warriornamegetter()){
                    j=i;
                }
            }
            warrptr = myWarrsvec[myWarrsVec.size()-1];
            myWarrsvec[myWarrsVec.size()-1] = myWarrsvec[j];
            myWarrsvec[j]= warrptr;
            myWarrsvec.pop_back();
            Totalstrengths -= hirwarr.Warriorstrengthgetter();
            cout << "You don't work for me anymore" << warriorname << "! -- " << noblename << '.' << endl;
        }
        else{
            cout << "Dead nobles cannot fire warriors; firing failed." << endl;
            }

//        helps display battle results and update noble status and their warrior strengths 
    void battle (Noble& enemynob){
        cout << name << " battles " << enemynob.Noblenamegetter() << endl;
        if (Totalstrengths == 0 && enemynob.Totalstrengths == 0) {
            cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
        }
        else if (Totalstrengths - enemynob.Totalstrengths == 0){
            cout << "Mutual Annihalation:" noblename << "and" << enemynob.noblename << "die at each other's hands" << endl;
            Totalstrengths = 0;
            nobledead = true;
            enemynob.nobledead = true;
            enemynob.Totalstrengths = 0;
            for (size_t ind = 0; ind < myWarrsvec.size(); ++ind) {
                myWarrsvec[ind].reStrength(0);
            }
            for (size_t ind2 = 0; ind2 < enemynob.myWarrsvec.size(); ++ind2) {
                enemynob.myWarrsvec[ind].reStrength(0);
            
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
                mynewstrength = myWarrsvec[ind]->Warriorstrengthgetter() * (1 - (enemynob.Totalstrengths)/ Totalstrengths);
                myWarrsvec[ind].reStrength(mynewstrength);
            }
            for (size_t ind2 = 0; ind2 < enemynob.myWarrsvec.size(); ++ind2) {
                enemynob.myWarrsvec[ind].reStrength(0);
            }
                
        }
        else if (Totalstrengths - enemynob.Totalstrengths < 0){
            cout << enemynob.noblename << "defeats" << noblename;
            enemynob.Totalstrengths -= Totalstrengths;
            nobledead = true;
            int hisnewstrength;
            Totalstrengths = 0;
            for (size_t ind = 0; ind < myWarrsvec.size(); ++ind) {
                myWarrsvec[ind].reStrength(0);
            }
            for (size_t ind2 = 0; ind2 < enemynob.myWarrsvec.size(); ++ind2) {
                hisnewstrength = enemynob.myWarrsvec[ind2]->Warriorstrengthgetter() * (1 - Totalstrengths/ (enemynob.Totalstrengths));
                enemynob.myWarrsvec[ind2].reStrength(hisnewstrength);
            }
            }
    }
private:
    string noblename;
    bool nobledead = false;
    vector <Warrior*> myWarrsvec;
    int Totalstrengths = 0;
};
        
ostream& operator << (ostream& os, const Noble& thenoble) {
    cout << thenoble.noblename << "has an army of" << thenoble.myWarrsvec.size() << endl;
    for (size_t ind = 0; ind < thenoble.myWarrsvec.size(); ++ind) {
        cout << thenoble.myWarrsvec.[ind];
    }
    return os;
    }

    

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
    
    cout << "==========\n"
         << "Status before all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";
    
    art.fire(cheetah);
    cout << art << endl;
    
    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);

    cout << "==========\n"
         << "Status after all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";
    
}
