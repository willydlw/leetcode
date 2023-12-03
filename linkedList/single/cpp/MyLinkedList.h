#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <cstdlib>
#include <iostream>


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
        int get(int index);

        void addAtHead(int val);
        void addAtTail(int val);

        /*  Add node of value val before the indexth node.

            If index equals the length of the linked list, the node will be 
            appended to the end of the list.

            If index is greater than the length, the node will not be inserted.

            Nodes are 0-indexed.
        */
        void addAtIndex(int index, int val);

        ~MyLinkedList();

        friend std::ostream& operator << (std::ostream& os, MyLinkedList& list);

    private:
        SinglyListNode *head;

        // Returns the last node in the linked list
        // Returns null pointer when list is empty
        SinglyListNode* getTail();

        // Returns the index-th node in the list
        // Return null pointer when index is greater than list length
        // Nodes are 0-indexed
        SinglyListNode* getNode(int index);
};

#endif 