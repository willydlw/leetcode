#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    // order and s consist of lowercase English letters
    // all characters of order are unique 
    string customSortString(string order, string s) 
    {
        string answer;

        // count occurrences of characters in s 
        // 1 <= order.length <= 26
        int frequencyCount[26] = {0};
        for(auto c : s)
        {   
            frequencyCount[c - 'a'] += 1;
        }

        // iterate through order, if the character occurs in s
        // append it to the answer and reduce its count
        for(auto c : order)
        {
            while(frequencyCount[c-'a'] > 0)
            {
                answer += c;                
                frequencyCount[c-'a'] -= 1;
            }
        }

        // append any characters in s that were not in order 
        for(int i = 0; i < 26; ++i)
        {
            while(frequencyCount[i] > 0)
            {
                answer += (i + 'a');
                frequencyCount[i] -= 1;
            }
        }

        return answer;
    }
};


void test(string order, string s, string expected)
{
    std::string result;
    Solution sol;
    result = sol.customSortString(order, s);
    assert(result == expected);
}

void runtests(void)
{
    {
        // Example 1
        string order = "cba";
        string s = "abcd";
        string expected = "cbad";;
        test(order, s, expected);
    }

    {
        // Example 2
        string order = "bcafg";
        string s = "abcd";
        string expected = "bcad";
        test(order, s, expected);
    }
}

int main(void)
{
    runtests();
    return 0;
}
