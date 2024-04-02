#include <vector>
#include <cassert>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

/* Constraints
    1 <= nums1.length, nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 1000
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::map<int,int> mapArray;
        std::vector<int> ans;

        // iterate through first array, only recording one occurrence
        // of each unique value in nums 1 (don't care if there are multiples
        // of same value in nums 1
        for(auto n : nums1)
        {
            mapArray[n] = 1;
        }

        // iterate through nums2. If numeric value is a key in the map
        // then this value is an intersection value
        for(auto n : nums2)
        {
            if(mapArray[n] == 1)
            {
                ans.push_back(n);
                // increase count to avoid adding more than 
                // one occurrence of same value in intersection set
                mapArray[n] = 2; 
            }
        }
        return ans;
    }

    
};

void test(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& expected)
{
    Solution s;
    std::vector<int> ans;
    ans = s.intersection(nums1, nums2);

    assert(expected.size() == ans.size());

    sort(ans.begin(), ans.end());
    for(long unsigned int i = 0; i < expected.size(); ++i)
    {
        assert(ans[i] == expected[i]);
    }
}


void runtests(void)
{
    {
        // Example 1
        std::vector<int> nums1 = {1,2,2,1};
        std::vector<int> nums2 = {2,2};
        std::vector<int> expected = {2};
        test(nums1, nums2, expected);
    }

    {
        // Example 2
        std::vector<int> nums1 = {4,9,5};
        std::vector<int> nums2 = {9,4,9,8,4};
        std::vector<int> expected = {4,9};
        test(nums1, nums2, expected);
    }
}


int main(void)
{
    runtests();
    return 0;
}