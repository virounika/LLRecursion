//  LinkedList.h

#ifndef LinkedList_h
#define LinkedList_h
#include <string>

typedef std::string ItemType;

// a Node has a value and a pointer to another node
struct Node {
    ItemType value;
    Node *next;
};

class LinkedList {
public:
 LinkedList();
 LinkedList(const LinkedList& rhs);
 ~LinkedList();
 const LinkedList& operator=(const LinkedList& rhs);
 void insertToFront(const ItemType &val);
 void printList() const;
 bool get(int i, ItemType& item) const;
 void reverseList();
 void printReverse() const;
 void append(const LinkedList &other);
 void swap(LinkedList &other);
 int size() const;

private:
    Node *head; // pointer of type Node; can only point to nodes (initial one)
};

#endif /* LinkedList_hpp */
