#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

char decyph(char& encryp_char, int rotat_dist) {
    if ('A' <= encryp_char && encryp_char <= 'Z') {
        encryp_char-=rotat_dist;
        if ('A' > encryp_char) {
            encryp_char+= 26;
        }
        if (encryp_char > 'Z') {
            encryp_char-=26;
        }
    }
    return encryp_char;
}

void str_decyph(string& encrypt_str, int rotat_dist) {
    for (char& x: encrypt_str) {
        decyph(x, rotat_dist);
    }
}

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
    
