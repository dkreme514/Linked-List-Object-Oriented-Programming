// 
// Author: Donald Kremer
// 
// File description: Driver file for a Linked
//   List for Object Oriented Programming. This project
//   is to understand the workings of the Linked List
//   data structure.
//
#include <iostream>
#include "linklist.h"
#include <string>

using namespace std;
int main() {
    LinkList MyList;
    cout << "Link List Example :)" << endl;
    MyList.Insert(1,"Donnie");
    MyList.List();
    MyList.Insert(2,"Eva");
    MyList.List();
    MyList.Insert(3,"Jodie");
    MyList.List();
    MyList.Insert(4,"John");
    MyList.List();
    MyList.Insert(5,"Max");
    MyList.List();
    MyList.Insert(6,"Anton");
    MyList.List();
    MyList.Insert(7,"Trey");
    LinkList CopyList;
    CopyList = MyList;
    cout << "Seeing if copy list works " << endl;
    ListIterator MyIterator;
    MyIterator = MyList.GetBegin();
    while (MyIterator.IsNext())
    {
        cout << MyIterator.GetData() << endl;
        ++MyIterator;
    }
    return 0;
}
