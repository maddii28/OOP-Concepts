#include <iostream>
using namespace std;

struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

void listDisplay(const Node* headPtr) {
    const Node* cur = headPtr;

    // corner case 

    while (cur != nullptr) {

        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

}
ostream& operator<<(ostream& os, const Node* headPtr) { return os; }
//int listSize(const Node* ptr) {}

void listAddTail(Node*& headPtr, int data) {
    Node* cur = headPtr;
    // corner cases
    if (headPtr == nullptr) {
        headPtr = new Node(data);
        return;
    }

    // general case
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = new Node(data, nullptr);


}
void listAddHead(Node*& headPtr, int data) { 
    // corner cases - none

    // general case
    headPtr = new Node(data, headPtr);
}
void listAdd(Node* at_node, int data) { }

bool listRemoveHead(Node*& headPtr) { 

    // corner cases
    if (!headPtr) return false;


    // general case
    Node* temp = headPtr;
    headPtr = headPtr->next;
    delete temp;
    
    return true; 

}
bool listRemoveTail(Node*& headPtr) { 

    Node* cur = headPtr;
    // corner cases
    if (!headPtr) return false;
    if (!headPtr->next) {
        delete headPtr;
        headPtr = nullptr;
        return true;
    }


    // general case
    while (cur->next->next != nullptr) {
        cur = cur->next;
    }
    delete cur->next;
    cur->next = nullptr;
    return true;
}
bool listRemove(Node* prior) { 

    // corner cases - many bimplementations ignore this.. it's not a list head, it's not passed by ref
    if (!prior) return false;
    if (!prior->next) return false;

    Node* temp = prior->next;
    prior->next = prior->next->next;
    delete temp;

    return true; 

}
void listClear(Node*& headPtr) { }

//Node* listDuplicate(const Node* headPtr) {  }
void listReverse(Node*& headPtr) {
    Node* cur = headPtr;
    Node* next = cur->next;
    Node* prev = nullptr;

    // corner cases
    if (!headPtr) return;
    if (!headPtr->next) return;


    // general case
    while (cur->next) {
        cur->next = prev;

        // traverse
        prev = cur;
        cur = next;
        next = next->next;

    }

    // at this point cur is pointing at final node
    headPtr = cur;
    cur->next = prev;


}


int main() {
	// Instantiate an empty list
    Node* mylist = nullptr;

    // Add three nodes to tail (any values)
    listAddTail(mylist, 27);
    listAddTail(mylist, 22);
    listAddTail(mylist, 33);

    // Display list (using display and operator<< )
    listDisplay(mylist);

    // Add one node to the tail
    listAddHead(mylist, 19);
    listAddHead(mylist, 17);
    listDisplay(mylist);

    // list reverse (do it twice to back to original)
    cout << "Reversing and displaying myList:\n";
    listReverse(mylist);
    listDisplay(mylist);

    // Add a node in the middle (the second node)
    cout << "Removing the second node:" << endl;
    listRemove(mylist);
    listDisplay(mylist);

    // Add a node in the middle - second implementation

    // Delete a node
    cout << "Removing a tail node:" << endl;
    listRemoveTail(mylist);
    listDisplay(mylist);

    cout << "Removing a head node:" << endl;
    listRemoveHead(mylist);
    listDisplay(mylist);

    // Get the node count

    // Remove a tail node 

    // Remove a head node 


    // list reverse - second version
    cerr << "Testing listReverse2\n";

    // print in reverse
    cout << "displaying myList in reverse by reversing, "
        << " printing and reversing again:\n";

    // Duplicate
    cout << "duplicating myList and displaying it:\n";


    // Removing items from list (both versions of remove)
    cout << "Removing second item and displaying myList:\n";


    // Delete all nodes using listRemoveHead


}
