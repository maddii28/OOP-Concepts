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


//Q3
void removeValue(Node*& head, int target){
    Node* dec = head;
    while (dec!= nullptr){
        if (dec->data == target){
            Node* old_head = dec;
            dec = dec -> next;
            delete old_head;
        }
        else{
            dec = dec -> next;
        }
    }
}
/*
wrong logic since dec is pointing at the head and when we delete old_head, we delete the head node so head pointer 
hasn't changed only dec has which means head pointer is still pointing at the deleted node
*/

//corrected logic
void removeValue(Node*& head, int target) {
    Node* dec = head;
    Node* prev = nullptr;
    while (dec != nullptr) {
        if (dec->data == target) {
            if (prev == nullptr) {
                // If the node to delete is the head, update the head pointer
                head = dec->next;
            } else {
                // Otherwise, update the previous node's next pointer
                prev->next = dec->next;
            }
            Node* old_head = dec; // Store the node to be deleted
            dec = dec->next;      // Move to the next node
            delete old_head;      // Delete the node
        } else {
            prev = dec;           // Update previous node to current
            dec = dec->next;      // Move to the next node
        }
    }
}


//Q4
bool removeLastValue(Node*& head, int target) {
    if (head == nullptr) {
        return false; // If the list is empty, nothing to remove
    }

    Node* lastOccurrence = nullptr; // Pointer to track the last occurrence of target
    Node* lastOccurrencePrev = nullptr; // Pointer to track the node before lastOccurrence
    Node* current = head; 
    Node* prev = nullptr;

    // Traverse the list
    while (current != nullptr) {
        if (current->data == target) {
            lastOccurrence = current; // Update the last occurrence
            lastOccurrencePrev = prev; // Update the node before it
        }
        prev = current;
        current = current->next;
    }

    // If no target value was found, return false
    if (lastOccurrence == nullptr) {
        return false;
    }

    // Remove the last occurrence
    if (lastOccurrencePrev == nullptr) {
        // If the last occurrence is the head
        head = lastOccurrence->next;
    } else {
        // Skip the lastOccurrence node
        lastOccurrencePrev->next = lastOccurrence->next;
    }

    delete lastOccurrence; // Free memory
    return true;
}

