#include <stdio.h>
#include <stdbool.h>

bool isGood(int* nums, int numsSize)
{
    int i;
    int base[numsSize];    

    for(i = 0; i < numsSize; ++i)
    {
        base[i] = 0;
    }  


    for(i = 0; i < numsSize; ++i)
    {
        if(nums[i] < numsSize)
        {
            base[nums[i]] += 1;
        }
        else 
        {
            return false;
        }
        
    }

    for(i = 1; i < numsSize - 1; ++i)
    {
        if(base[i] != 1)
        {
            return false;
        }
    }

    if(base[numsSize-1] == 2)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void print_result(bool ans)
{
    if(ans)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

}


void run_tests(void)
{
    {
        int nums[3] = {2, 1, 3};
        print_result(isGood(nums, 3));
    }

    {
        int nums[4] = {1, 3, 3, 2};
        print_result(isGood(nums, 4));
    }

    {
        int nums[2] = {1, 1};
        print_result(isGood(nums, 2));
    }

    {
        int nums[6] = {3, 4, 4, 1, 2, 1};
        print_result(isGood(nums, 6));
    }
}

int main(void)
{
    run_tests();
    return 0;
}