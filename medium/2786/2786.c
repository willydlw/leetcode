/* Visit Array Positions to Maximize Score

    Given a 0-indexed array and a positive integer x

    Initially at array position 0 and can visit other positions according to 
    the following rules:
        - If you are currently in position i, then you can move to any 
          position j such that i < j
        - For each position i that you visite you get a score of nums[i]
        - If you move from i to j and the parities of arr[i] and arr[j]
          differ, they you lose a score of x.

          NOTE: By parity, they mean mathematical parity, whether an
          integer is an odd number or an even number.
    
    Return the maximum total score you can get.

    Initially you have arr[0] points.
*/

#include <assert.h>
#include <stdio.h>

long long max(long long a, long long b)
{
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

long long maxScore(int* nums, int numsSize, int x){
        long long odd;          // maximum score of most recent odd number
        long long even;         // maximum score of most recent even number

        // assign initial score based on even/odd state
        if(nums[0] & 1)
        {
            odd = (long long)nums[0];
            even = (long long)nums[0] - x;         
        }
        else
        {
            odd = (long long)nums[0] - x;
            even = (long long)nums[0];
        }

        for(int i = 1; i < numsSize; ++i) {
            if(nums[i] & 1){

                odd = (long long)nums[i] + max(odd, even - x);    
            }
            else{
                even = (long long)nums[i] + max(odd - x, even );
            }
        }

       return max(odd, even);
}

void run_tests(void)
{
    {
        // case 1
        int nums[6] = {2, 3, 6, 1, 9, 2};
        int x = 5;
        long long max = maxScore(nums, 6, x);
        // 2 + 6 + 1 + 9 - 5 = 13
        assert(max == 13);
    }
    
    {
        // case 2
        int nums[4] = {2, 4, 6, 8};
        int x = 3;
        long long max = maxScore(nums, 4, x);
        // 2 + 4 + 6 + 8 = 20
        assert(max == 20);
    }
}


int main(void){
    run_tests();
    return 0;
}