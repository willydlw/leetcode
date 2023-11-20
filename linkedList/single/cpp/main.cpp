#include "test.h"

// g++ -Wall -pedantic -g main.cpp test.cpp MyLinkedList.cpp 
// valgrind -s ./a.out


int main(void)
{
    test_add_at_head();
    test_add_at_tail();
    test_get();
    test_add_at_index();
    return 0;
}