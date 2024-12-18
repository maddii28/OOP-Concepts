/* rec02.cpp fall 2024
 Maddhav Suneja */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility> 

using namespace std;

struct hydrocarbons {
    int carbons_atm;
    int hydro_atm;
    vector<string> chem_name;
};

void read_file(ifstream& hydro_ifs);

void vector_insert(ifstream& hydroifs, vector<hydrocarbons>& hydrocarbs);

void display_hydro(const hydrocarbons& hydro);

void name_hydro(hydrocarbons& hc, const string& name);

void print(const vector<hydrocarbons>& hydrocarb) ;

size_t find_hydro(int hydro, int carbo, const vector<hydrocarbons>& hydrocarbons);

void hydrosort(vector<hydrocarbons>& hydrocarbons) ;


// Main function
int main() {
    ifstream ifs;
    read_file(ifs);

    vector<hydrocarbons> hydrocarbons;
    vector_insert(ifs, hydrocarbons);

    ifs.close();

    cout << "Unsorted hydrocarbons:" << endl;
    print(hydrocarbons);

    hydrosort(hydrocarbons);

    cout << endl << "Sorted hydrocarbons:" << endl;
    print(hydrocarbons);

    return 0;
}

// Function to add a name to a hydrocarbon
void name_hydro(hydrocarbons& hc, const string& name) {

    hc.chem_name.push_back(name);
}

// Function to print a hydrocarbon
void display_hydro(const hydrocarbons& hydro) {

    cout << "C" << hydro.carbons_atm << "H" << hydro.hydro_atm;

    for (const string& name : hydro.chem_name) {

        cout << " " << name;
    }
    cout << endl;
}

// Open the file
void read_file(ifstream& hydro_ifs) {
    string filename;
    do {
        cout << "Input filename: ";

        cin >> filename;

        hydro_ifs.open(filename);

        if(!hydro_ifs) {
            cout << "Can't open the file, try again." << endl;
        }
    } while (!hydro_ifs);
}

// print the hydrocarbons
void print(const vector<hydrocarbons>& hydrocarb) {

    for (const hydrocarbons& hydrocarbon : hydrocarb) {

        display_hydro(hydrocarbon);
    }
}

// Find the index of a hydrocarbon 
size_t find_hydro(int hydro, int carbo, const vector<hydrocarbons>& hydrocarbons) {
    for (size_t row = 0; row < hydrocarbons.size(); ++row) {

        if (hydrocarbons[row].carbons_atm == carbo && hydrocarbons[row].hydro_atm == hydro) {
            return row;
        }
    }
    return hydrocarbons.size();
}

// Fill the vector 
void vector_insert(ifstream& hydroifs, vector<hydrocarbons>& hydrocarbs) {
    char gobble;
    int hydrogen;
    int carbon;
    string name;

    while (hydroifs >> name >> gobble >> carbon >> gobble >> hydrogen) {
        size_t index = find_hydro(hydrogen, carbon, hydrocarbs);

        if (index == hydrocarbs.size()) {
            hydrocarbons HC;
            HC.carbons_atm = carbon;
            HC.hydro_atm = hydrogen;
            HC.chem_name.push_back(name);
            hydrocarbs.push_back(HC);
        } else {

            hydrocarbs[index].chem_name.push_back(name);
        }
    }
}

// Insertion sort
void hydrosort(vector<hydrocarbons>& hydrocarbons) {
    for (size_t i = 1; i < hydrocarbons.size(); i++) {

        for (size_t row = i; row > 0; row--) {

            if (hydrocarbons[row].carbons_atm < hydrocarbons[row - 1].carbons_atm) {
                swap(hydrocarbons[row], hydrocarbons[row - 1]);

            } else if (hydrocarbons[row].carbons_atm == hydrocarbons[row - 1].carbons_atm) {
                if (hydrocarbons[row].hydro_atm < hydrocarbons[row - 1].hydro_atm) {
                    swap(hydrocarbons[row], hydrocarbons[row - 1]);

                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }
}