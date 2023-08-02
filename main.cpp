//  main.cpp
#include "LinkedList.h"
#include <iostream>
#include <cassert>

int main(){
    // testing insertToFront, get
    LinkedList ls;
    ls.insertToFront("Hawkeye");
    ls.insertToFront("Thor");
    ls.insertToFront("Hulk");
    ls.insertToFront("Black Widow");
    ls.insertToFront("Iron Man");
    ls.insertToFront("Captain America");
    for (int k = 0; k < ls.size(); k++)
    {
    std::string x;
     ls.get(k, x);
     std::cout << x << std::endl;
    }
    
    // testing printList, printReverse
    LinkedList ls2;
    ls2.insertToFront("The Mandalorian");
    ls2.insertToFront("Baby Yoda");
    ls2.insertToFront("Cara Dune");
    ls2.insertToFront("Greef Karga");
    ls2.printList();
    ls2.printReverse();
    
    // testing append, get
    LinkedList e1;
    e1.insertToFront("Athos");
    e1.insertToFront("Porthos");
    e1.insertToFront("Aramis");
    LinkedList e2;
    e2.insertToFront("Robin");
    e2.insertToFront("Batman");
    e1.append(e2); // adds contents of e2 to the end of e1
    std::string s;
    assert(e1.size() == 5 && e1.get(3, s) && s == "Batman");
    assert(e2.size() == 2 && e2.get(1, s) && s == "Robin");
    
    // testing reverseList
    LinkedList e11;
    e11.insertToFront("Jim");
    e11.insertToFront("Oz");
    e11.insertToFront("Paul");
    e11.insertToFront("Kevin");
    e11.reverseList(); // reverses the contents of e1
    std::string t;
    assert(e11.size() == 4 && e11.get(0, t) && t == "Jim");
    
    // testing swap
    LinkedList e12;
    e12.insertToFront("A");
    e12.insertToFront("B");
    e12.insertToFront("C");
    e12.insertToFront("D");
    LinkedList e21;
    e21.insertToFront("X");
    e21.insertToFront("Y");
    e21.insertToFront("Z");
    e12.swap(e21); // exchange contents of e1 and e2
    std::string u;
    assert(e12.size() == 3 && e12.get(0, u) && u == "Z");
    assert(e21.size() == 4 && e21.get(2, u) && u == "B");
    e12.printList();
    e21.printList();
   
}
