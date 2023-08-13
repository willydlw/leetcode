#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <cstdlib>

struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x) : val(x), next(NULL) {}
};


class MyLinkedList{
    public:
        MyLinkedList();

        /* Get the value of the indexth node in the list. 
           List is 0-indexed
           If the index is invalid, return -1
        */
        int get(int index) const;

        void addAtHead(int val);
        void addAtTail(int val);

        ~MyLinkedList();

    private:
        SinglyListNode *head;
};

#endif 