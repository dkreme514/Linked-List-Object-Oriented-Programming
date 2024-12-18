//
// Created by Donnie on 6/5/2023.
//

#ifndef LINKEDLISTOOP_LINKLIST_H
#define LINKEDLISTOOP_LINKLIST_H
#include <iostream>
#include <string>
#include "linknode.h"
using namespace std;
class ListIterator;
class LinkList {
public:
    friend class ListIterator;
    LinkList();
    ~LinkList();
    int Size() {return count;}
    bool Empty() {return count==0;}
    void Clear();
    bool Insert(const int i, const string n);
    void List();
    int Find(const string n);
    bool Delete (const int i);

    ListIterator GetBegin(); // returns true if succesful
    LinkList & operator = ( LinkList & L);

protected:
    LinkNode * _head;
    LinkNode * _tail;
    LinkNode * _prev;   // used to insert nodes
    LinkNode * _node;   // used to create list
    LinkNode * _curr;
    int count; // number of records
};
class ListIterator {
public:
    friend class LinkList;
    ListIterator() { ptr = nullptr; }
    ListIterator(LinkList p) { ptr = p._head; }
    bool IsNext() {
        if (ptr->next == nullptr) return false;
        else return true;
}
    bool IsPrev()
    { if(ptr->prev==nullptr) return false;
         else return true;}
    void Next()
        { if(ptr!=nullptr) ptr=ptr->next;}
    string GetData()
        {return ptr->name;}
    friend ListIterator * operator ++(ListIterator & p)
    { p.ptr=p.ptr->Getnext(); }
protected:
    LinkNode * ptr;
};

#endif //LINKEDLISTOOP_LINKLIST_H
