#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <cstdlib>


/* Class is based on leetcode's explore singly linked list problem:
    Design Linked List
*/

struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x) : val(x), next(NULL) {}
};


class MyLinkedList{
    public:
        static const int INVALID_INDEX = -1;

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