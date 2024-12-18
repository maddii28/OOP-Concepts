#include "Noble.hpp"
#include "Warrior.hpp"
using namespace std;

namespace WarriorCraft {

    // Warrior class definitions

    // Warrior Constructor
    Warrior::Warrior(const string& name, double strength)
        : warrior_name(name), warrior_strength(strength), nob_lord(nullptr) {}

    const string& Warrior::getName() const { return warrior_name; }
    double Warrior::getStrength() const { return warrior_strength; }
    void Warrior::setStrength(double strength) { warrior_strength = strength; }
    void Warrior::setNoble(Noble* nobleptr) { nob_lord = nobleptr; }

    bool Warrior::isHired() const {
        if (nob_lord == nullptr) {
            return false;
        }
        else {
            return true;
        }
    }

    // Utilizes cyclic association to let the warrior run away
    bool Warrior::runaway() {
        if (warrior_strength == 0 && !nob_lord) {  
            cout << "Runaway failed for " << warrior_name << endl;
            return false;
        }

        if (nob_lord->removeWarrior(*this)) {
            cout << warrior_name << " flees in terror, abandoning his lord, "
                 << nob_lord->getName() << endl;
            setNoble(nullptr);
            return true;
        }
        return false;
    }

    // Helps in displaying details about the warrior 
    ostream& operator<<(ostream& os, const Warrior& somewarrior) {
        os << "   " << somewarrior.warrior_name << ": " << somewarrior.warrior_strength;
        return os;
    }

}  // namespace WarriorCraft
