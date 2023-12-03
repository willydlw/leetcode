#include "MyLinkedList.h"


MyLinkedList::MyLinkedList() : head(NULL) {}

MyLinkedList::~MyLinkedList()
{
    SinglyListNode *current = head;
    while(current != NULL)
    {
        head = current->next;
        delete current;
        current = head;
    }

    head = NULL;
}


/* Get the value of the indexth node in the linked list.
   If index is invalid, return -1.
*/
int MyLinkedList::get(int index) 
{
    SinglyListNode *current = getNode(index);

    if(current != NULL)
    {
        return current->val;
    }

    return MyLinkedList::INVALID_INDEX;
}

/*  Add node of value val before the first element of the linked list.
    After insertion, the new node will be the first element of the linked list.
*/
void MyLinkedList::addAtHead(int val)
{
    SinglyListNode *newNode = new SinglyListNode(val);
    newNode->next = head;
    head = newNode;
}

// Append node of value val as the last element
void MyLinkedList::addAtTail(int val)
{
    if(head != NULL)
    {
        SinglyListNode *newNode = new SinglyListNode(val);
        SinglyListNode *tail = getTail();   
        tail->next = newNode;
    }
    else
    {
        addAtHead(val);
    }
}


void MyLinkedList::addAtIndex(int index, int val)
{
    if(index == 0)
    {
        addAtHead(val);
        return;
    }

    SinglyListNode* prev = getNode(index-1);
    if(prev == nullptr)
    {
        return;
    }

    SinglyListNode* newNode = new SinglyListNode(val);
    newNode->next = prev->next;
    prev->next = newNode;
}


std::ostream& operator << (std::ostream& os, MyLinkedList& list)
{
    SinglyListNode* current = list.head;
    int index = 0;
    while(current != nullptr)
    {
        os << "index: " << index << ", val: " << list.get(index) << "\n";
        ++index;
        current = current->next;
    }

    return os;
}



SinglyListNode* MyLinkedList::getTail()
{
    SinglyListNode* current = head;
    while(current != nullptr && current->next != nullptr)
    {
        current = current->next;
    }

    return current;
}


SinglyListNode* MyLinkedList::getNode(int index)
{
    SinglyListNode* current = head;
    for(int i = 0; i < index && current!= nullptr; ++i)
    {
        current = current->next;
    }

    return current;
}