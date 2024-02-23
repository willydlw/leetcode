/*  Minimum number of operations to make array empty

    You are given a 0-indexed array nums consisting of positive integers.

    There are two types of operations that you can apply on the array any 
    number of times:

    - Choose two elements with equal values and delete them from the array.
    - Choose three elements with equal values and delete them from the array.
    
    Return the minimum number of operations required to make the array empty, 
    or -1 if it is not possible.

    Constraints:   
        2 <= nums.length <= 10^5
        1 <= nums[i] <= 10^6
*/

#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_map>

class Solution {
public:

    /* First Attempt - works but can be more efficient.

       Editorial explained that ceil(count / 3) provides correct answer.
       ceil() function rounds up when the remainder is not zero.

       ceil(2/3) = 1.  For the count of 2, we subtract 2 once
       ceil(3/3) = 1.  For the count of 3, we subtract 3 once
       ceil(4/3) = 2.  For the count of 4, we subtract 2 twice
       ceil(5/3) = 2.  For the count of 5, we subtract 3 once, 2 once
    */
    int minOperations1(std::vector<int>& nums) 
    {
        int totalOps = 0;

        std::unordered_map<int, int> umap;

        // map frequency count of array elements
        for(long unsigned int i = 0; i < nums.size(); ++i)
        {
            umap[nums[i]]++;
        }

        // verify count
        for(auto u : umap)
        {
            int currentOps = 0;
            if(u.second == 1)
            {
                return -1;
            }
            else 
            {
                if(u.second % 3 == 0)
                {
                    currentOps = u.second / 3;
                }
                else
                {
                    while(u.second > 4)
                    {
                        u.second -= 3;
                        ++currentOps;
                    }

                    // u.second should be an even number
                    currentOps += u.second / 2;
                }
                totalOps += currentOps;
            }
        }
        return totalOps;
    }

    /* Better solution

       Editorial explained that ceil(count / 3) provides correct answer.
       ceil() function rounds up when the remainder is not zero.

       ceil(2/3) = 1.  For the count of 2, we subtract 2 once
       ceil(3/3) = 1.  For the count of 3, we subtract 3 once
       ceil(4/3) = 2.  For the count of 4, we subtract 2 twice
       ceil(5/3) = 2.  For the count of 5, we subtract 3 once, 2 once

       Comments suggested an even better method of (count + 2) / 3. May run 
       faster than calling the ceiling function which performs floating point
       division.
    */
    int minOperations(std::vector<int>& nums) 
    {
        int totalOps = 0;

        std::unordered_map<int, int> count;

        // map frequency count of array elements
        for(long unsigned int i = 0; i < nums.size(); ++i)
        {
            count[nums[i]]++;
        }

        // verify count
        for(auto c : count)
        {
            int currentOps = 0;
            if(c.second == 1)
            {
                return -1;
            }
            else 
            {
                // u.second should be an even number
                currentOps += (c.second + 2) / 3;
            }
            totalOps += currentOps;
        }
        return totalOps;
    }
};



void test(std::vector<int>& nums, int expectedAns)
{
    Solution s;
    int ans = s.minOperations(nums);
    printf("ans: %d\n", ans);
    assert(ans == expectedAns);
}

void runTests(void)
{
    {
        std::vector<int> a{2,3,3,2,2,4,2,3,4};
        test(a, 4);
    }
    {
        std::vector<int> a{2,1,2,2,3,3};
        test(a, -1);
    }

    {
        std::vector<int> a{1};
        test(a, -1);
    }

    {
        std::vector<int> a{2,2};
        test(a, 1);
    }

    {
        std::vector<int> a{3,3,3};
        test(a, 1);
    }

    {
        std::vector<int> a{4,4,4,4};
        test(a, 2);
    }

    {
        std::vector<int> a{5,5,5,5,5};
        test(a, 2);
    }

    {
        std::vector<int> a{1,1,1,1,1,1};
        test(a, 2);
    }

    {
        std::vector<int> a{1,1,1,1,1,1,1};
        test(a, 3);
    }
}


int main(void)
{
    runTests();
    return 0;
}