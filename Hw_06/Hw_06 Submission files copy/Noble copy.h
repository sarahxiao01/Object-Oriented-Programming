//
//  main.cpp
//  Noble__
//
//  Created by Sarah Xiao on 3/31/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#ifndef NOBLE_H
#define NOBLE_H
#include <string>
#include <iostream>
#include <vector>

namespace WarriorCraft {
    class Noble{        
        friend std::ostream& operator<< (std::ostream& os, const Noble& thenoble);
        public:
//        function definitions only
//        creating a noble
            Noble (const std::string& mynobsname);
            const std::string& Noblenamegetter() const;
        //  helps nobles hire warriors. Checks if he is dead first, because dead nobles cannot hire warriors. Also checks if warrior is already hired, and if not, hires him by adding him into vector of warriors.
            bool hire (Warrior& hirwarr);
//      fires warriors, removes him from army
            void fire (Warrior& hirwarr);
        //        helps display battle results and update noble status and their warrior strengths
        void battle (Noble& enemynob);
        bool removehim(Warrior& him);
        private:
            std::string noblename;
            bool nobledead = false;
            std::vector <Warrior*> myWarrsvec;
            int Totalstrengths = 0;
        };
        }
#endif
