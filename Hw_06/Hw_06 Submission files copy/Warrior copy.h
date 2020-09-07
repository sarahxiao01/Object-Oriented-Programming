//
//  main.cpp
//  Warrior__
//
//  Created by Sarah Xiao on 3/31/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#ifndef WARRIOR_H
#define WARRIOR_H
#include <string>
#include <iostream>
#include <vector>


namespace WarriorCraft {

    class Warrior {
        friend std::ostream& operator<< (std::ostream& os, const Warrior& warror);
    public:
//  function definitions only
//        for creating a warrior
        Warrior(const std::string& Name, int Strength);
//        getter/setter methods
        const std::string& Warriornamegetter() const;
        const int Warriorstrengthgetter() const;
        void reStrength(int newstrength);
        Noble* getlord();
        Noble* setlord (Noble* lord);
        const bool ishired (Noble& thenoble);
        void setfree();
//        new runaway method with employment methds
        bool runaway();

    private:
        std::string warsname;
        int warsstrength;
        Noble* mynob;
};
}
#endif
