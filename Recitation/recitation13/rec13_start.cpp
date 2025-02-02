/* 
Name: Maddhav Suneja
FileName: rec13_start.cpp
Purpose: To display distinct words in a file along with their single/multiple occurences 
*/

#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

//Utility function to print a vector with index numbers.
template <typename T>
void printVec(const vector<T>& v) {
    size_t index = 0;
    for (const T& elem : v) {
        cout << ++index << ". " << elem << endl;
    }
}

// Utility function to print a set with index numbers
template <typename T>
void printSet(const set<T>& s) {
    size_t index = 0;
    for (const T& elem : s) {
        cout << ++index << ". " << elem << endl;
    }
}

// Utility function to print a map with index numbers and positions
template <typename Key, typename Value>
void printMap(const map<Key, Value>& m) {
    size_t index = 0;
    for (const auto& entry : m) {
        cout << ++index << ". " << entry.first << " - Positions: ";
        for (const auto& pos : entry.second) {
            cout << pos << " ";
        }
        cout << endl;
    }
}

// Utility function to print a list using a range-based for loop
void printListRF(const list<int>& l) {
    for (int elem : l) {
        cout << elem << " ";
    }
    cout << endl;
}

// Utility function to print a list using iterators
void printListIter(const list<int>& l) {
    for (auto iter = l.begin(); iter != l.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

void printlistAuto(const list<int>& l) {
    for (auto iter = l.begin(); iter != l.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

// Function to find a value in a list and return an iterator using a for loop
list<int>::iterator ourFind(list<int>::iterator begin, list<int>::iterator  end, int value) {
    for (auto it = begin; it != end; ++it) {
        if (*it == value) {
            return it;  
        }
    }
    cout << "Value " << value << " not found in the list." << endl;
    return end;  
}

// Function to implement a generic templated find
template <typename Iterator, typename T>
Iterator ourFind(Iterator begin, Iterator end, const T& value) {
    for (Iterator iter = begin; iter != end; ++iter) {
        if (*iter == value) {
            return iter;
        }
    }
    cout << "Value " << value << " not found in the list." << endl;
    return end;
}

// Predicate function to check if a number is even
bool predicate(int n) {
    return (n % 2 == 0);
}

// Functor class for predicate
class Predicate {
public:
    bool operator()(int n) const {
        return (n % 2 == 0);
    }
};

// Function to count distinct words using a vector
void countDistinctWordVec(const string& filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    vector<string> collection;
    string curr_word;
    while (ifs >> curr_word) {
        if (find(collection.begin(), collection.end(), curr_word) == collection.end()) {
            collection.push_back(curr_word);
        }
    }
    cout << "Number of Distinct Words: " << collection.size() << endl;
    printVec(collection);
}

// Function to count distinct words using a set
void countDistinctWordSet(const string& filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    set<string> collection;
    string curr_word;
    while (ifs >> curr_word) {
        collection.insert(curr_word);
    }
    cout << "Number of Distinct Words: " << collection.size() << endl;
    printSet(collection);
}

// Function to count word occurrences using a map
void countDistinctWordMap(const string& filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    map<string, vector<int>> collection;
    string curr_word;
    int position = 0;
    while (ifs >> curr_word) {
        collection[curr_word].push_back(position);
        position++;
        
    }
    cout << "Number of Distinct Words: " << collection.size() << endl;
    printMap(collection);
}
int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> v({1, 4, 6, 3, 2, 5});
    printVec(v);
    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> l(v.begin(), v.end());
    printListRF(l);
    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(v.begin(), v.end());
    printVec(v);
    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for (size_t i = 0; i < v.size(); i += 2) {
        cout << v[i];
    }
    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    // for (size_t i = 0; i < l.size(); i += 2) {
    //     cout << l[i];
    // }
    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter += 2) {
        cout << *iter;
    }
    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    for (list<int>::iterator iter = l.begin(); iter != l.end(); ++++iter) {
        cout << *iter;
    }
    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    l.sort();
    printListRF(l);
    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    printListIter(l);
    cout << "\n=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    printListRF(l);
    cout << "\n=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    printlistAuto(l);
    cout << "\n=======\n";

    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    cout << *findList(l, 3); // 
    cout << "\n=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    cout << *findList(l, 3);
    cout << "\n=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    cout << *find(l.begin(), l.end(), 3);
    cout << "\n=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    cout << *find_if(l.begin(), l.end(), predicate);
    cout << "\n=======\n";

    // 16. Functor
    cout << "Task 16:\n";
    cout << *find_if(l.begin(), l.end(), Predicate());
    cout << "\n=======\n";

    // 17. Lambda
    cout << "Task 17:\n";
    cout << *find_if(l.begin(), l.end(), [](int n) { return (n & 1) == 0; });
    cout << "\n=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int* DA = new int[6];
    copy(l.begin(), l.end(), DA);
    for (size_t i = 0; i < 6; ++i) {
        cout << DA[i];
    }
    delete[] DA;
    cout << "\n=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    cout << *ourFind(l.begin(), l.end(), 3);
    cout << "\n=======\n";

    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    cout << *ourFind(l.begin(), l.end(), 3);
    cout << "\n=======\n";

    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    countDistinctWordVec("pooh-nopunc.txt");
    cout << "=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    countDistinctWordSet("pooh-nopunc.txt");
    cout << "=======\n";

    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    countDistinctWordMap("pooh-nopunc.txt");
    cout << "=======\n";
}