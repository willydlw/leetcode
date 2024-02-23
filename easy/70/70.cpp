#include <cassert>

/*  Problem 70 - Climbing Stairs (Easy)

    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb 1 or 2 steps. 
    In how many distinct ways can you climb to the top?

    Example 1:
        Input: n = 1
        Output: 1
    Explanation:
    There is one way to climb to the top.
    1. 1 step

    Example 2:
        Input: n = 2
        Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps
    
    
    Example 3:
        Input: n = 3
        Output: 3
    Explanation: There are three ways to climb to the top.
    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step

    Example 4:
        Input: n = 4
        Output: 5
    Explanation: There are five ways to climb to the top
    1. 1 step + 1 step + 1 step + 1 step
    2. 1 step + 1 step + 2 steps
    3. 1 step + 2 steps + 1 step
    4. 2 steps + 1 step + 1 step
    5. 2 steps + 2 steps

    Example 5:
        Input: n = 5
        Output: 8

    Explanation: There are eight ways to climb to the top
    1. 1 step + 1 step + 1 step + 1 step + 1 step
    2. 1 step + 1 step + 1 step + 2 steps
    3. 1 step + 1 step + 2 steps + 1 step
    4. 1 step + 2 step + 1 step + 1 step
    5. 2 steps + 1 step + 1 step + 1 step
    6. 2 steps + 2 steps + 1 step
    7. 2 steps + 1 step + 2 steps
    8. 1 step + 2 steps + 2 steps

    The solution appears to be a Fibonacci sequence

    n:      1   2   3   4   5
    ans:    1   2   3   5   8

*/


class Solution {
public:
    int climbStairs(int n) {
        // constraint: 1 <= n <= 45
        int a[46] = {0,1,2};
        for(int i = 3; i <= n; ++i)
        {
            a[i] = a[i-2] + a[i-1];
        }
        return a[n];
    }
};

void test(int n, int expected)
{
    Solution s;
    int ans = s.climbStairs(n);
    assert(expected == ans);
}

void runTests(void)
{
    test(1,1);
    test(2,2);
    test(3,3);
    test(4,5);
    test(5,8);
}

int main(void)
{
    runTests();
    return 0;
}