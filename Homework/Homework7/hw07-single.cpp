/*
 File Name:hw07-single.cpp
 Name: Maddhav Suneja
 Purpose: Using cyclic association to simulate noble-warrior battle
 */


#include <iostream>
#include <vector>
#include <string>
using namespace std;


//forward declaration
class Noble;

// warrior class is handling warrior name, strength and hire/fire status
class Warrior {

friend ostream& operator<<(ostream& os, const Warrior& somewarrior);

public:
    Warrior(const string& name, double strength);

    const string& getName() const;
    double getStrength() const;
    void setStrength(double strength);
    void setNoble(Noble* nobleptr);
    bool isHired() const;
    bool runaway();

private:
    string warrior_name;
    double warrior_strength;
    Noble* nob_lord;
};

//Noble manages an army of warrior as well as details of the noble itself
class Noble {

  friend ostream& operator<<(ostream& os, const Noble& somenoble);

public:

    Noble(const string& name);
    const string& getName() const;
    bool removeWarrior(Warrior& new_warrior);
    bool hire(Warrior& new_warrior);
    bool fire(Warrior& new_warrior);
    void battle(Noble& enemy);
    double getArmyStrength() const;
    void updateArmyStrength(double winner_strength, double loser_strength);
    void die();

private:
    string noble_name;
    vector<Warrior*> army;
    bool alive;
};


int main() {
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");

    Warrior cheetah("Tarzan", 4);
    Warrior sky("Leia", 6);
    Warrior wizard("Merlin", 9);
    Warrior jaffa("Teal'c", 9);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);

    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(jaffa);
    art.hire(cheetah);
    art.hire(wizard);
    art.hire(sky);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(nimoy);

    cout << "================ Initial Status ===============" << endl;
    cout << art << endl
	 << lance << endl
	 << jim << endl
	 << linus << endl
	 << billie << endl;
    cout << "===============================================\n\n";

    art.fire(cheetah);
    wizard.runaway(); 
    cout << endl << art << endl;

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);

    cout << "\n================ Final Status ===============" << endl;
    cout << art << endl
	 << lance << endl
	 << jim << endl
	 << linus << endl
	 << billie << endl;

    //Tarzan and Merlin should be unemployed
    cout << "Tarzan's Hire Status: " << boolalpha 
	 << cheetah.isHired() << endl;
    cout << "Merlin's Hire Status: " << boolalpha 
	 << wizard.isHired() << endl;
    cout << "===============================================\n\n";
}


//Warrior class definitions

//Warrior Constructor
Warrior::Warrior(const string& name, double strength)
: warrior_name(name), warrior_strength(strength), nob_lord(nullptr) {}

const string& Warrior::getName() const { return warrior_name; }
double Warrior::getStrength() const { return warrior_strength; }
void Warrior::setStrength(double strength) { warrior_strength = strength;}
void Warrior::setNoble(Noble* nobleptr){nob_lord = nobleptr;}
bool Warrior::isHired() const {
    if (nob_lord == nullptr){
        return false;
    }
    else {return true;}
}

//utilises cyclic association to let the warrior runaway
bool Warrior::runaway(){
    if (warrior_strength == 0 && !nob_lord) {  
        cout << "Runaway failed for" << warrior_name << endl;
        return false;
    }

    if (nob_lord->removeWarrior(*this)) {
        cout << warrior_name << " flees in terror, abandoning his lord, "
        << nob_lord->getName()<< endl;
        setNoble(nullptr);
        return true;
    }
    return false;
}

//helps in displaying details about the warrior 
ostream& operator<<(ostream& os, const Warrior& somewarrior) {
     os << "   " << somewarrior.warrior_name << ": " << somewarrior.warrior_strength;
     return os;
}


//Noble class definitions

//Noble Constructor
Noble::Noble(const string& name) : noble_name(name), alive(true) {}

const string& Noble::getName() const {return noble_name;}

//remove the warrior from the army
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

//hires the warrior after checking the noble pointer
bool Noble::hire(Warrior& new_warrior) {
    if (!(new_warrior.isHired()) && alive) {
        army.push_back(&new_warrior);
        new_warrior.setNoble(this);
        return true;
    }
    cout << noble_name << " failed to hire " << new_warrior.getName() << endl;
    return false;
}
    
//hires the warrior after checking the noble pointer
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

//battle logic btw nobles and their armies
void Noble::battle(Noble& enemy) {
    cout << noble_name << " battles " << enemy.noble_name << endl;

    if (!alive && !enemy.alive) {
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
    } 
    else if (!alive) {
        cout << "He's dead, " << enemy.noble_name << endl;
    } 
    else if (!enemy.alive) {
        cout << "He's dead, " << noble_name << endl;
    } 
    else {
        double self_strength = getArmyStrength();
        double enemy_strength = enemy.getArmyStrength();
        if (self_strength == enemy_strength) {
            die();
            enemy.die();
            cout << "Mutual Annihilation: " << noble_name << " and " << enemy.noble_name
            << " die at each other's hands" << endl;
        } 
        else if (self_strength > enemy_strength) {
            updateArmyStrength(self_strength, enemy_strength);
            enemy.die();
            cout << noble_name << " defeats " << enemy.noble_name << endl;
        } 
        else {
            enemy.updateArmyStrength(enemy_strength, self_strength);
            die();
            cout << enemy.noble_name << " defeats " << noble_name << endl;
        }
    }
}

//returns the total army strength of a noble
double Noble::getArmyStrength() const {
    double total_strength = 0;
    for (const Warrior* warrior : army) {
        total_strength += warrior->getStrength();
    }
    return total_strength;
}
 
//sets the army strength after a battle takes place
void Noble::updateArmyStrength(double winner_strength, double loser_strength) {
    double ratio = (winner_strength - loser_strength) / winner_strength;
    for (Warrior* warrior : army) {
        warrior->setStrength(warrior->getStrength() * ratio);
    }
}

//setter in case of die situation in battle
void Noble::die() {
    alive = false;
    for (Warrior* warrior : army) {
        warrior->setStrength(0);
    }
}

//helps in displaying details about the noble n its army
ostream& operator<<(ostream& os, const Noble& somenoble) {
     os << somenoble.noble_name << " has an army of " 
     << somenoble.army.size() << endl; 

     for (const Warrior* warrior : somenoble.army) {
          os << *warrior << endl;
     }
     return os;
}
