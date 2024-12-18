/*
  fileName: hw05.cpp
  Name: Maddhav Suneja
  Program: Noble-Warrior battle simulation
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//handles the warrior's details
class Warrior {
    // friend function prototype
    friend ostream& operator<<(ostream& os, const Warrior& somewarrior);

public:
    // initialization list
    Warrior(const string& theName, int theStrength)
        : name(theName), strength(theStrength), hired(false) {}

    // getters and setters
    const string& getName() const { return name; }
    int getStrength() const { return strength; }
    void setStrength(int theStrength) { strength = theStrength; }
    bool getHiredStatus() const { return hired; }
    void changeHiredStatus() { hired = !hired; }

private:
    // private variables of Warrior class
    string name;
    int strength;
    bool hired;
};

//handles the noble's army and its management 
class Noble {
    // friend function prototype
    friend ostream& operator<<(ostream& os, const Noble& somenoble);

public:
    // initialization list
    Noble(const string& theName) : name(theName), army(), alive(true) {}

    // Get the name of the Noble
    const string& getName() const { return name; }

    // Display the status of the Noble
    void display() const {
        cout << *this; // Use the overloaded operator to display
    }

    // sum up strengths of all the Warriors in the army and return
    int getArmyStrength() const {
        int total_strength = 0;
        for (Warrior* const& curr_ptr : army) {
            total_strength += curr_ptr->getStrength();
        }
        return total_strength;
    }

    // multiply strength of each warrior with the ratio
    void updateArmyStrength(int winner_strength, int loser_strength) {
        for (Warrior*& curr_ptr : army) {
            int updatedStrength =
                curr_ptr->getStrength() * (winner_strength - loser_strength) /
                winner_strength;  
            curr_ptr->setStrength(updatedStrength);
        }
    }

    bool getStatus() const { return alive; }

    // change the status of "alive" and change strength of all Warriors to 0
    void die() {
        alive = false;
        updateArmyStrength(1, 1);
    }

    // attempt to hire a warrior
    bool hire(Warrior& somewarrior) {
        if (somewarrior.getHiredStatus() || !alive) {
            return false;  
        }
        somewarrior.changeHiredStatus();
        army.push_back(&somewarrior);
        return true;
    }

    // attempt to fire a warrior
    bool fire(Warrior& somewarrior) {
        if (!alive) {
            return false;  
        }
        bool fired = false;
        for (size_t i = 0; i < army.size(); i++) {
            if (fired == false) {
                if (army[i] == &somewarrior) {
                    cout << "You don't work for me anymore "
                         << somewarrior.getName() << "! -- " << name << "."
                         << endl;
                    somewarrior.changeHiredStatus();
                    fired = true;
                }
            } else {
                army[i - 1] = army[i];  
                                        
            }
        }
        if (fired) {
            army.pop_back(); 
        }
        return fired;  
    }

    // battle is now a method of Noble, instead of Warrior
    void battle(Noble& enemy) {
        cout << name << " battles " << enemy.name << endl;
        
        if (!alive && !enemy.alive) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        } else if (!alive && enemy.alive) {
            cout << "He's dead, " << enemy.name << endl;
        } else if (alive && !enemy.alive) {
            cout << "He's dead, " << name << endl;
        } else {  
            int self_strength = getArmyStrength();
            int enemy_strength = enemy.getArmyStrength();
            if (self_strength == enemy_strength) {
                die();
                enemy.die();
                cout << "Mutual Annihilation: " << name << " and " << enemy.name
                     << " die at each other's hands" << endl;
            } else if (self_strength > enemy_strength) {
                updateArmyStrength(self_strength, enemy_strength);
                enemy.die();
                cout << name << " defeats " << enemy.name << endl;
            } else {  
                enemy.updateArmyStrength(enemy_strength, self_strength);
                die();
                cout << enemy.name << " defeats " << name << endl;
            }
        }
    }

private:
    
    string name;
    vector<Warrior*> army;
    bool alive;
};

int main() {
    vector<Noble> nobles;
    vector<Warrior> warriors;

    ifstream file("nobleWarriors.txt");
    string line;

    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1; 
    }

    while (getline(file, line)) {
        stringstream iss(line);
        string command;
        iss >> command; 

        
        if (command == "Noble") {
            string name;
            getline(iss, name); 
            
            if (name[0] == ' ') name.erase(0, 1);
            nobles.push_back(Noble(name)); 
        } else if (command == "Warrior") {
            string name;
            int strength;
            iss >> name >> strength;
            warriors.push_back(Warrior(name, strength)); 
        } else if (command == "Hire") {
            string nobleName, warriorName;
            iss >> nobleName >> warriorName;
            for (size_t i = 0; i < nobles.size(); ++i) {
                if (nobles[i].getName() == nobleName) {
                    for (size_t j = 0; j < warriors.size(); ++j) {
                        if (warriors[j].getName() == warriorName) {
                            nobles[i].hire(warriors[j]); 
                            break;
                        }
                    }
                    break;
                }
            }
        } else if (command == "Fire") {
            string nobleName, warriorName;
            iss >> nobleName >> warriorName;
            for (size_t i = 0; i < nobles.size(); ++i) {
                if (nobles[i].getName() == nobleName) {
                    for (size_t j = 0; j < warriors.size(); ++j) {
                        if (warriors[j].getName() == warriorName) {
                            nobles[i].fire(warriors[j]); 
                            break;
                        }
                    }
                    break;
                }
            }
        } else if (command == "Battle") {
            string nobleName1, nobleName2;
            iss >> nobleName1 >> nobleName2;
            Noble* noble1 = nullptr;
            Noble* noble2 = nullptr;
            for (size_t i = 0; i < nobles.size(); ++i) {
                if (nobles[i].getName() == nobleName1) {
                    noble1 = &nobles[i];
                }
                if (nobles[i].getName() == nobleName2) {
                    noble2 = &nobles[i];
                }
            }
            if (noble1 && noble2) {
                noble1->battle(*noble2); 
            }
        } else if (command == "Status") {
            for (size_t i = 0; i < nobles.size(); ++i) {
                nobles[i].display(); 
            }
        }
    }

    file.close(); 
    return 0;
}

// operator overload for Warrior
ostream& operator<<(ostream& os, const Warrior& somewarrior) {
    os << "  " << somewarrior.name << ": " << somewarrior.strength;
    return os;
}

// operator overload for Noble
ostream& operator<<(ostream& os, const Noble& somenoble) {
    os << somenoble.name << " has an army of " << somenoble.army.size() << endl;
    for (Warrior* curr_warriorp : somenoble.army) {
        if (curr_warriorp) {
            os << *curr_warriorp << endl;
        }
    }
    return os;
}
