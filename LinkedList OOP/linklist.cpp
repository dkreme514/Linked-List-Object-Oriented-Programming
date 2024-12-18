//
// Created by Donnie Kremer on 6/5/2023.
// File description: Header file for creating a Linked
//   List for Object Oriented Programming. This project
//   is to understand the workings of the Linked List
//   data structure.
//

#include "linklist.h"
#include "linknode.h"
using namespace std;
LinkList::LinkList()
{
    _head = nullptr;
    _tail = nullptr;
    _node = nullptr;
    _curr = nullptr;
    count=0;
}
// *****************************************************
// * Destructor: Deletes all of the records
// *    created in the list
// *****************************************************
LinkList::~LinkList()
{
    cout << "Destructor Called" << endl;
    Clear();
    /*
    if (Empty())
    {
        return;
    }
    _curr=_head;
    while (_curr != nullptr)
    {
        _node = _curr;
        _curr = _curr->Getnext();
        delete _node;
    }
*/
}
// *****************************************************
// * Insert
// *****************************************************
bool LinkList::Insert(const int i, const string n)
{
    _node = new LinkNode(i,n);
    _node->Setnext(nullptr);
    _node->Setprev(nullptr);

    cout << "Inserting " <<_node->Getname()<<endl;
    if(Empty())
    {
        _head=_node;
        _tail=_node;
        count++;
        return true;
    }
    if(n < _head->Getname()) // If it replaces the head
    {
        cout <<"Replace Head" <<endl;
        _node->Setnext(_head);  // Set the new node to point to the old head
        _head->Setprev(_node);  // Set the old head to point to the new node
        _head=_node;        // new head
        count++;
        return true;
    }
    if(n > _tail->Getname()) // If it replaces the head
    {
        cout <<"Replace Tail" <<endl;
        _node->Setprev(_tail);  // Set the new node to point to the old head
        _tail->Setnext(_node);  // Set the old head to point to the new node
        _tail=_node;             // new tail
        count++;
        return true;
    }
    _curr=_head;
    while (n > _curr->Getname())
    {
        _curr = _curr->Getnext();
    }
    LinkNode * tempprev;
    tempprev = _curr->Getprev();
    _node->Setprev(tempprev);
    _node->Setnext(_curr);
    tempprev->Setnext(_node);
    _curr->Setprev(_node);
    count++;
    return true;
}
// *****************************************************
// * List
// *****************************************************
void LinkList::List() {
    if(Empty()) {
        cout <<"Empty List"<<endl;
    }
    _curr=_head;
    while (_curr!=nullptr)
    {
        cout<< _curr->Getid() << " " <<_curr->Getname() << endl;
        _curr =_curr->Getnext();
    }
}
// *****************************************************
// * Find
// *****************************************************
int LinkList::Find(const std::string n) {
    _curr=_head;
    while(_curr != nullptr) {
        if (n == _curr->Getname())
            return _curr->Getid();
        else _curr = _curr->Getnext();
    }
    return -1; // signals not found

}
void LinkList::Clear()
{
    if (Empty())
    {
        return;
    }
    _curr=_head;
    while (_curr != nullptr)
    {
        _node = _curr;
        _curr = _curr->Getnext();
        delete _node;
    }
}
LinkList & LinkList::operator=(LinkList & L) {
    if (!Empty()) Clear();
    static LinkNode * Temp;
    Temp = L._head;
    while(Temp !=nullptr)
    {
        Insert(Temp->Getid(), Temp->Getname());
        Temp=Temp->Getnext();
    }
    return *this;
}
// *****************************************************
// * Delete
// *****************************************************
bool LinkList::Delete(const int i) {
    if (_head->Getid() == i)
    {
        _curr=_head;
        _head=_head->Getnext();
        delete _curr;
        return true;
    }
    if (_tail->Getid() == i)
    {
        _curr=_tail;
        _tail=_tail->Getprev();
        delete _curr;
        return true;
    }
    _curr = _head;
    while(_curr!= nullptr)
    {
        if(_curr->Getid()==i)
        {
            _prev=_curr->Getprev();
            _node=_curr->Getnext();
            _prev->Setnext(_node);
            _node->Setprev(_prev);
            delete _curr;
            count--;
            return true;
        }
        else
            _curr=_curr->Getnext();
    }
    return false;
}
ListIterator LinkList::GetBegin()
{
    ListIterator temp;
    temp.ptr = _head;
    return temp;
}