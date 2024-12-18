/*
  hw04_start.cpp
  Association: Noble - Warrior
  Test code for hw04
 */
/*
Notes - 
two classes - warrior and noble 

warrior - constructor that takes in the 
warrior name and warrior strength
methods - 
hire_status() - to check whether if the warrior is already hired or not
fire_status() - to check whether if the warrior is hired or not by the noble

Noble army is a vector of pointers to the warrior created 
noble - constructor, battle method, hire method, fire method
what does hire method do - 


*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Your Noble and Warrior classes should go here.
// ...

class Warrior {
     public:
         Warrior(const string& name, int strength) : 
         warrior_name(name), warrior_strength(strength){}

         bool Hire_status(){return stat;}
         bool Fire_status(){return !stat;}
         void change_status(){stat=!stat;}
         const string& getName()const{return warrior_name;}
         const int& getStrength()const{return warrior_strength;}
         void setStrength(const int& strength) {warrior_strength = strength;}
         
     private:
         string warrior_name;
         int warrior_strength;
         bool stat = true;
};

class Noble {
     public:
       Noble(const string& name) : noble_name(name), army(){}
       
       bool hire(Warrior& new_warrior){
          if new_warrior.hire_status(){
               army.push_back(&new_warrior);
               new_warrior.changed_status()
          }
          else {
               return false;
          }
       }
       bool fire(Warrior& new_warrior){
          if new_warrior.fire_status(){
               for (size_t row = 0; row < army.size(); row++){
                    if army[row]-> getName == new_warrior.getName(){
                         for (size_t j = row; j <army.size()- 1; ++j){
                              army[j] = army[j+1]
                         }
                         army.pop_back();
                         
                         }
                    }
               }
               new_warrior.changed_status()
          }
          else {
               return false;
          }
       }
       void battle(){

       }

     private:
        string noble_name;
        vector <Warrior*> army;

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
