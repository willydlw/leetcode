/* Problem 1480 - Running Sum of 1d array

    Given an array nums, we define a running sum of an array
    as runningSum[i] = sum(nums[0]...nums[i])

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 *  Note: The returned array must be malloced, assume caller calls free().
 * 
 *  Constraints
 *  1 <= nums.length <= 1000
 *  -10^6 <= nums[i] <= 10^6 
 * 
 *  Max possible sum: 1000 * 10^6 = 10^9 
 * 
 *  (signed 32 bit int type ok for sum: -2147,483,648 to 2,147,483,647)
 * 
 *  Problem provides the function header below. 
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int* sum = NULL;
    
    sum = (int*) malloc(numsSize * sizeof(int));

    if(sum == NULL)
    {
         *returnSize = 0;
        return NULL;
    }

    sum[0] = nums[0];

    for(int i = 1; i < numsSize; i++)
    {
        sum[i] = sum[i-1] + nums[i];
    }

    *returnSize = numsSize;
    return sum;
}


bool compare(int* sums, int asize, int* expected)
{
    for(int i = 0; i < asize; ++i)
    {
        if(sums[i] != expected[i])
        {
            printf("Error: sums[i] = %d, expected[i] = %d\n", sums[i], expected[i]);
            return false;
        }
    }

    return true;
}


void test(int* nums, int asize, int* expected, int testNumber)
{
    int returnSize = -1;
    int* sums = runningSum(nums, asize, &returnSize);
    
    if(!(compare(sums, asize, expected)))
    {
        printf("Test number %d failure\n", testNumber);
    }

    free(sums);
}


void run_tests()
{
    int testNumber = 1;

    {
        int nums[4]= {1,2,3,4};
        int expected[4] = {1, 3, 6, 10};
        test(nums, 4, expected, testNumber);
        testNumber++;
    }

    {
        int nums[5] = {1,1,1,1,1};
        int expected[5] = {1,2,3,4,5};
        test(nums, 4, expected, testNumber);
        testNumber++;
    }

    {
        int nums[5] = {3, 1, 2, 10, 1};
        int expected[5] = {3, 4, 6, 16, 17};
        test(nums, 4, expected, testNumber);
        testNumber++;
    }

    {
        int nums[0];
        int expected[0];
        test(nums, 0, expected, testNumber);
        testNumber++;
    }

}


int main(void)
{
    run_tests();
    return 0;
}