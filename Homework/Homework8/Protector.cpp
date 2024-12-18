// File: Protector.cpp
// Author: Maddhav Suneja
// Description: Implementation file


#include "Protector.hpp"
#include "Noble.hpp"
#include <iostream>
using namespace std;

namespace WarriorCraft {

    Protector::Protector(const string& name, double strength)
        : name(name), strength(strength), lord(nullptr) {}

    const string& Protector::getName() const {
        return name;
    }

    double Protector::getStrength() const {
        return strength;
    }

    Lord* Protector::getLord() const { return lord; }

        // let the Protector runaway
    bool Protector::runaway() {
        if (strength == 0) {  // fail if Protector is dead
            cout << name << " is already dead!" << endl;
            return false;
        }
        if (!lord) {  // fail if lord is a nullptr
            cout << name << " doesn't have a lord!";
            return false;
        }
        string lordname = lord->getName();
        if (lord->remove(*this)) {
            cout << name << " flees in terror, abandoning his lord, "
                 << lordname << endl;
            return true;
        }
        return false;  // fail if the Protector is not removed from the army
    }

    void Protector::setStrength(double newStrength) {
        strength = newStrength;
    }

    void Protector::setLord(Lord* newLord) {
        lord = newLord;
    }

    std::ostream& operator<<(std::ostream& os, const Protector& protector) {
        os << "Protector Name: " << protector.name << ", Strength: " << protector.strength;
        return os;
    }

    void Warrior::defend() const {
        cout << getName() << " says: Take that in the name of my lord, "
        << getLord()->getName() << endl;
    }

    // Wizard Implementation Code
    void Wizard::defend() const { cout << "POOF!" << endl; }

    // Archer Implementation Code
    void Archer::defend() const {
        cout << "TWANG! ";
        Warrior::defend();
    }

    // Archer Implementation Code
    void Swordsman::defend() const {
        cout << "CLANG! ";
        Warrior::defend();
    }
}
