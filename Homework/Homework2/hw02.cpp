/* 
Name - Maddhav Suneja
Purpose - A batte warrior text game using strut, functions and vectors
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct warrior {
    string name;
    int strength;
};

//Function prototype
void read_file(ifstream& battle);
void status_mode(const vector<warrior>& army);
void warrior_mode(ifstream& ifs, vector<warrior>& army);
void battle_mode(ifstream& ifs, vector<warrior>& army);
void deploy_file(ifstream& ifs, vector<warrior>& army);

//reads the file 
void read_file(ifstream& battle) {
    string filename;
    do {
        cout << "Input filename: ";
        cin >> filename;
        battle.open(filename);
        if (!battle) {
            cout << "Can't open the file, try again." << endl;
        }
    } while (!battle);
}

//prints out the status mode 
void status_mode(const vector<warrior>& army) {
    cout << "There are: " << army.size() << " warriors" << endl;
    for (const auto& commando : army) {
        cout << "Warrior: " << commando.name << ", strength: " << commando.strength << endl;
    }
}

//gives the entry of the warriors
void warrior_mode(ifstream& ifs, vector<warrior>& army) {
    string name;
    int power;
    ifs >> name >> power;
    warrior WR;
    WR.name = name;
    WR.strength = power;
    army.push_back(WR);
}

//battles between warriors and deducts points
void battle_mode(ifstream& ifs, vector<warrior>& army) {
    string player1, player2;
    ifs >> player1 >> player2;
    
    int strength_1;
    int strength_2;

    // Find the warriors in the army
    for (size_t row = 0; row < army.size(); ++row) {
        if (army[row].name == player1) {
            strength_1 = row;
        }
        if (army[row].name == player2) {
            strength_2 = row;
        }
    }

    cout << player1 << " Battles " << player2 << endl;

    if (army[strength_1].strength > army[strength_2].strength) {
        army[strength_1].strength -= army[strength_2].strength;
        army[strength_2].strength = 0;
        cout << player1 << " wins!" << endl;
    } else if (army[strength_1].strength < army[strength_2].strength) {
        army[strength_2].strength -= army[strength_1].strength;
        army[strength_1].strength = 0;
        cout << player2 << " wins!" << endl;
    } else {
        army[strength_1].strength = 0;
        army[strength_2].strength = 0;
        cout << "Both warriors are dead!" << endl;
    }
}

//deploys all the modes
void deploy_file(ifstream& ifs, vector<warrior>& army) {
    string command;
    while (ifs >> command) {
        if (command == "Warrior") {
            warrior_mode(ifs, army);
        } else if (command == "Status") {
            status_mode(army);
        } else if (command == "Battle") {
            battle_mode(ifs, army);
        }
    }
}

//the main code file 
int main() {
    ifstream ifs;
    read_file(ifs);
    vector<warrior> army;
    deploy_file(ifs, army);
    ifs.close(); 
    return 0;
}