
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A {
    public:
       A() {cout << "A()\n";}
       ~A() {cout << "~A()\n";}
};

class B : public A {
    public:
       B() {cout << "B()\n";}
       ~B() {cout << "~B()\n";}
};

int main() {
    B b;
    cout << "Finished" << endl;
}


//LINKED LIST PRACTICE QUESTIONS

//Q1
int findNext(Node* head, int target, int largest){
    int x = largest;
    while (head){
        if ((head -> data) > target && x > (head -> data)){
            x = head -> data;
        }
        head = head -> next;
    }
    return x;
}

//Q2
Node* sortList(Node* head, int largest){
    Node* xyz = head;
    if (xyz != nullptr){
        int lowest = xyz -> data;
        xyz = xyz -> next;
    }
    while (xyz){
        if ((xyz -> data) < lowest) {
            lowest = xyz -> data;
        }
        xyz = xyz -> next;
    }
    Node* result = new Node{lowest};
    Node* last = result;
    while (head){
        int ao = findNext(head,lowest,largest);
        last -> next = new Node{ao};
        last = last -> next;
        head = head -> next;
    }
    return result;
}

//Corrected logic 
Node* sortList(Node* head, int largest) {
    // Step 1: Find the smallest element in the list
    Node* temp = head;
    int lowest = temp->data;
    while (temp) {
        if (temp->data < lowest) {
            lowest = temp->data;
        }
        temp = temp->link;
    }

    // Step 2: Create the result list with the smallest element
    Node* result = new Node{lowest}; // Start the new sorted list
    Node* last = result;

    // Step 3: Use findNext to build the sorted list
    int current = lowest;
    while (current != largest) {
        current = findNext(head, current, largest);
        last->link = new Node{current};
        last = last->link;
    }

    // Return the head of the sorted list
    return result;
}
