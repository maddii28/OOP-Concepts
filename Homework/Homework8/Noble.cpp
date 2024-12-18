// File: Noble.cpp
// Author: Maddhav Suneja
// Description: Defines the Noble class and the Lord class for managing 
// nobles and their armies in the WarriorCraft game.



#include <iostream>
#include <vector>
#include "Noble.hpp"
#include "Protector.hpp"
using namespace std;

namespace WarriorCraft {


    Noble::Noble(const string& theName) : name(theName), alive(true) {}


    const string& Noble::getName() const { return name; }
    void Noble::changeAliveStatus() { alive = !alive; }
    bool Noble::getAliveStatus() const { return alive; }

    // Battle betweem Nobles
    void Noble::battle(Noble& enemy) {
        cout << name << " battles " << enemy.name << endl;

        if (!alive && !enemy.alive) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;

        } else if (!alive && enemy.alive) {
            enemy.defend();
            cout << "He's dead, " << enemy.name << endl;

        } else if (alive && !enemy.alive) {
            defend();
            cout << "He's dead, " << name << endl;
            
        } else {  // both Nobles are alive
            int self_strength = getStrength();
            int enemy_strength = enemy.getStrength();
            defend();
            enemy.defend();

            if (self_strength == enemy_strength) {
                die();
                enemy.die();
                cout << "Mutual Annihilation: " << name << " and " << enemy.name
                     << " die at each other's hands" << endl;

            } else if (self_strength > enemy_strength) {
                updateStrength(self_strength, enemy_strength);
                enemy.die();
                cout << name << " defeats " << enemy.name << endl;

            } else {  // self_strength < enemy_strength
                enemy.updateStrength(enemy_strength, self_strength);
                die();
                cout << enemy.name << " defeats " << name << endl;
            }
        }
    }

    void Noble::die() {  // change the status of "alive" and set strength to 0
        changeAliveStatus();
        updateStrength(1, 1);
    }

    // Lord Implementation Code
    Lord::Lord(const std::string& theName) : Noble(theName) {}

    ostream& operator<<(ostream& os, const Lord& lord) {
        os << lord.getName() << " has an army of size: " << lord.army.size() << endl;
        for (size_t i = 0; i < lord.army.size(); ++i){
            os << '\t'<< lord.army[i]->getName() <<" has strength " << lord.army[i]->getStrength() << endl;
        }
        return os;
    }

    double Lord::getStrength() const {
        // sum up strengths of all the Warriors in the army and return
        double total_strength = 0;
        for (Protector* curr_ptr : army) {
            total_strength += curr_ptr->getStrength();
        }
        return total_strength;
    }

    // multiply strength of each Protector with the ratio
    void Lord::updateStrength(double winner_strength, double loser_strength) {
        for (Protector* curr_ptr : army) {
            double updatedStrength =
                (curr_ptr->getStrength() * (winner_strength - loser_strength)) / winner_strength;  // current strength times the ratio
            curr_ptr->setStrength(updatedStrength);
        }
    }

    // call defend() for every Protector
    void Lord::defend() const {
        for (Protector* curr_ptr : army) {
            curr_ptr->defend();
        }
    }

    // hire a Protector
    bool Lord::hires(Protector& someprotector) {
        if (!getAliveStatus()) {
            cout << "Lord " << getName() << " is already dead!" << endl;
            return false;  // fail if Noble is dead
        }
        if (someprotector.getLord()) {  // if somewarrior.lord is not a nullptr
            cout << "Protector " << someprotector.getName()
                 << " is already hired!" << endl;
            return false;  // fail if Warrior is already hired
        }
        someprotector.setLord(this);
        army.push_back(&someprotector);
        return true;
    }

    // fire a Protector
    bool Lord::fires(Protector& someprotector) {
        if (!getAliveStatus()) {
            cout << "Lord " << getName() << " is already dead!" << endl;
            return false;  // fail if Lord is dead
        }
        if (remove(someprotector)) {
            cout << "You don't work for me anymore " << someprotector.getName()
                 << "! -- " << getName() << "." << endl;
            return true;
        }
        return false;  // fail if the protector is not removed
    }

    // remove a protector (fire or runaway)
    bool Lord::remove(Protector& someprotector) {
        for (size_t i = 0; i < army.size(); i++) {
            if (army[i] == &someprotector) {
                someprotector.setLord(nullptr);
                army[i] = army.back();  // copy last element to removed
                                        // protector's place
                army.pop_back();
                return true;
            }
        }
        cout << someprotector.getName() << " is not hired by " << getName()
             << "!" << endl;
        return false;  // fail if the Protector is not hired by the Lord
    }

    ostream& operator<<(std::ostream& os, const PersonWithStrengthToFight& person) {
        os << person.getName() << "has strength " << person.getStrength();
        return os;
    }

    // PersonWithStrengthToFight Implementation Code
    PersonWithStrengthToFight::PersonWithStrengthToFight(
        const std::string& theName, double theStrength)
        : Noble(theName), strength(theStrength) {}

    // getter and setter
    double PersonWithStrengthToFight::getStrength() const { return strength; }
    void PersonWithStrengthToFight::updateStrength(double winner_strength,
                                                   double loser_strength) {
        strength -= loser_strength;
    }

    void PersonWithStrengthToFight::defend() const { cout << "Ugh!" << endl; }
        


}  // namespace WarriorCraft

