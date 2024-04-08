#include <string>
#include <cassert>
#include <iostream>

class Solution {
public:
    std::string makeGood(std::string s) 
    {
        std::size_t left = 0;
        std::size_t right = 1;
        std::size_t len = s.length();

        while(right < len)
        {
            // same letter:     (tolower(left) == tolower(right))       
            // different case:  ((int)left ^ (int)right) == 0x20
            if( (tolower(s[left]) == tolower(s[right])) && (((int)s[left] ^ (int)s[right]) == 0x20))
            {
                // don't include these two letters in the answer
                s.erase(left, 2);        
                len = s.length();

                // Exmample: s = "abBA"
                // when left is 1, right is 2, "bB" is removed from the string
                // need to next check "aA" where left is 0, right is 1
                if(left > 0)
                {
                    --left;
                    --right;
                }
            }
            else 
            {   
                    // not same letter OR (same letter, same case)
                    ++left;
                    ++right;
            }
        }

        return s;
    }
};


void test(std::string s, std::string expected)
{
    Solution sol;
    std::string ans;
    ans = sol.makeGood(s);
    //std::cerr << "s: " << s << ", ans: " << ans << ", expected: " << expected << "\n";
    assert(ans == expected);
}

void runtests(void)
{
    {
        std::string s = "leEeetcode";
        std::string expected = "leetcode";
        test(s, expected);
    }

    {
        std::string s = "abBAcC";
        std::string expected = "";
        test(s, expected);
    }

    {
        std::string s = "AabBc";
        std::string expected = "c";
        test(s, expected);
    }

        {
        std::string s = "CcABba";
        std::string expected = "";
        test(s, expected);
    }

    {
        std::string s = "s";
        std::string expected = "s";
        test(s, expected);
    }

    {
        std::string s = "";
        std::string expected = "";
        test(s, expected);
    }

    {
        std::string s = "abABcd";
        std::string expected = "abABcd";
        test(s, expected);
    }
}


int main(void)
{
    runtests();
    return 0;
}