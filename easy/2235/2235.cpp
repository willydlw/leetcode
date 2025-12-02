#include <cassert>

class Solution {
public:
    int sum(int num1, int num2) {
        return (num1 + num2);
    }
};


// constraints: -100 <= num1, num2 <= 100
void test(int num1, int num2, int expected)
{
    Solution s;
    int result = s.sum(num1, num2);
    assert(result == expected);
}

void runtests()
{
    test(12, 5, 17);
    test(-10, 4, -6);
    test(-100, 100, 0);
}


int main(void)
{
    runtests();
    return 0;
}