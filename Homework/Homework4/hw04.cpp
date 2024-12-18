/*
  fileName: hw04.cpp
  Name: Maddhav Suneja
  Program: Noble-Warrior battle simulation
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// warrior class is handling warrior name, strength and hire/fire status
class Warrior {

friend ostream& operator<<(ostream& os, const Warrior& somewarrior);

public:
    Warrior(const string& name, int strength)
    : warrior_name(name), warrior_strength(strength), stat(false) {}

    bool Hire_status() { return !stat; }
    bool Fire_status() { return stat; }
    void change_status() { stat = !stat; }
    const string& getName() const { return warrior_name; }
    int getStrength() const { return warrior_strength; }
    void setStrength(int strength) { warrior_strength = strength; }



private:
    string warrior_name;
    int warrior_strength;
    bool stat;
};

//Noble manages an army of warrior as well as details of the noble itself
class Noble {

  friend ostream& operator<<(ostream& os, const Noble& somenoble);

public:
    Noble(const string& name) : noble_name(name), alive(true) {}
     
    //hires the warrior after checking the hire status
    bool hire(Warrior& new_warrior) {
        if (new_warrior.Hire_status() && alive) {
            army.push_back(&new_warrior);
            new_warrior.change_status();
            return true;
        }
        cout << noble_name << " failed to hire " << new_warrior.getName() << endl;
        return false;
    }

    //fires the warrior after checking the fire status
    bool fire(Warrior& new_warrior) {
        if (new_warrior.Fire_status() && alive) {
            for (size_t i = 0; i < army.size(); ++i) {
                if (army[i]->getName() == new_warrior.getName()) {
                    cout << new_warrior.getName() 
                    << ", You don't work for me anymore " 
                    << " -- " << noble_name << endl;

                    new_warrior.change_status();
                    army[i] = army.back();  
                    army.pop_back();        
                    return true;
                }
            }
        }
        return false;
    }

    //battle logic btw nobles and their armies
    void battle(Noble& enemy) {
        cout << noble_name << " battles " << enemy.noble_name << endl;

        if (!alive && !enemy.alive) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        } else if (!alive) {
            cout << "He's dead, " << enemy.noble_name << endl;
        } else if (!enemy.alive) {
            cout << "He's dead, " << noble_name << endl;
        } else {
            int self_strength = getArmyStrength();
            int enemy_strength = enemy.getArmyStrength();
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
    //returns the total army strength of a noble
    int getArmyStrength() const {
        int total_strength = 0;
        for (const Warrior* warrior : army) {
            total_strength += warrior->getStrength();
        }
        return total_strength;
    }
 
    //sets the army strength after a battle takes place
    void updateArmyStrength(int winner_strength, int loser_strength) {
        double ratio = double(winner_strength - loser_strength) / winner_strength;
        for (Warrior* warrior : army) {
            warrior->setStrength(int(warrior->getStrength() * ratio));
        }
    }

    //setter in case of die situation in battle
    void die() {
        alive = false;
        for (Warrior* warrior : army) {
            warrior->setStrength(0);
        }
    }


private:
    string noble_name;
    vector<Warrior*> army;
    bool alive;

};

int main()
{
	
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");
	
    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);
	
    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);
    art.hire(nimoy);
	
    cout << "==========\n\n"
         << "Status before all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n\n";
	
    art.fire(cheetah);
    cout << art << endl;

    lance.fire(nimoy);
    cout << lance << endl;
    cout << "==========\n\n";

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);

    cout << "==========\n\n"
         << "Status after all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";
	
} // main

//helps in displaying details about the noble n its army
ostream& operator<<(ostream& os, const Noble& somenoble) {
     os << somenoble.noble_name << " has an army of " 
     << somenoble.army.size() << endl; 

     for (const Warrior* warrior : somenoble.army) {
          os << *warrior << endl;
     }
     return os;
    }

//helps in displaying the warrior name n details
ostream& operator<<(ostream& os, const Warrior& somewarrior) {
     os << "   " << somewarrior.warrior_name << ": " << somewarrior.warrior_strength;
     return os;
}