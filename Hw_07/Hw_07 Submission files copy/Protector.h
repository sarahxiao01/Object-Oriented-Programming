//
//  main.cpp
//  Protector_
//
//  Created by Sarah Xiao on 4/16/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#ifndef PROTECTOR_H
#define PROTECTOR_H
#include <string>
#include <iostream>
#include <vector>


namespace WarriorCraft {
    class Noble;
    class Protector {
        friend std::ostream& operator<< (std::ostream& os, const Protector& warror);
    public:
//  function definitions only
//        for creating a protector
        Protector(const std::string& Name, int Strength);
//        getter/setter methods
        const std::string& Protectornamegetter() const;
        const int Protectorstrengthgetter() const;
        void reStrength(int newstrength);
        Noble* getlord();
        Noble* setlord (Noble* lord);
        const bool ishired (Noble& thenoble);
        void setfree();
//        new runaway method with employment methds
        bool runaway();
        virtual void warCry() const = 0;

    private:
        std::string warsname;
        int warsstrength;
        Noble* mynob;
    };
    class Wizard: public Protector{
    public:
        Wizard (const std::string& Name, int Strength);
        void warCry() const;
    };

    class Warrior: public Protector{
    public:
        Warrior (const std::string& Name, int Strength);
        void warCry() const;
    };

    class Swordsman: public Warrior{
    public:
        Swordsman (const std::string& Name, int Strength);
        void warCry() const;
    };

    class Archer: public Warrior{
    public:
        Archer (const std::string& Name, int Strength);
        void warCry() const;
    };
}
#endif
