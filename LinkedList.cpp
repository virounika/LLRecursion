//  LinkedList.cpp

#include "LinkedList.h"
#include <iostream>
using namespace std;


// default constructor
LinkedList::LinkedList() {
    head = nullptr;
}

 // copy constructor
// copies to a new linked list
LinkedList::LinkedList(const LinkedList& rhs) { // rhs is the one being copied
    head = nullptr;
    Node *currentRhs = rhs.head;
    Node *previousNew = nullptr; //nothing has been created in new LinkedList yet
    
    while (currentRhs != nullptr) {                   // loop will stop when Rhs becomes nullptr
        Node *newNode;                               // create ptr called newNode
        newNode = new Node;
        newNode->value = currentRhs->value;          // value of Rhs is copied to NewNode
        newNode->next = nullptr;                    // initialize it before assigning later
        
        if (previousNew == nullptr) { // creating the first node; only iterated once
            head = newNode;            // head points to the node
        }
        else {
            previousNew->next = newNode; // linking prev node to the newly created node
        }
            previousNew = newNode;          // previous points to same node as new
            currentRhs = currentRhs->next; // updating value of Rhs to be copied to new LL item
    }
}

 // Destroys all the dynamically allocated memory
 // in the list.
LinkedList::~LinkedList() {
    while (head != nullptr) { // head points to the first node initially
        Node* current = head; // current points to the node that head points to
        head = head->next;    // head moves to the next node
        delete current;       // deletes node previously head
    }
}

 // assignment operator
const LinkedList& LinkedList::operator=(const LinkedList& rhs) {
    if (this != &rhs) {
        LinkedList tempList(rhs);
        swap(tempList);
    }
    return *this;
}

 // Inserts val at the front of the list
void LinkedList::insertToFront(const ItemType &val) {
    Node *newNode;
    newNode = new Node;
    newNode->value = val;
    newNode->next = head; // link new node to old top node (head has address of old top node)
    head = newNode;       // link head ptr to new top node
}

 // Prints the LinkedList
void LinkedList::printList() const {
    Node *current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

 // Sets item to the value at position i in this
 // LinkedList and return true, returns false if
 // there is no element i
bool LinkedList::get(int i, ItemType& item) const {
    if (i < 0)
        return false;
    
    Node* current;
    current = head;
    int counter = 0;
    while (current != nullptr && counter < i) {
        current = current->next;    // advancing current until reaches i
        counter++;
    }
    
    if (current == nullptr)
        return false;
    else {
    item = current->value; // setting item to value at position i
    return true;
    }
}

 // Reverses the LinkedList
void LinkedList::reverseList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
    
 // Prints the LinkedList in reverse order
void LinkedList::printReverse() const {
    int listSize = size();
    for (int i = listSize - 1; i >= 0; i--) {
        string value;
        if (get(i, value) == true) {
            cout << value << " ";
        }
    }
    cout << endl;
}

 // Appends the values of other onto the end of this
 // LinkedList.
void LinkedList::append(const LinkedList &other) {
    Node* currentOther;
    currentOther = other.head;
    
    if (currentOther == nullptr) {  // if other list empty
        return;
    }
    
    Node* current;                      // points to node
    current = head;
    while (current->next != nullptr) {  // traverse to end of original List
        current = current->next;
    }
    
    while (currentOther != nullptr) {
        Node* newNode;
        newNode = new Node;
        newNode->value = currentOther->value; // making a copy of other before appending
        newNode->next = nullptr;
        
        current->next = newNode;        // last node of original list holds ptr to appended node
        current = newNode;
        currentOther = currentOther->next;    // advance to next node for appending
    }
}

 // Exchange the contents of this LinkedList with the other one.
void LinkedList::swap(LinkedList& other) {
    Node* tempHead = head;  // tempHead stores original list's head
    head = other.head;      // og head is now other's head
    other.head = tempHead;  // other head is now og's head
}

 // Returns the number of items in the Linked List.
int LinkedList::size() const {
    int counter = 0;
    Node *current = head;
    while (current != nullptr) {
        counter++;
        current = current->next;
    }
    return counter;
}
