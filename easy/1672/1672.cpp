/* Richest Customer Wealth

    Given an m x n integer grid accounts where accounts[i][j] is
    the amount of money the ith customer has in the jth bank, return
    the wealth that the richest customer has.

    A customer's wealth is the amount of money they have in all their
    bank accounts. The richest customer is the customer that has the 
    maximum wealth.

    Constraints:

    m - accounts.length
    n - accounts[i].length
    1 <= m,n <= 50
    1 <= accounts[i][j] <= 100

*/

#include <cassert>
#include <vector>


class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int max = 0;
        for(auto person : accounts)
        {
            int sum = 0;
            for(auto bank : person)
            {
                sum += bank;
            }
            if(sum > max)
            {
                max = sum;
            }
        }

        return max;
    }
};


void run_test(std::vector<std::vector<int>>& accounts, int expected)
{
        int maxWealth;
        Solution s;
        maxWealth = s.maximumWealth(accounts);
        assert(maxWealth == expected);
}

void run_test_cases()
{
    {
        // Case 1
        std::vector<std::vector<int>> accounts { {1,2,3}, {3,2,1}};
        run_test(accounts, 6);
    }

    {
        // Case 2
        std::vector<std::vector<int>> accounts { {1,5}, {7,3}, {3, 5}};
        run_test(accounts, 10);
    }


    {
        // Case 3
        std::vector<std::vector<int>> accounts { {2,8,7}, {7,1,3}, {1,9,5}};
        run_test(accounts, 17);
    }
}




int main(void)
{
    run_test_cases();
    return 0;
}