#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

bool uniqueOccurrences(int* arr, int arrSize)
{   
    /*  Constraints:
        1 <= arr.length <= 1000
        -1000 <= arr[i] <= 1000
    */
   # define INDEX_OFFSET    1000
   # define COUNT_SIZE      2001
   int count[COUNT_SIZE] = {0};

   for(int i = 0; i < arrSize; ++i){
    count[arr[i]+INDEX_OFFSET]++;
   }

   qsort(count, COUNT_SIZE, sizeof(int), cmpfunc);

   for(int i = 1; i < COUNT_SIZE; ++i){
    if(count[i] && count[i-1]== count[i]){
        return false;
    }
   }

   return true;
}

void runTests(void)
{
    {
        /* Example 1
            Input: arr = [1,2,2,1,1,3]
            Output: true

            Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. 
            No two values have the same number of occurrences.
        */
       int arr[6] = {1,2,2,1,1,3};
       if(uniqueOccurrences(arr, 6)){
        printf("true\n");
       }
       else{
        printf("false\n");
       }
    }
}

int main(void)
{
    runTests();
    return 0;
}