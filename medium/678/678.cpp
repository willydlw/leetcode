/* Valid Parenthesis String

    Given a string s containing only three types of characters: '(', ')' and '*', 
    return true if s is valid.

    The following rules define a valid string:

    - Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    - Any right parenthesis ')' must have a corresponding left parenthesis '('.
    - Left parenthesis '(' must go before the corresponding right parenthesis ')'.

    '*' could be treated as a single right parenthesis ')' or a single left 
    parenthesis '(' or an empty string "".
*/

#include <cassert>
#include <iostream>
#include <string>


class Solution{
public:
    bool checkValidString(std::string s)
    {

    }
};


void test(std::string s, bool expected, int testNumber)
{
    Solution sol;
    bool result = sol.checkValidString(s);
    std::cerr << "Test number: " << testNumber << "\n";
    assert(result == expected);
}

void runtests(void)
{
    int testNumber = 1;

    {   // Example 1
        std::string s = "()";
        test(s, true, testNumber++);
    }

    {   // Example 2
        std::string s = "(*)";
        test(s, true, testNumber++);
    }

    {   // Example 3
        std::string s = "(*))";
        test(s, true, testNumber++);
    }

    {   // Example 4
        std::string s = "((*)";
        test(s, true, testNumber++);
    }

    {   // Example 5
        std::string s = "()*)";
        test(s, true, testNumber++);
    }

    {   // Example 6
        std::string s = ")(";
        // left does not come before the corresponding right
        test(s, false, testNumber++);
    }

    {   // Example 7
        std::string s = "*(";
        // left does not come before the corresponding right
        test(s, false, testNumber++);
    }

    {   // Example 8
        std::string s = "(()))";
        // left does not come before the corresponding right
        test(s, false, testNumber++);
    }

    {   // Example 9
        std::string s = "((*)***)";
        // left does not come before the corresponding right
        test(s, true, testNumber++);
    }
}


int main(void)
{
    runtests();
    return 0;
}