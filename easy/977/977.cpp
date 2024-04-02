#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> ans(nums);

        for(auto& v : ans){
            v *= v;
        }

        std::sort(ans.begin(), ans.end());
        return ans;
    }
};


void test(std::vector<int>& nums, std::vector<int>& expected)
{
    Solution s;
    std::vector<int> result;
    result = s.sortedSquares(nums);
    for(long unsigned int i = 0; i < nums.size(); ++i)
    {
        assert(result[i] == expected[i]);
    }
}

void runTests(void)
{
    {
        std::vector<int> v = {-4, -1, 0, 3, 10};
        std::vector<int> expected = {0, 1, 9, 16, 100};
        test(v, expected);
    }

     {
        std::vector<int> v = {-7, -3, 2, 3, 11};
        std::vector<int> expected = {4, 9, 9, 49, 121};
        test(v, expected);
    }
}

int main(void)
{
    runTests();
    return 0;
}