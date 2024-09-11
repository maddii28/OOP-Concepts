// NAME: MADDHAV SUNEJA

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

char decyph(char& encryp_char, int rotat_dist);

void str_decyph(string& encrypt_str, int rotat_dist);

int main() {
    vector<string> vec_line;
    string line;
    ifstream ifs;

    ifs.open("encrypted.txt");

    while (getline(ifs,line)) {
        vec_line.push_back(line);
    }

    int num = stoi(vec_line[0]); 

    for (size_t i = vec_line.size()-1; i > 0; --i) {
        str_decyph(vec_line[i], num);
        cout << vec_line[i] << endl;
    }
 }
   
char decyph(char& encryp_char, int rotat_dist) {
    if ('A' <= encryp_char && encryp_char <= 'Z') {
        encryp_char-=rotat_dist;
        if ('A' > encryp_char) {
            encryp_char+= 26;
        }
        if (encryp_char > 'Z') {
            encryp_char -= 26;
        }
    }
    return encryp_char;
}

void str_decyph(string& encrypt_str, int rotat_dist) {
    for (char& x: encrypt_str) {
        decyph(x, rotat_dist);
    }
}

/* Mistakes I made during the homework
1. Mistake in the for condition for the decypher code - messed up the logical operators
2. Type mismatch btw char and string for function call to decyph 
3. i >= 0 was a wrong condition to loop over the vector backwards idk why??
4. Forgot to consider the domain of the program - for eg. rotating alphabets on the edge - line 35-39 */


