/*
    Anti-theft security devices are activated inside a bank. You are given a 0-indexed 
    binary string array bank representing the floor plan of the bank, which is 
    an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. 
    '0' means the cell is empty, while'1' means the cell has a security device.


    There is one laser beam between any two security devices if both conditions are met:

    - The two devices are located on two different rows: r1 and r2, where r1 < r2.
    - For each row i where r1 < i < r2, there are no security devices in the ith row.
    - Laser beams are independent, i.e., one beam does not interfere nor join with another.

    Return the total number of laser beams in the bank.

    Constraints:
        m == bank.length
        n == bank[i].length
        1 <= m, n <= 500
        bank[i][j] is either '0' or '1'.
*/

#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int numberOfBeams(std::vector<std::string>& bank) {
        int totalBeams = 0;

        int row = 0;
        int endRow = bank.size();
        int numFrom = 0;
        int numTo = 0;

        while(row < endRow)
        {
            // find first row with devices
            while(numFrom <= 0 && row < endRow)
            {
                numFrom = countDevices(bank[row]);
                ++row;
            }

            // find second row with devices
            while(numTo <= 0 && row < endRow)
            {
                numTo = countDevices(bank[row]);
                ++row;
            }

            totalBeams += numTo * numFrom;
            numFrom = numTo;
            numTo = 0; 
        }

        return totalBeams;
    }

    int countDevices(const std::string& row)
    {
        int total = 0;
        for(auto c : row )
        {
            if (c == '1')
            {
                ++total;
            }
        }

        return total;
    }
};

void runTests(void)
{
    {
        Solution s;
        std::vector<std::string> bank {"011001","000000","010100","001000"};
        int ans;
        ans = s.numberOfBeams(bank);
        std::cerr << "ans: " << ans << "\n";
        assert(ans == 8);
    }

    {
        Solution s;
        std::vector<std::string> bank {"000","111","000"};
        int ans;
        ans = s.numberOfBeams(bank);
        std::cerr << "ans: " << ans << "\n";
        assert(ans == 0);
    }
}


int main(void)
{
    runTests();
    return 0;
}