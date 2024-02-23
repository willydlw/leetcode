/* Leetcode, 2610, medium

    You are given an integer array nums. You need to create a 2D array from nums 
    satisfying the following conditions:

        - The 2D array should contain only the elements of the array nums.
        - Each row in the 2D array contains distinct integers.
        - The number of rows in the 2D array should be minimal.
        - Return the resulting array. If there are multiple answers, return any of them.

    Note that the 2D array can have a different number of elements on each row.

*/

#include <iostream>
#include <vector>

class Solution {
public:

    /*  Constraints:
            1 <= nums.length <= 200
            1 <= nums[i] <= nums.length
    */
    std::vector<std::vector<int>> findMatrix(std::vector<int>& nums) 
    {
        int len = (int)nums.size() + 1;

        std::vector<int> frequencyCount(len, 0);

        // O(len) time complexity to perform frequency count
        for (int n : nums)
        {
            frequencyCount[n] += 1;
        }

        // find most frequent number. This is number of rows.
        // 0(len) time complexity
        int maxCount = 0;
        for (int n : frequencyCount)
        {
            if(maxCount < n)
            {
                maxCount = n;
            }
        }

        // number of rows is max count
        std::vector<std::vector<int>> ans(maxCount);

        // O(len) time complexity for iterating through frequency array
        for(int i = 1; i < len; ++i)
        {
            // O(maxCount, i.e. numRows) time complexity 
            for(int r = 0; r < frequencyCount[i]; ++r)
            {
                ans[r].push_back(i);
            }
        }

        return ans;
    }
};


void printResult(std::vector<std::vector<int>> v)
{
    for(int i = 0; i <(int)v.size(); ++i)
    {
        for(int j = 0; j < (int)v[i].size(); ++j)
        {
            std::cout << v[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void run_tests(void)
{
    {
        std::vector<int> nums {1,3,4,1,2,3,1};

        Solution s;

        // Expected output  [[1,2,3,4], [1,3], [1]]
        std::vector<std::vector<int>> ans = s.findMatrix(nums);
        printResult(ans);
        
    }
}


int main(void)
{
    run_tests();
    return 0;
}
