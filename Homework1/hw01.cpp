#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

char decyph(char& encryp_char, int rotat_dist) {
    if ('A' < encryp_char && encryp_char>'Z') {
        encryp_char-=rotat_dist;
    }
    return encryp_char;
}

void str_decyph(string& encrypt_str, int rotat_dist) {
    for (string& x: encrypt_str) {
        decyph(x, rotat_dist);
    }
}

 int main() {
    string code_msg;
    ifstream ifs;
    ifs.open("encrypted.txt");
    while (ifs >> code_msg) {
        str_decyph()
    }

 }