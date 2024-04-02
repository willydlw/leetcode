#include <string>
#include <cassert>


class Solution {
public:

    // assumes both strings are same length
    bool compareStrings(const std::string& s, const std::string& goal, 
                    size_t sIndex, size_t gIndex)
    {
        size_t length = s.length();
        size_t loopCount = 0;
        while(loopCount < length)
        {
            if(s[sIndex] != goal[gIndex])
            {
                return false;
            }
            sIndex = (sIndex + 1) % length;
            gIndex = (gIndex + 1) % length;
            ++loopCount;
        }

        return true;
    }

    bool rotateString(std::string s, std::string goal) 
    {
        if(s.length() != goal.length())
        {
            return false;
        }

        // does the first character in goal occur in s?
        std::size_t goalIndex = s.find(s[0]);
        while(goalIndex != std::string::npos)
        {
            if(compareStrings(s, goal, 0, goalIndex))
            {
                return true;
            }
            goalIndex = goal.find(s[0], goalIndex+1);
        }

        return false;
    }
};


void test(std::string s, std::string goal, bool expected)
{
    bool result;
    Solution sol;
    result = sol.rotateString(s, goal);
    assert(result == expected);
}

void runtests(void)
{
    {   // Example 1
        std::string s = "abcde";
        std::string goal = "cdeab";
        test(s, goal, true);
    }

    {   // Example 2
        std::string s = "abcde";
        std::string goal = "abced";
        test(s, goal, false);
    }

    {   // unequal length strings
        std::string s = "abcd";
        std::string goal = "abc";
        test(s, goal, false);
    }

     {   // Example 3: multiple occurrences of same character
        std::string s = "adabc";
        std::string goal = "abcad";
        test(s, goal, true);
    }

}


int main(void)
{
    runtests();
    return 0;
}