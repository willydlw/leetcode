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
    {   // test adding to emtpy list at index zero
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

    #if 1
    {   // test list with valid indices
        int i;
        int val;
        int n = rand() % MAX_ARRAY_LENGTH + 1;  // ensure array size is not zero
        int *arr = new int[n];
        
        inOrderFill(arr, n);

        std::cerr << "Test Array\n";
        printArray(arr, n);


        // populate list with every other array value
        MyLinkedList list;
        for(i = 0; i < n; i += 2)
        {
            list.addAtTail(arr[i]);
        }

        std::cerr << "\nList - should contain every other array value\n";
        std::cerr << list << "\n";

        // insert missing array elements
        for(i = 1; i < n; i +=2)
        {
            list.addAtIndex(i, arr[i]);
        }

        std::cerr << "\nList after adding missing array values at index positions\n";
        std::cerr << list << "\n";
    
        // compare array elements to list
        // should be in same order
        for(i = 0; i < n; ++i)
        {
            val = list.get(i);
            assert(val == arr[i]);
        }

        delete [] arr;
    }

    #endif
}


void printArray(int *arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << "  ";
    }

    std::cout << "\n";
}