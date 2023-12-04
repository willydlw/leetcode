#ifndef TEST_LIST_H
#define TEST_LIST_H

#include "MyLinkedList.h"

#define MAX_ARRAY_LENGTH 10
#define MAX_SEARCHES 10

void randomFill(int *arr, int n);
void inOrderFill(int *arr, int n);

void test_add_at_head(void);
void test_add_at_tail(void);
void test_add_at_index(void);

void test_delete_at_index(void);

void test_get(void);


void printArray(int *arr, int n);

#endif 