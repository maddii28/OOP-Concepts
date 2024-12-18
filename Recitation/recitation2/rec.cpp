/*
NAME: MADDHAV SUNEJA
*/


/* A file with names and hydrocarbon formula
Function 1 - Opening a file with standard practice
Function 2 - Fill the vector from stream
Function 3 - Displaying the above vector */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

struct hydrocarbons {
        int carbon_atm;
        int hydrogen_atm;
        vector <string> chem_name;
    };


void read_file(ifstream& stream_obj) {
    do {
        string filename;

        cout << "Enter the file name:";
        cin >> filename;

        stream_obj.open(filename);

        if(!stream_obj) {
            cout << "Can't open the file, try again." << endl;
        }

    } while (!stream_obj);
}

void name_hydro(hydrocarbons& hydro, const string& name) {
    hydro.chem_name.push_back(name);
}

void print_hydro(const hydrocarbons& ahydro) {
    cout << "C" << ahydro.carbon_atm << "H" << ahydro.hydrogen_atm << " " << ahydro.chem_name[0]<< endl;
}

void display_hydro(const vector<hydrocarbons>& HC) {
    for (const hydrocarbons& hydro : HC) {
        print_hydro(hydro);
    }
}

void fill_vector(vector<hydrocarbons>& naming, ifstream& ifs) {
    hydrocarbons hydro;
    string chem_name;
    char gobble;
    while (ifs >> chem_name >> gobblek >> hydro.carbon_atm >> gobble >> hydro.hydrogen_atm ) {
        hydro.chem_name.push_back(chem_name);
        naming.push_back(hydro);
    }
    
}

void insertion(string chem_name, int carbon_atm, int hydrogen_atm ) {
    for (size_t index = 0; index < naming.size(); ++index) {
        if naming[index].carbon_atm == carbon_atm && naming[index].hydrogen_atm == hydrogen_atm{
            return index
            hydro.chem_name.push_back(chem_name)
        }
        else {
            hydro.chem_name.push_back(chem_name);
            naming.push_back(hydro);
    }

        }
    }





int main() {

    ifstream ifs;
    vector<hydrocarbons> naming;

    read_file(ifs);
    fill_vector(naming, ifs);

    for (size_t index = 0; index < naming.size(); ++index) {
        print_hydro(naming[index]);
        }

}