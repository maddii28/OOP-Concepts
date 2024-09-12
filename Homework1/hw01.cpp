/*
NAME: MADDHAV SUNEJA
PURPOSE: THE PROGRAM DECRYPTS A CAESER CIPHER ENCRYPTED FILE USING C++ BASICS.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


char decypher(char& encrypted_letter, int rotate_value);

void line_decypher(string& encrypt_sentence, int rotate_value);

//main function includes the whole functional code.
int main() {

    //Defining the various elements i.e vectors and variables
    vector<string> lines;
    int rotation;
    string current_line;
    string gobble;
    ifstream ifs;

    //opening the encrypted file using defined variable ifs
    ifs.open("encrypted.txt");

    //checking if file opened correctly
    if (!ifs) {
        cout << "Can't open the file";
        exit(1);
    }

    //storing the rotation value from the first line in an int variable
    ifs >> rotation;

    //gobbling up the newline character before reading the encrypted txt
    getline(ifs,gobble);

    //Filling up the encrypted text in the vector using push_back method.
    while (getline(ifs, current_line)) {
        lines.push_back(current_line);
    }

    //Closing the encrypted file after reading
    ifs.close();

    //Looping over the vector- decrypting and printing it.
    for (int row = lines.size()-1; row >= 0; --row) {
        line_decypher(lines[row], rotation);
        cout << lines[row] << endl;
    }
 }
   
//decyph function decrypts the character using the rotation value.
char decypher(char& encrypted_letter, const int rotate_value) {

    //makes sure only uppercase are decrypted
    if ('A' <= encrypted_letter && encrypted_letter <= 'Z') {  
        encrypted_letter -= rotate_value;

        //the following condition considers the upper and lower bounds
        if ('A' > encrypted_letter) {
            encrypted_letter += 26;
        }
        if (encrypted_letter > 'Z') {
            encrypted_letter -= 26;
        }
    }
    return encrypted_letter;
}

//str_decypher function decrypts a whole string using the decypher function.
void line_decypher(string& encrypted_sentence, const int rotate_value) {
    for (char& traverse: encrypted_sentence) {
        decypher(traverse, rotate_value);
    }
}


