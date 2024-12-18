//
// Created by Donnie on 6/5/2023.
//

#ifndef LINKEDLISTOOP_LINKNODE_H
#define LINKEDLISTOOP_LINKNODE_H
#include <string>
using namespace std;
class LinkNode {
    friend class ListIterator;
public:
    LinkNode() {} // Typically not used in this version
    LinkNode(const int i, const string n)
    { id =i; name=n; prev= nullptr; next = nullptr; }
    int Getid() {return id;}
    string Getname() {return name;}
    void Setid (const int i) {id=i;}
    void Setname (const string n )  {name=n;}
    void Setprev(LinkNode * l) {prev =l;}
    void Setnext (LinkNode * l) {next = l;}
    LinkNode * Getprev() {return prev;}
    LinkNode * Getnext() {return next;}
protected:
    int id;
    string name;
    LinkNode * prev;
    LinkNode * next;
};
#endif //LINKEDLISTOOP_LINKNODE_H
