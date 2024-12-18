/*
Name: Maddhav Suneja
FileName: "hw03.cpp"
Purpose: Using class n its methods to make warriors battle using weapons
*/ 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


//class Weapon is nested inside class Warrior
//the nested classes handle the warrior name, weapon name and its strength
class Warrior {
    friend ostream& operator<<(ostream& os, const Warrior& display);

    class Weapon {
        friend ostream& operator<<(ostream& os, const Warrior::Weapon& display);
        private:
            string weapon_name;
            int power;
        public:
            //the constructor for the weapon class
            Weapon(const string& weapon, int strength) 
            : weapon_name(weapon), power(strength) {}

            //gets the power
            const int& getPower() const{
                return power;
            }

            //reduces the weapons's power in a battle
            void setPower( int opponent_power){
                power = power - opponent_power;
            }

            //sets the weapon power to zero
            void setZero()  {
                power = 0;
            }
       };

    friend ostream& operator<<(ostream& os, const Warrior::Weapon& display); 

    public:
      //the constructor for the warrior class
      Warrior(const string& name, const string& weapon, int strength) 
      : solider_name(name), arms(weapon, strength) {}

      //gets the warrior name
      const string& getName() const {
          return solider_name;
      }

      //gets the weapon 
      Weapon& getWeapon()  {
          return arms;
      }

    private:
       string solider_name;
       Weapon arms;

};

//class battle handles the battle logic between two warriors 
class Battle {

    public:
       /*the method fight reduces the weapon power of warriors 
       during battle using getters n setters */
       void fight(const string& fighter1, const string& fighter2, 
       vector<Warrior>& warriors_data) {

          int warrior1 = -1;
          int warrior2 = -1;

          for (size_t row = 0; row < warriors_data.size(); ++row) {

             if (warriors_data[row].getName() == fighter1){
                 warrior1 = row;
             }
             if (warriors_data[row].getName() == fighter2){
                 warrior2 = row;
             }
          }

          if (warrior1 == -1 || warrior2 == -1){
            cout << "Either one or both warriors are not present";
            return;
          }

          cout << warriors_data[warrior1].getName() << " battles " 
          << warriors_data[warrior2].getName() << endl;
          
          if (warriors_data[warrior1].getWeapon().getPower() == 0){

              if (warriors_data[warrior2].getWeapon().getPower() == 0){
                cout << "Yuck, they are both dead" << endl;
              }
              else {
                cout << warriors_data[warrior1].getName() << " is dead" 
                << endl;
              }  
          }

          else if (warriors_data[warrior2].getWeapon().getPower() == 0){

              if (warriors_data[warrior1].getWeapon().getPower() == 0){
                cout << "Yuck, they are both dead" << endl;
              }
              else {
                cout << "He's dead, " << warriors_data[warrior1].getName() 
                << endl;
              }  
          }

          else if (warriors_data[warrior1].getWeapon().getPower() 
          > warriors_data[warrior2].getWeapon().getPower()) {

            warriors_data[warrior1].getWeapon().
            setPower(warriors_data[warrior2].getWeapon().getPower());

            warriors_data[warrior2].getWeapon().setZero();

            cout << warriors_data[warrior1].getName() << " defeats " 
            << warriors_data[warrior2].getName() << endl;

          }

          else if (warriors_data[warrior2].getWeapon().getPower() 
          > warriors_data[warrior1].getWeapon().getPower()) {

            warriors_data[warrior2].getWeapon().
            setPower(warriors_data[warrior1].getWeapon().getPower());

            warriors_data[warrior1].getWeapon().setZero();

            cout << warriors_data[warrior2].getName() << " defeats " 
            << warriors_data[warrior1].getName() << endl;
          }

          else if (warriors_data[warrior2].getWeapon().getPower() 
          == warriors_data[warrior1].getWeapon().getPower()) {

            warriors_data[warrior1].getWeapon().setZero();
            warriors_data[warrior2].getWeapon().setZero();

            cout << "Mutual Annihilation: " << warriors_data[warrior1].getName() 
            << " and " << warriors_data[warrior2].getName() 
            << " die at each other's" << endl;
          }

       }

};

// status class uses output operator to display warriors, weapons n their strength
class Status {
public:

    //loops through the vector and displays all warrior details
    void displayWarriors(const vector<Warrior>& warriors) {
        cout << "There are: " << warriors.size() << " warriors" << endl;
        for (const Warrior& warrior : warriors) {
            cout << warrior << endl;  
        }
    }
};

//Function Prototypes
void open_file(ifstream& ifs);
void warrior_status(ifstream& ifs, vector<Warrior>& fighter_data);
void battle_status(ifstream& ifs, vector<Warrior>& fighter_data);
void initiate_status(const vector<Warrior>& fighter_data);


//main() stores all the function calls and runnable code
int main()
{
ifstream ifs;
string status;
vector<Warrior> fighter_data;

open_file(ifs);

while (ifs >> status){
    if (status == "Warrior"){
        warrior_status(ifs, fighter_data);
    }
    else if (status == "Battle"){
        battle_status(ifs, fighter_data);
    }
    else if (status == "Status"){
        initiate_status(fighter_data);
    }
} 
    ifs.close();
    return 0;
}

//helps in displaying weapon name n strength 
ostream& operator<<(ostream& os, const Warrior::Weapon& display) {
    os << ", weapon: " << display.weapon_name << ", " << display.power;
    return os;
}

//helps in displaying the warrior name n arms(i.e weapon name n strength)
ostream& operator<<(ostream& os, const Warrior& display){
    os << "Warrior: " << display.solider_name << display.arms;
    return os;
}

//opens the file n gives error if it doesn't open
void open_file(ifstream& ifs) {
    ifs.open("warriors.txt");
    if (!ifs.is_open()) {
        cout << "Error: Could not open file 'warriors.txt'" << endl;
    }
}

//error checks for duplicates n then enters the details of warrior 
void warrior_status(ifstream& ifs, vector<Warrior>& fighter_data){
    string name;
    string weapon_name;
    int weapon_strength;
    ifs >> name >> weapon_name >> weapon_strength;

    bool error_check = false;

    for (size_t row = 0; row < fighter_data.size(); ++row){
        if (fighter_data[row].getName() == name) {
            error_check = true;
            break;
        }
    }
    if (error_check == false){
        Warrior fighter(name, weapon_name, weapon_strength);
        fighter_data.push_back(fighter);
    }
    else if (error_check == true) {
        cout << "Warrior name is repeated";
    }

}

//initiates the battle between two warriors
void battle_status(ifstream& ifs, vector<Warrior>& fighter_data){
    string name;
    string name2;
    ifs >> name >> name2;
    Battle battle;
    battle.fight(name, name2, fighter_data);
}

//displays the warriors n weapon data
void initiate_status(const vector<Warrior>& fighter_data){
    Status status;
    status.displayWarriors(fighter_data);
}