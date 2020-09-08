//
//  main.cpp
//  Noble_
//
//  Created by Sarah Xiao on 4/16/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#ifndef NOBLE_H
#define NOBLE_H
#include <string>
#include <iostream>
#include <vector>

namespace WarriorCraft {
    class Protector;
    class Noble{
        friend std::ostream& operator<< (std::ostream& os, const Noble& thenoble);
        public:
//        function definitions only
//        creating a noble
            Noble (const std::string& mynobsname);
            const std::string& Noblenamegetter() const;
        //helps obtain and update the strength of nobles (both lords of land and person with strength to right) after battles
            virtual const int Noblestrengthgetter()const = 0;
            virtual void Noblestrengthsetter() = 0;
            virtual bool removehim(Protector& him) = 0;
        //        helps display battle results and update noble status and their protector strengths
            void battle (Noble& enemynob);
            virtual void Cry() const = 0;
        private:
            std::string noblename;
            bool nobledead = false;
        };
    class Lord: public Noble {
        public:
            Lord (const std::string& mynobsname);
            const int Noblestrengthgetter() const;
            void Noblestrengthsetter(int remaining);
    //  helps nobles hire protectors. Checks if he is dead first, because dead nobles cannot hire protectors. Also checks if protector is already hired, and if not, hires him by adding him into vector of protectors.
            bool hire (Protector& hirwarr);
    //      fires protectors, removes him from army
            void fire (Protector& hirwarr);
    //        helps display battle results and update noble status and their protector strengths
            bool removehim(Protector& him);
            void Cry() const ;
        private:
            std::vector <Protector*> myWarrsvec;
            int Totalstrengths = 0;
        };
    class PersonWithStrengthToFight: public Noble{
        public:
            PersonWithStrengthToFight(const std::string& mynobsname, int theStrength);
            const int Noblestrengthgetter() const;
            void Noblestrengthsetter(int strengthen);
            bool removehim(Protector& him);
            void Cry() const;
        private:
            int myStrength;
    };
}
#endif
