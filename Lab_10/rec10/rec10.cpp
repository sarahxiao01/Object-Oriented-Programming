//
//  main.cpp
//  rec10
//
//  Created by Sarah Xiao on 4/10/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//


#include <iostream>
#include <vector>
using namespace std;

class Instrument {
public:
    virtual void makeSound() const = 0;
    virtual void Play() = 0;
};
void Instrument::makeSound() const{
    cout << "To make a sound... ";
}

class MILL {
public:
    void receiveInstr(Instrument& myinstr){
        myinstr.makeSound();
        for (size_t index = 0; index < lib.size(); ++index){
            if (lib[index] == nullptr) {
                lib[index]= &myinstr;
                return;
            }
        }
        lib.push_back(&myinstr);
    }
    void dailyTestPlay(){
        for (size_t index = 0; index < lib.size(); ++index){
            if (lib[index] != nullptr) {
               lib[index]->makeSound();
            }
        }
    }
    Instrument* loanOut(){
        Instrument* me;
        for (size_t index = 0; index < lib.size(); ++index){
            if (lib[index] != nullptr){
                me = lib[index];
                lib[index] = nullptr;
                return me;
            }
        }
        return nullptr;
    }
private:
    vector<Instrument*> lib;
};

class Brass: public Instrument {
public:
    Brass (const unsigned& mysize): size(mysize) {}
    void makeSound() const {
        Instrument::makeSound();
        cout << "blow on a mouthpiece of size" << size << '"';
    }
private:
    unsigned size;
};

class Trombone: public Brass {
public:
    using Brass::Brass;
    void Play() {
        cout << "Blat";
    }
};

class Trumpet: public Brass  {
public:
    using Brass::Brass;
    void Play() {
        cout << "Toot";
    }
};

class String: public Instrument  {
public:
    String(const unsigned& mypitch): pitch(mypitch) {}
    void makeSound() const {
        Instrument::makeSound();
        cout << "bow a string with pitch" <<  pitch << '"';
    }
private:
    unsigned pitch;
};

class Cello: public String {
public:
    using String::String;
    void Play() {
        cout << "Squawk";
    }
};

class Violin: public String  {
public:
    using String::String;
    void Play() {
        cout << "Screech";
    }
};

class Percussion: public Instrument  {
public:
    void makeSound() const {
        Instrument::makeSound();
        cout << "hit me!";
    }
};

class Drum: public Percussion {
public:
    using Percussion::Percussion;
    void Play() {
        cout << "Boom";
    }
};

class Cymbal: public Percussion  {
public:
    using Percussion::Percussion;
    void Play() {
        cout << "Crash";
    }
};

class Musician {
public:
    Musician() : instr(nullptr) {}

    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    Instrument* giveBackInstr() {
        Instrument* result(instr);
        instr = nullptr;
        return result;
    }

    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << "have no instr\n";
    }
    void myPlay() {
        if (instr){
            instr->Play();
        }
    }

private:
    Instrument* instr;
};

class Orch {
public:
    void play(){
        for (size_t index = 0; index < artists.size(); ++index){
            artists[index]->myPlay();
        }
    }
    void addPlayer(Musician& muse){
        artists.push_back(&muse);
    }
private:
    vector<Musician*> artists;
};


//// PART ONE
//int main() {
//
//     cout << "Define some instruments ------------------------------------\n";
//     Drum drum;
//     Cello cello(673);
//     Cymbal cymbal;
//     Trombone tbone(4);
//     Trumpet trpt(12) ;
//     Violin violin(567) ;
//
//     // use the debugger to look at the mill
//     cout << "Define the MILL --------------------------------------------\n";
//     MILL mill;
//
//     cout << "Put the instruments into the MILL --------------------------\n";
//     mill.receiveInstr(trpt);
//     mill.receiveInstr(violin);
//     mill.receiveInstr(tbone);
//     mill.receiveInstr(drum);
//     mill.receiveInstr(cello);
//     mill.receiveInstr(cymbal);
//
//     cout << "Daily test -------------------------------------------------\n";
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//
//     cout << "Define some Musicians---------------------------------------\n";
//     Musician harpo;
//     Musician groucho;
//
//     cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
//     groucho.testPlay();
//     cout << endl;
//     groucho.acceptInstr(mill.loanOut());
//     cout << endl;
//     groucho.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//
//     cout << endl << endl;
//
//     groucho.testPlay();
//     cout << endl;
//     mill.receiveInstr(*groucho.giveBackInstr());
//     harpo.acceptInstr(mill.loanOut());
//     groucho.acceptInstr(mill.loanOut());
//     cout << endl;
//     groucho.testPlay();
//     cout << endl;
//     harpo.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//
//     cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
//
//     // fifth
//     mill.receiveInstr(*groucho.giveBackInstr());
//     cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
//     mill.receiveInstr(*harpo.giveBackInstr());
//
//
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//
//     cout << endl;
//}
// PART TWO
int main() {
    // The initialization phase

    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);

    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);

    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;

    Orch orch;

    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

} // main
