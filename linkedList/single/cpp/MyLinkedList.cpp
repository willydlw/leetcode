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


void MyLinkedList::addAtIndex(int index, int val)
{

    // Add to list at index position 0
    // Valid for both empty list and non-empty list.
    // If list is empty (0 elements) meets requirement 
    // that index equals length of list.
    if(index == 0)
    {
        addAtHead(val);
        return;
    }

    // List length is zero. Index > 0, meets condition that
    // index > list length is not inserted
    if(head == nullptr)
    {
        return;
    }

    int count = 0;
    SinglyListNode* current = head;
    while(current->next != nullptr && count < index)
    {
        count += 1;
        current = current->next;
    }

    if(count == index)
    {
        if(current == nullptr)
        {
            // index equals list length
            addAtTail(val);
        }
        else{
            // add before
            SinglyListNode* temp = new SinglyListNode(val);
            temp->next = current;
            current = temp;
        }
    }
    else
    {
        std::cerr << "TODO: complete addAtIndex\n";
    }
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