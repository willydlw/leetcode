/*  Longest Increasing Subsequence

    Given an integer array nums, return the length of the longest strictly 
    increasing subsequence.

    A subsequence is an array that can be derived from another array by deleting 
    some or no elements without changing the order of the remaining elements.

    Constraints:
        - 1   <= nums.length <= 2500
        -10^4 <= nums[i]     <= 10^4

*/

#include <cassert>
#include <vector>
#include <algorithm>

class Solution {
public:

    /*  Dynamic Programming Solution

        Use recursion

         Example: nums = {1, 2, 4, 3};

        Start at the end of the array, where the longest increasing subsequence 
        is length 1.

            LIS[index 3] = 1

        Move to the left, index 2:
            We can take 4 by itself which is length 1 or 4 with number at index 3 if 
            that value is less than 4.

            LIS[index 2] = max(1, 1 + LIS[index 3])

            If nums[2] < nums[3], then 1 + LIS[index 3]
            else 1 

        Move to the left, index 1:
            max(1, 1 + LIS[2], 1 + LIS[3])

        Move to the left, index 0:
            max(1, 1 + LIS[1], 1 + LIS[2], 1 + LIS[3])


        Time complexity is O(n^2). Why?

        When we start at the end, we look at one value.
        When moving to left, we check that value and the one at the end.
        Move to left, we check that value and the two to its right.
        We cycle through approximately n^2 times.
    */
    int lengthOfLIS(std::vector<int>& nums) {
        
        // Create an array to hold LIS for each index position. 
        // Initialize values to 1
        std::vector<int> LIS(nums.size(), 1);

        // iterate backward throught the array
        for(int i = (int)nums.size(); i >= 0; --i)
        {
            for(int j = i + 1; j < (int)nums.size(); ++j)
            {
                if(nums[i] < nums[j])
                {
                    LIS[i] = std::max(LIS[i], 1 + LIS[j]);
                }
            }
        }
        return *std::max_element(LIS.begin(), LIS.end(), Solution::myfn);
    }

    static bool myfn(int i, int j) { return i<j; }
};


void test(std::vector<int>& nums, int expected)
{
    Solution s;
    int ans = s.lengthOfLIS(nums);
    assert(ans == expected);
}

void runTests()
{
    {  // Example 1
    
        std::vector<int>nums{10,9,2,5,3,7,101,18};
        // Explanation: The longest increasing subsequence is [2,3,7,101], 
        // therefore the length is 4.
        test(nums, 4);
    }

    {   // Example 2
        std::vector<int> nums{0,1,0,3,2,3};
        test(nums, 4);
    }

    {   // Example 3
        std::vector<int> nums{7,7,7,7,7,7,7};
        test(nums, 1);
    }
}


int main(void)
{
    runTests();
    return 0;
}


Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
