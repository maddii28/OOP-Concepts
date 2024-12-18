/*
  words.cpp
  24F Sec C
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Word {
    string token;
    vector<int> positions;
};

int main() {

    ifstream textStream("jabberwocky");
    if (!textStream) {
	cerr << "failed to open jabberwocky\n";
	exit(1);
    }

    vector<Word> words;

    string token;
    int where = 0;
    while (textStream >> token) {
        // Have we seen the token
        size_t index = findToken(token, words);

        // No?
        if (index == words.size()) {
            //  Create a new word for that token and position
            //  and add that word to the vector;
            Word aWord;
            aWord.token = token;
            aWord.positions.push_back(where);
            words.push_back(aWord);
        }
        // Yes?
        else {
            //   add the position to that word
            words[index].positions.push_back(where);
        }

        ++where;
    }
}
