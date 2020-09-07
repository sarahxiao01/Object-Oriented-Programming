    //
//  main.cpp
//  hw05
//
//  Created by Sarah Xiao on 3/3/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


//warrior constructor, creates warriors
class Warrior {
    
public:
    Warrior(const string& Name, int Strength) : warsname(Name), warsstrength(Strength), {mynob = nullptr; };
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
    Noble (const string& mynobsname): noblename(mynobsname) {nobledead = false;  Totalstrengths = 0; };
    
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

    void fire (Warrior& hirwarr){
        if (nobledead == false){
            hirwarr.isfired();
            size_t j;
            Warrior* warrptr = nullptr;
            for (size_t i = 0; i < myWarrsVec.size(); ++i){
                if (myWarrsvec[i]->Warriornamegetter() == hirwarr.Warriornamegetter())
                {
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
//checks if there are no nobles in the pointer vector
bool Nonobles (const vector <Noble*>& vector){
    if (vector.size() == 0){
        return true;
        }
    else {
        return false;
                }
}
//checks if there are no warriors in the pointer vector
bool Nowarriors (const vector <Warrior*>& vector){
    if (vector.size() == 0){
        return true;
    }
    else {
        return false;
            }
    }

//checks if the noble exists
bool ifNoble (const string& ifname, const vector<Noble*>& myvec){
    j = -1;
    for (size_t i = 0; i < myvec.size(); ++i) {
        if (myvec[i]->Noblenamegetter() == ifname) {
            j = i;
            break;
            }
    if (j != -1){
        return true;
    }
    return false;
            
        }
    }

//check if warrior exists
bool ifWarrior (const string& ifname, const vector<Noble*>& myvec){
    j = -1;
    for (size_t i = 0; i < myvec.size(); ++i) {
        if (myvec[i]->Warriornamegetter() == ifname) {
            j = i;
            break;
            }
    if (j != -1){
        return true;
    }
    return false;
            
        }
    }

            void Status(const vector <Warrior*>& warrsvecto, const vector<Noble*>& nobsvecto) {
                if (Nonobles(nobsvecto) == false) {
                    for (size_t i = 0; i < nobsvecto.size(); ++i) {
                        cout << *(nobsvecto[i]);
                            }
                        }
                else {
                    cout << "NONE" << endl;
                            }
                cout << "Unemployed Warriors" << endl;
                for (size_t ind = 0; ind < warrsvecto.size(); ++ind) {
                    bool empty = true;
                    if (*warrsvecto[ind]->ishired() == false) {
                        empty = false;
                        cout << *(warrsvecto[ind]) << endl;
            }
                    if (empty == false){
                        cout << "NONE" << endl;
                        }
        }

            void Battles (const string& nob, const string& nobbs, const vector<Noble*>& nobvector) {
                if (ifNoble(nob, nobvector) == false) {
                    cout << "He does not exist, battle failed" << endl;
                            }
                else {
                    if (ifNoble(nobbs, nobvector) == false) {
                        cout << "His enemy does not exist, battle failed" << endl;
                                }
                    else    {
                        int mypos = noblelocator(nob, nobvector);
                        int hispos  = noblelocator(nobbs, nobvector);
                        nobvector[mypos].battle(*(nobvector[hispos]));
                    }
            }
                    }
//Clears everything in the vector
void Warriorclear(vector<Warrior*>& theVec) {
    for (size_t ind = 0; ind < theVec.size(); ++ind) {
        delete (theVec[ind]);
        theVec[ind] = nullptr;
    }
    theVec.clear();
    }
        }
void Noblesclear(vector<Noble*>& theVector) {
    for (size_t i = 0; i < theVector.size(); ++i) {
            delete (theVector[i]);
            theVector[i] = nullptr;
    }
    theVector.clear();
}
               }
//locates warriors and nobles in their vectors using their names as input string
size_t warriorlocator(const string& name, const vector<Warrior*>& vector) {
        for (size_t i = 0; i < vector.size(); ++i) {
            if (vector[i]->Warriornamegetter() == name) {
                        return i;
            }
            }
                return vector.size();
            }

size_t noblelocator(const string& name,const vector<Noble*>& vector) {
                for (size_t i = 0; i < vector.size(); ++i) {
                    if (vector[i]->Noblenamegetter() == name) {
                        return i;
                    }
                }
                return vector.size();
                 }
int main {
    ifstream fname ("nobleWarriors.txt");
    if (!fname) {
        cerr << "Could not open the file.";
        exit(1);
            }
    string instruction;
        
    bool ifWarrior;
        
    bool ifNoble;
        
    string nName;
        
        
    string wName;
        
    string mynobname;
        
    string enemynobname;
        
    int thewarstrength;
        
    vector <Warrior*> WarriorsVec;
        
    vector <Noble*> NobVec;
    while (fname >> instruction) {
        if (instruction == "Noble") {
            fname >> nName;
                if (Nonobles(NobVec == true)) {
                    Noble* nobptr = new Noble(nName);
                    NobVec.push_back(nobptr);
                                }
                else if (ifNoble(nName, NobVec) == false) {
                        Noble* nobptr = new Noble(nName);
                        NobVec.push_back(nobptr);
                       }
                else    {
                        cout << "This noble already exists, failed to create" << endl;
                                }
                    }
        else if (instruction == "Warrior") {
            fname >> wName >> thewarstrength;
                if (Nowarriors(WarriorsVec) == true) {
                    Warrior* newwarrptr = new Warrior(wName, thewarstrength);
                    WarriorsVec.push_back(newwarrptr);
                        }
                else if (ifWarrior(wName, WarriorsVec) == false) {
                    Warrior* newwarrptr = new Warrior(wName, thewarstrength);
                    WarriorsVec.push_back(newwarrptr);
                              }
                else    {
                    cout << "This warrior already exists, failed to create" << endl;
                           }
        }
        else{
            
            if (instruction == "Clear") {
                Warriorclear(WarriorsVec);
                Noblesclear(NobVec);
                    }
            if (instruction == "Status") {
                cout << "Status" << endl;
                cout << "======" << endl;
                cout << "Nobles:" << endl;
                Status(NobVec, WarriorsVec);
                    }
            if (instruction == "Fire") {
                fname >> nName >> wName;
                Fire(nName, wName, NobVec, WarriorsVec);
                }
            if (instruction == "Hire") {
                fname >> nName >> wName;
                Hire(nName, wName, NobVec, WarriorsVec);
    }
            else (instruction == "Battle") {
                fname >> mynobname >> enemynobname;
                Battles(mynobname, enemynobname, NobVec);
                }
        }
        fname.close();
    }


//each Noble having a unique name and each Warrior having a unique name

//commands
//Noble. Create a Noble on the heap.
//Warrior. Create a Warrior on the heap.
//Hire. Call the Noble's hire method.
//Fire. Call the Noble's fire method.
//Battle. Call the Noble's battle method.
//Status. The status command shows the nobles, together with their armies, as we did previously. In addition, it will show separately the warriors who do not currentle have a employer
//Clear. Clear out all the nobles and warriors that were created.

//
//  helps nobles hire warriors; checks if either of them does not exist, in which case hiring would fail. Checks if he is dead first, because dead nobles cannot hire warriors. Also checks if warrior is already hired, and if not, hires him by adding him into vector of warriors.
void Hire(const string& nname, const string& wname,  vector <Warrior*>& wvector,  vector<Noble*>& nvector) {
    if (ifNoble(nname, nvector) == false) {
        cout << "This noble does not exist, hiring failed" << endl;
            }
    else {
        if (ifWarrior(wname, wvector) == false)     {
            cout << "This warrior does not exist, firing failed" << endl;
          }
        else {
            int npos = noblelocator(nname, nvector);
            int wpos  = warriorlocator(wname, wvector);
            nvector[npos]->hire(wvector[wpos]);
                      }
        }
}
            
//helps fire warriors by removing him from vector of warriors. Checks if either of them does not exist, in which case firing would fail. Checks if he is dead first, because dead nobles cannot fire warriors. Also checks if warrior is in the army, and if yes, remove him from the vector of warriors.
void Fire(const string& nname, const string& wname,  vector <Warrior*>& wvector,  vector<Noble*>& nvector) {
    if (ifNoble(nname, nvector) == false) {
        cout << "This noble does not exist, hiring failed" << endl;
                }
    else{
        if (ifWarrior(wname, wvector) == false)     {
            cout << "This warrior does not exist, firing failed" << endl;
        }
        if ((wname, wvector) == false)     {
            cout << "This warrior does not exist, firing failed" << endl;
        }
        else {
            int npos = noblelocator(nname, nvector);
            int wpos  = warriorlocator(wname, wvector);
            nvector[npos]->fire(wvector[wpos]);
                              }
                        }
}



//checks if there are no nobles in the pointer vector
bool Nonobles (const vector <Noble*>& vector){
    if (vector.size() == 0){
        return true;
        }
    else {
        return false;
                }
}
//checks if there are no warriors in the pointer vector
bool Nowarriors (const vector <Warrior*>& vector){
    if (vector.size() == 0){
        return true;
    }
    else {
        return false;
            }
    }

//checks if the noble exists
bool ifNoble (const string& ifname, const vector<Noble*>& myvec){
    size_t j = myvec.size();
    for (size_t i = 0; i < myvec.size(); ++i) {
        if (myvec[i]->Noblenamegetter() == ifname) {
            j = i;
            break;
            }
    if (j != myvec.size()){
        return true;
    }
    return false;
            
        }
    }

//check if warrior exists
bool ifWarrior (const string& ifname, const vector<Warrior*>& myvec){
    size_t j = myvec.size();
    for (size_t i = 0; i < myvec.size(); ++i) {
        if (myvec[i]->Warriornamegetter() == ifname) {
            j = i;
            break;
            }
        if (j != myvec.size(){
        return true;
    }
    return false;
            
        }
    }

            void Battles (const string& nob, const string& nobbs, const vector<Noble*>& nobvector) {
                if (ifNoble(nob, nobvector) == false) {
                    cout << "He does not exist, battle failed" << endl;
                            }
                else {
                    if (ifNoble(nobbs, nobvector) == false) {
                        cout << "His enemy does not exist, battle failed" << endl;
                                }
                    else    {
                        int mypos = noblelocator(nob, nobvector);
                        int hispos  = noblelocator(nobbs, nobvector);
                        nobvector[mypos].battle(*(nobvector[hispos]));
                    }
            }
                    }
