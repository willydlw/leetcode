#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:

    /*  Given the head of a linked list, remove the nth node from the end
        of the list and return its head.
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Space complexity O(n) where n is number of nodes in list 
        // Time complexity O(n) where n is number of nodes in list
        std::vector<ListNode*> ptrArray;

        // populate ptrArray
        ListNode* current = head;
        while(current != nullptr)
        {
            ptrArray.push_back(current);
            current = current->next;
        }

        // remove nth node 
        int removeIndex = ptrArray.size() - n;

        // Constraints
        // Number of node in list is sz
        // 1 <= sz <= 30
        // 1 <= n <= sz
        if(removeIndex == 0)
        {
            head = head->next;
        }
        else 
        {
            ptrArray[removeIndex-1]->next = ptrArray[removeIndex]->next;
        }
        delete ptrArray[removeIndex];
        return head;
    }
};


ListNode* test(ListNode* head, int n, std::vector<int>& expected)
{
    Solution s;
    head = s.removeNthFromEnd(head, n);

    ListNode* current = head;
    long unsigned int i;
    for(i = 0; i < expected.size() && current != nullptr; ++i, current = current->next)
    {
        assert(current->val == expected[i]);
    }

    assert(i == expected.size());
    return head;
}

ListNode* insertHead(ListNode* head, int val)
{
    ListNode *newNode = new(ListNode);
    newNode->val = val;
    newNode->next = head;
    head = newNode;
    return head;
}

ListNode* deleteList(ListNode* head)
{
    ListNode* current = head;
    while(current != nullptr)
    {
        head = current->next;
        delete current;
        current = head;
    }

    return nullptr;
}

void runTests(void)
{
    // Constraints
    // Number of node in list is sz
    // 1 <= sz <= 30
    // 1 <= n <= sz

    {   // List with 1 node
        std::vector<int> expected;
        ListNode* head = nullptr;
        head = insertHead(head, 12);
        head = test(head, 1, expected);
        head = deleteList(head);
    }

    {   // Example: List with two nodes
        std::vector<int> expected = {1};
        ListNode* head = nullptr;
        head = insertHead(head, 2);
        head = insertHead(head, 1);
        head = test(head, 1, expected);
        head = deleteList(head);
    }

    {   // Example list with multiple nodes
        std::vector<int> expected = {1,2,3,5};
        ListNode* head = nullptr;
        head = insertHead(head, 5);
        head = insertHead(head, 4);
        head = insertHead(head, 3);
        head = insertHead(head, 2);
        head = insertHead(head, 1);
        head = test(head, 2, expected);
        head = deleteList(head);
    }
}


int main(void)
{
    runTests();
    return 0;
}