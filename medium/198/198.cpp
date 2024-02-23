/* 198 (medium) House Robber

    You are a professional robber planning to rob houses along a street. 
    Each house has a certain amount of money stashed, the only constraint 
    stopping you from robbing each of them is that adjacent houses have 
    security systems connected and it will automatically contact the police 
    if two adjacent houses were broken into on the same night.

    Given an integer array nums representing the amount of money of each 
    house, return the maximum amount of money you can rob tonight without 
    alerting the police.


    Constraints:
        1 <= nums.length <= 100
        0 <= nums[i] <= 400

*/

#include <vector>
#include <iostream>
#include <cassert>

class Solution {
public:

    int max(int a, int b)
    {
        return a < b? b : a;
    }

    int rob(std::vector<int>& nums) {
        int n = nums.size();
        int sum[n];

        if(n == 1)
        {
            return nums[0];
        }
        
        if(n == 2)
        {
            return max(nums[0], nums[1]);
        }

        sum[0] = nums[0];
        sum[1] = nums[1];
        sum[2] = nums[2] + nums[0];

        if(n == 3)
        {
            return max(nums[1], nums[0] + nums[2]);
        }

        for(int i = 3; i < n; ++i)
        {
            // chose largest total of prior sums while maintaining a gap of 1
            sum[i] = max(sum[i-3], sum[i-2]) + nums[i];      
        }

        return max(sum[n-2], sum[n-1]);
    }
};


void test(std::vector<int> &nums, int expected)
{
    Solution s;
    int ans = s.rob(nums);
    assert(ans == expected);
}

void runTests(void)
{
    {
        // Example 1
        std::vector<int> nums {1,2,3,1};

        // rob house[0] for a total of 1 and house[2] for a total of 1 + 3
        int expected = 4;

        test(nums, expected);
    }

    {
        // Example 2
        std::vector<int> nums {2,7,9,3,1};

        // rob houses 0,2,4 for a money total of 2 + 9 + 1
        int expected = 12;

        test(nums, expected);
    }

    {
        // Example 3
        std::vector<int> nums{14};

        // rob houses 0 for a money total of 14
        int expected = 14;

        test(nums, expected);
    }

    {
        // Example 4
        std::vector<int> nums{0,0,0,0,0,0,0};
        
        // rob houses for a money total of 0
        int expected = 0;

        test(nums, expected);
    }

    {
        // Example 5
        std::vector<int> nums{2,1,1,2};
        
        // rob houses for a money total of 0
        int expected = 4;

        test(nums, expected);
    }

    {
        // Example 6
        std::vector<int> nums{1,2};
        int expected = 2;
        test(nums, expected);
    }

    {
        // Example 7
        std::vector<int> nums{1,2,3};
        int expected = 4;
        test(nums, expected);
    }
}


int main(void)
{
    runTests();
    return 0;
}