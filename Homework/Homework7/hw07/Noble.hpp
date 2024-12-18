#ifndef NOBLE_HPP
#define NOBLE_HPP

#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft {
    // Forward declaration
    class Warrior;

    // Noble manages an army of warriors as well as details of the noble itself
    class Noble {
        friend std::ostream& operator<<(std::ostream& os, const Noble& somenoble);

    public:
        Noble(const std::string& name);
        const std::string& getName() const;
        bool removeWarrior(Warrior& new_warrior);
        bool hire(Warrior& new_warrior);
        bool fire(Warrior& new_warrior);
        void battle(Noble& enemy);
        double getArmyStrength() const;
        void updateArmyStrength(double winner_strength, double loser_strength);
        void die();

    private:
        std::string noble_name;
        std::vector<Warrior*> army;
        bool alive;
    };
} 

#endif // NOBLE_HPP
