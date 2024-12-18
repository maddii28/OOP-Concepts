#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include <fstream>
#include <iostream>
#include <string>

namespace WarriorCraft {
    //forward declaration
    class Noble;
    
    // warrior class is handling warrior name, strength and hire/fire status
    class Warrior {
        friend std::ostream& operator<<(std::ostream& os, const Warrior& somewarrior);
        public:
            Warrior(const std::string& name, double strength);
            const std::string& getName() const;
            double getStrength() const;
            void setStrength(double strength);
            void setNoble(Noble* nobleptr);
            bool isHired() const;
            bool runaway();
            
        private:
            std::string warrior_name;
            double warrior_strength;
            Noble* nob_lord;
    };

} //namespace WarriorCraft

#endif