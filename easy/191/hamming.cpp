#include <iostream>
#include <cassert>

class Solution {
public:

    /*  Follow up: If this function is called many times, how would you optimize it?

        Precompute the answers and store them in an array (lookup table).
        Tradeoff between memory and speed of execution.

        Example: precompute the results for 8 bit values. 
        Requires an array of 256 elements;

        The function then breaks the 32 bit input into four groups of
        8 bits, looks up the number of 1's for each group and sums them.
    */
    
    // 4-bit grouping requires an array of size 16
    const int WEIGHTS[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};

    /*  Algorithm using precomputed weights

        Time Complexity: 
            O(8) where  32 bits / 4 bits/iteration  = 8 iterations worst case

        Space Complexity: Requires an array of size 16 
    */
    int hammingWeight3(uint32_t n) {
        int onesCount = 0;
        uint32_t bitmask = 0xf;
       
        while(n)
        {
            onesCount += WEIGHTS[n & bitmask];
            n = n >> 4;
        }

        return onesCount;
    }



    /*  Algorithm 

        Time Complexity: 
            O(K) where K is the number of bits that are 1's.
            Worst case O(N=32) when all 32 bits are 1's.
            This algorithm should perform better on average.

        Space Complexity: O(1) 
    */
    int hammingWeight2(uint32_t n) {
        int onesCount = 0;
        while(n)
        {
            onesCount += 1;

            // remove righmost 1 bit
            // n = 13,      binary 1101
            // n-1 = 12,    binary 1100
            // n & (n-1)           1100
            n = n & (n-1);
        }

        return onesCount;
    }

    /*  Naive Algorithm - each bit is tested
        Time Complexity: O(K) where K is the number of bits.
                         In this case 32 bits.

        Space Complexity: O(1) 
    */
    int hammingWeight1(uint32_t n) {
        int onesCount = 0;
        while(n)
        {
            if(n&1){
                onesCount += 1;
            }
            n >>= 1;
        }

        return onesCount;
    }
};


void testCase(uint32_t n, int expected)
{
    Solution s;
    int result;
    result = s.hammingWeight3(n);
    std::cerr << "n: " << n << ", expected: " << expected 
        << ", actual: " << result << "\n";
    assert(result == expected);
}

void runTests(void)
{   
   
    // Test 1
    uint32_t n = 11;    //0xB
    testCase(n, 3);

    // Test 2
    n = 128;    // Binary 1000 0000
    testCase(n, 1);

    // Test 3
    n = 0xFFFFFFFD;
    testCase(n, 31);

}

int main(void)
{
    runTests();
    return 0;
}