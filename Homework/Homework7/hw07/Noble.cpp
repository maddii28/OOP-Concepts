#include <iostream>
#include <vector>
#include "Noble.hpp"
#include "Warrior.hpp"
using namespace std;

namespace WarriorCraft {
    // Noble class definitions

    // Noble Constructor
    Noble::Noble(const string& name) : noble_name(name), alive(true) {}

    const string& Noble::getName() const { return noble_name; }

    // Remove the warrior from the army
    bool Noble::removeWarrior(Warrior& new_warrior) {
        for (size_t i = 0; i < army.size(); ++i) {
            if (army[i] == &new_warrior) {
                for (size_t j = i; j < army.size() - 1; ++j) {
                    Warrior* a = army[j];
                    army[j] = army[j + 1];
                    army[j + 1] = a;
                }
                army.pop_back();
                return true;
            }
        }
        return false;
    }

    // Hires the warrior after checking the noble pointer
    bool Noble::hire(Warrior& new_warrior) {
        if (!(new_warrior.isHired()) && alive) {
            army.push_back(&new_warrior);
            new_warrior.setNoble(this);
            return true;
        }
        cout << noble_name << " failed to hire " << new_warrior.getName() << endl;
        return false;
    }

    // Fires the warrior after checking the noble pointer
    bool Noble::fire(Warrior& new_warrior) {
        if (new_warrior.isHired() && alive) {
            bool removed = removeWarrior(new_warrior);
            if (removed) {
                cout << new_warrior.getName()
                     << ", You don't work for me anymore "
                     << " -- " << noble_name << endl;

                new_warrior.setNoble(nullptr);
                return true;
            }
        }
        return false;
    }

    // Battle logic between nobles and their armies
    void Noble::battle(Noble& enemy) {
        cout << noble_name << " battles " << enemy.noble_name << endl;

        if (!alive && !enemy.alive) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        } else if (!alive) {
            cout << "He's dead, " << enemy.noble_name << endl;
        } else if (!enemy.alive) {
            cout << "He's dead, " << noble_name << endl;
        } else {
            double self_strength = getArmyStrength();
            double enemy_strength = enemy.getArmyStrength();
            if (self_strength == enemy_strength) {
                die();
                enemy.die();
                cout << "Mutual Annihilation: " << noble_name << " and " << enemy.noble_name
                     << " die at each other's hands" << endl;
            } else if (self_strength > enemy_strength) {
                updateArmyStrength(self_strength, enemy_strength);
                enemy.die();
                cout << noble_name << " defeats " << enemy.noble_name << endl;
            } else {
                enemy.updateArmyStrength(enemy_strength, self_strength);
                die();
                cout << enemy.noble_name << " defeats " << noble_name << endl;
            }
        }
    }

    // Returns the total army strength of a noble
    double Noble::getArmyStrength() const {
        double total_strength = 0;
        for (const Warrior* warrior : army) {
            total_strength += warrior->getStrength();
        }
        return total_strength;
    }

    // Sets the army strength after a battle takes place
    void Noble::updateArmyStrength(double winner_strength, double loser_strength) {
        double ratio = (winner_strength - loser_strength) / winner_strength;
        for (Warrior* warrior : army) {
            warrior->setStrength(warrior->getStrength() * ratio);
        }
    }

    // Setter in case of die situation in battle
    void Noble::die() {
        alive = false;
        for (Warrior* warrior : army) {
            warrior->setStrength(0);
        }
    }

    // Helps in displaying details about the noble and its army
    ostream& operator<<(ostream& os, const Noble& somenoble) {
        os << somenoble.noble_name << " has an army of "
           << somenoble.army.size() << endl;

        for (const Warrior* warrior : somenoble.army) {
            os << *warrior << endl;
        }
        return os;
    }

} // namespace WarriorCraft
