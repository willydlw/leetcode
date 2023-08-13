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

    return -1;
}

void MyLinkedList::addAtHead(int val)
{
    SinglyListNode *newNode = new SinglyListNode(val);
    newNode->next = head;
    head = newNode;
}

void MyLinkedList::addAtTail(int val)
{

}