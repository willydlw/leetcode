/*  2181. Merge Nodes in Between Zeros

    Given: the head of a linked list, which contains a series of integers 
    separated by 0's. The beginning and end of the linked list will have Node.val == 0

    For every two consecutive 0's, merge all the nodes lying in between them into
    a single node whod value is the sum of all the merged nodes. The modified list
    should not contain any 0's.

    Return the head of the modified linked list.
*/

#include <iostream>
#include <new>
#include <cassert>

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:

    /* 
        Constraints
        - Number of nodes in list is in the range [3, 2*10^5]
        - 0 <= Node.val <= 1000 
        - No two consecutive nodes with Node.val == 0
        - Beginning and end of linked list have Node.val == 0
    */
    ListNode* mergeNodes(ListNode* head) {
        ListNode* firstZero = head;         // per constraint, head will have zero value
        ListNode* current = head->next;     // per constraint, at least 3 nodes in list

        // When the end of list is reached, need address of previous first zero pair
        // to properly null-terminate the list
        ListNode* previousZero = nullptr;   
       
        
        /*  sum must be an int type. Why?
        *   Weak argument - sum to be stored in ListNode val which is int type
        *
        *   Stronger argument - 
        *       max possible sum 2*10^5 * 1000 = 2 * (10^5) * (10^3) = 200,000,000
        *       which is less than the max value of a positive 4-bit int type (2,147,483,647)
        */
        
        while(current != nullptr)
        {
            if(current->val == 0)
            {   // found second zero
                previousZero = firstZero;
                firstZero = current;
                current = current->next;            
            }
            else    // second zero not found
            {
                firstZero->val += current->val;            // add list value to sum
                // Remove this node from the list
                firstZero->next = current->next;           // connect firstZero to next node in list
                delete current;
                current = firstZero->next;
            }
        }

        if(firstZero->val == 0)
        {
            // reached end of list, per constraint, no two consecutive zeros in list 
            // previousZero points to last node in list, set its next pointer to null
            previousZero->next = nullptr;
            delete firstZero; 
        }

        return head;
        
    }
};

ListNode* allocNode(int val)
{
    ListNode* temp = nullptr;
    try
    {
        temp = new ListNode(val);
    }
    catch(std::bad_alloc& ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << "\n";
    }

    return temp;
}


ListNode* createList(int *arr, int n)
{
    ListNode* head = nullptr;
    ListNode* tail = head;

    // add first array element to head of list
    head = allocNode(arr[0]);
    tail = head;

    // add remaining array elements at tail
    for(int i = 1; i < n && tail != nullptr; ++i)
    {
        ListNode* temp = new ListNode(arr[i]);
        tail->next = temp;
        tail = temp;
    }

    return head;
}


void printList(const ListNode* head)
{
    const ListNode* current = head;
    while(current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << "\n";
}


ListNode* deleteList(ListNode* head)
{
    while(head != nullptr)
    {
        ListNode* temp = head->next;
        delete head;
        head = temp;
    }

    return head;
}


void test(int* original, int origLen, int* expected, int expectedLen)
{
    ListNode* head = createList(original, origLen);
    printList(head);
    Solution s;
    head = s.mergeNodes(head);

    ListNode* current = head;
    printList(head);
    for(int i = 0; i < expectedLen && current != nullptr; i++)
    {
        assert(current->val == expected[i]);
        current = current->next;
    }

    head = deleteList(head);
    assert(head == nullptr);
}

void runTests()
{
    {   // list has at least 3 elements
        int arr[3] = {0,3,0};
        int expected[1] = {3};
        test(arr, 3, expected, 1);
    }

    {   // list has two zeros
        int arr[4] = {0, 2, 3, 0};
        int expected[1] = {5};
        test(arr, 4, expected, 1);
    }

    {
        int arr[8] = {0,3,1,0,4,5,2,0};
        int expected[2] = {4, 11};
        test(arr, 8, expected, 2);
    }
}


int main(void)
{
    runTests();
    return 0;
}