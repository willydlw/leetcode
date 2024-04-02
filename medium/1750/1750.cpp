#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:

    // original solution
    #if 0
    int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;
        char current = s[left];

        while(left <  right)
        {
            if(s[left] != s[right])
            {
                return right - left + 1;
            }
            
            while(s[left] == current && left <= right)
            {
                ++left;
            }

            while(s[right] == current && right >= left)
            {
                --right;
            }

            current = s[left];
        }

        return right - left + 1;
    }

    #endif 

    // refactored by moving if test condition into loop test
        int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;
        char current = s[left];

        while(left <  right && s[left] == s[right])
        { 
            while(s[left] == current && left <= right)
            {
                ++left;
            }

            while(s[right] == current && right >= left)
            {
                --right;
            }

            current = s[left];
        }

        return right - left + 1;
    }

};


void test(std::string& str, int expected)
{
    std::cerr << "Testing string: " << str << "\n";
    Solution s;
    int result = s.minimumLength(str);
    std::cerr << "Expected: " << expected << ", actual: " << result << "\n";
    assert(result == expected);
}


void runTests(void)
{
    #if 1
    {   // can't remove any characters
        string s = "ca";
        int expected = 2;
        test(s,expected);
    }

    {   // can remove all characters
        string s = "cabaabac";
        int expected = 0;
        test(s,expected);
    }

    {   // string length 1, can remove all characters
        string s = "c";
        test(s,1);
    }

    {
        string s = "aabccabba";
        test(s,3);
    }
    #endif 
    {
        string s = "bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb";
        int expected = 1;
        test(s, expected);
    }
}


int main(void)
{
    runTests();
    return 0;
}