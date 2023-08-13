#include <cassert>
#include <cstdlib>
#include <string>

#include "test.h"

void randomFill(int *arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        arr[i] = rand();
    }
}

void inOrderFill(int *arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        arr[i] = i;
    }
}

void compareArrayToList(const MyLinkedList& list, int *arr, int n, std::string funcName, int line)
{
    int i;
    int val;

    for(i = 0; i < n; ++i)
    {
        val = list.get(i);
        assert( val == arr[i]);
    }
}

void test_add_at_head(void)
{
    {
        MyLinkedList list;
        int val = rand();
        list.addAtHead(val);
        int zeroVal = list.get(0);
        assert(zeroVal == val);
    }

    {
        int i;
        int val;
        int n = rand() % MAX_ARRAY_LENGTH + 1;  // ensure array size is not zero
        int arr[n];
        
        randomFill(arr, n);

        // populate list
        MyLinkedList list;
        for(i = n-1; i >= 0; --i)
        {
            list.addAtHead(arr[i]);
        }
    
        // compare array elements to list
        // should be in same order
        for(i = 0; i < n; ++i)
        {
            val = list.get(i);
            assert(val == arr[i]);
        }
    }
}


void test_add_at_tail(void)
{
    {   // test empty list
        MyLinkedList list;
        int val = rand();
        list.addAtTail(val);
        int zeroVal = list.get(0);
        assert(zeroVal == val);
    }

    {
        int i;
        int val;
        int n = rand() % MAX_ARRAY_LENGTH + 1;  // ensure array size is not zero
        int arr[n];
        
        randomFill(arr, n);

        // populate list
        MyLinkedList list;
        for(i = 0; i < n; ++i)
        {
            list.addAtTail(arr[i]);
        }
    
        // compare array elements to list
        // should be in same order
        for(i = 0; i < n; ++i)
        {
            val = list.get(i);
            assert(val == arr[i]);
        }
    }
}