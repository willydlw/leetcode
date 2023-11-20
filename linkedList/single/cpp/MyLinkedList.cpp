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
int MyLinkedList::get(int index) const
{
    SinglyListNode *current = head;
    int count = 0;

    while(current != NULL)
    {
        if(count != index)
        {
            current = current->next;
            ++count;
        }
        else 
        {
            return current->val;
        }
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
        SinglyListNode *current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    else
    {
        addAtHead(val);
    }
}