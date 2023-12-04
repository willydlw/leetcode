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

void compareArrayToList(MyLinkedList& list, int *arr, int n, std::string funcName, int line)
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
    {   // test adding at head of empty list
        MyLinkedList list;
        int val = rand();
        list.addAtHead(val);
        int zeroVal = list.get(0);
        assert(zeroVal == val);
    }

    {   // test adding multiple values to head of list
        int i;
        int val;
        int n = rand() % MAX_ARRAY_LENGTH + 1;  // add 1 to ensure array size is not zero

        // C++ does not allow variable length arrays on the stack, so allocate on the heap
        int *arr = new int[n];
        
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

        delete [] arr;
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
        int *arr = new int[n];
        
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

        delete [] arr;
    }
}



void test_get(void)
{
    {   // test empty list
        MyLinkedList list;

        int emptyListValue = list.get(0);
        assert(emptyListValue == MyLinkedList::INVALID_INDEX);

        emptyListValue = list.get(1);
        assert(emptyListValue == MyLinkedList::INVALID_INDEX);

        int val = rand();
        list.addAtTail(val);
        int zeroVal = list.get(0);
        assert(zeroVal == val);
    }

    {   // test non-empty list with invalid values
        int i;
        int val;
        int n = rand() % MAX_ARRAY_LENGTH + 1;  // ensure array size is not zero
        int *arr = new int[n];
        
        randomFill(arr, n);

        // populate list in order with values from 0 to n-1
        MyLinkedList list;
        for(i = 0; i < n; ++i)
        {
            list.addAtTail(arr[i]);
        }
    
        // search list for invalid index values
        const int numSearches = rand() % MAX_SEARCHES + 1; 
        for(i = 0; i < numSearches; ++i)
        {
            int index = rand() % n + n;       // create index values not in list
            val = list.get(index);
            assert(val == MyLinkedList::INVALID_INDEX);
        }

        delete [] arr;

    }
}

void test_add_at_index(void)
{
    {   // test adding node at head of empty list
        MyLinkedList list;

        int val = rand();
        int index = 0;
        list.addAtIndex(index, val);
        int indexVal = list.get(index);
        assert(indexVal == val);
    }

   {   // test adding to emtpy list at index value greater than list length
        MyLinkedList list;

        int val = rand();
        int index = 1;
        list.addAtIndex(index, val);
        int indexVal = list.get(index);
        assert(indexVal == MyLinkedList::INVALID_INDEX);
    }

    {   // test inserting populated list at indices other than head
        int i;
        int val;
        int n = rand() % MAX_ARRAY_LENGTH + 1;  // ensure array size is not zero
        int *arr = new int[n];
        
        inOrderFill(arr, n);

        // populate list 
        MyLinkedList list;
        for(i = 0; i < n; i += 2)
        {
            list.addAtTail(arr[i]);
        }

        // insert missing array elements
        for(i = 1; i < n; i +=2)
        {
            list.addAtIndex(i, arr[i]);
        }
    
        // compare array elements to list
        // should be in same order
        for(i = 0; i < n; ++i)
        {
            val = list.get(i);
            assert(val == arr[i]);
        }

        delete [] arr;
    }
}


void printArray(int *arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << "  ";
    }

    std::cout << "\n";
}


void test_delete_at_index(void)
{
    {   // test deleting from head from a populated list
        int i;
        int val;
        int n = rand() % MAX_ARRAY_LENGTH + 1;  // ensure array size is not zero
        int *arr = new int[n];
        
        inOrderFill(arr, n);

        // populate list 
        MyLinkedList list;
        for(i = 0; i < n; ++i)
        {
            list.addAtTail(arr[i]);
        }

        // delete head node, index 0
        int listLength = n;
        for(int i = 0; i < n; ++i)
        {
            list.deleteAtIndex(0);
            --listLength;

            for(int j = 0; j < listLength; ++j)
            {
                // compare array elements to list
                val = list.get(j);
                assert(val == arr[i + j + 1]);
            }
        }
        delete [] arr;
    }

    {   // test deleting from tail 
        int i;
        int val;
        int n = rand() % MAX_ARRAY_LENGTH + 1;  // ensure array size is not zero
        int *arr = new int[n];
        
        inOrderFill(arr, n);

        // populate list 
        MyLinkedList list;
        for(i = 0; i < n; ++i)
        {
            list.addAtTail(arr[i]);
        }

        // delete tail node
        int listLength = n;
        for(int i = 0; i < n; ++i)
        {
            list.deleteAtIndex(listLength-1);
            --listLength;

            for(int j = 0; j < listLength; ++j)
            {
                // compare array elements to list
                val = list.get(j);
                assert(val == arr[j]);
            }
        }
        delete [] arr;
    }

    {   // test deletion from empty list
        // A better test might be ensuring the head pointer is null
        // but the class doesn't give access to the head pointer

        // Purpose of this test is to ensure deletion doesn't crash program
        // calling get to verify list may not be the ideal test, but going
        // with it at this time.
        MyLinkedList list;

        // validate list is empty
        int val = list.get(0);
        assert(val == MyLinkedList::INVALID_INDEX);
        list.deleteAtIndex(0);

        // validate list is still empty
        val = list.get(0);
        assert(val == MyLinkedList::INVALID_INDEX);
    }

    {   // test deletion from an invalid index
        int val;
        int n = rand() % MAX_ARRAY_LENGTH + 1;  // ensure array size is not zero
        int *arr = new int[n];
        
        inOrderFill(arr, n);

        // populate list 
        MyLinkedList list;
        for(int i = 0; i < n; ++i)
        {
            list.addAtTail(arr[i]);
        }

        // delete at some random ivalid index >= n
        list.deleteAtIndex(rand() + n);

        for(int i = 0; i < n; ++i)
        {
            val = list.get(i);
            assert(val == arr[i]);
        }
        
        delete [] arr;
    }

    {   // test deleting from a random valid index
        int val;
        int n = rand() % MAX_ARRAY_LENGTH + 1;  // ensure array size is not zero
        int *arr = new int[n];
        
        inOrderFill(arr, n);

        // populate list 
        MyLinkedList list;
        for(int i = 0; i < n; ++i)
        {
            list.addAtTail(arr[i]);
        }

        int deleteIndex = rand() % n;
        list.deleteAtIndex(deleteIndex);

        int listIndex = 0;
        for(int i = 0; i < n; ++i)
        {
            if(i != deleteIndex)
            {
                val = list.get(listIndex);
                assert(val == arr[i]);
                ++listIndex;
            }
        }

        delete [] arr;
    }
}