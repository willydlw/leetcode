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
        int balanceCount = 0;
        int len = (int)s.length();

        // traverse string once from left to right 
        // Count left '(' paren and treat '*' as left
        // to ensure there are not too many closing parentheses 
        for(int i = 0; i < len; ++i)
        {
            // treat '*' as potentially a left
            if( s[i] != ')')
            {
                ++balanceCount;
            }  
            else if(balanceCount > 0)
            {  
                --balanceCount;
            }
            else // balance is 0, there are too many closing (right) parens
            {
                return false;
            }
        }


        // check in reverse order to ensure there are not too many left parens
        balanceCount = 0;
        for(int i = len-1; i >= 0; --i)
        {
            if( (s[i]) != '(')
            {
                ++balanceCount;
            }
            else  if(balanceCount > 0)
            {
                --balanceCount;
            }
            else 
            {   // too many left parens 
                return false;
            }
        }

        return true;
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

    {   // Example 1 - empty string
        std::string s = "";
        test(s, true, testNumber++);
    }

    {   // Example 2 - no parens
        std::string s = "*";    
        test(s, true, testNumber++);
    }

    {   // Example 3 - no parens
        std::string s = "******";    
        test(s, true, testNumber++);
    }

    {   // Example 4 - single left
        std::string s = "(";    
        test(s, false, testNumber++);
    }

    {   // Example 5 - single right
        std::string s = ")";    
        test(s, false, testNumber++);
    }

    {   // Example 6 - * cannot be treated as right
        std::string s = "*(";    
        test(s, false, testNumber++);
    }

    {   // Example 7 - * cannot be treated as left
        std::string s = ")*";    
        test(s, false, testNumber++);
    }

    {   // Example 8
        std::string s = "()";
        test(s, true, testNumber++);
    }

    {   // Example 9
        std::string s = "(*)";
        test(s, true, testNumber++);
    }

    {   // Example 10
        std::string s = "(*))";
        test(s, true, testNumber++);
    }

    {   // Example 11
        std::string s = "((*)";
        test(s, true, testNumber++);
    }

    {   // Example 12
        std::string s = "()*)";
        test(s, true, testNumber++);
    }

    {   // Example 13
        std::string s = ")(";
        // left does not come before the corresponding right
        test(s, false, testNumber++);
    }

    {   // Example 14
        std::string s = "(()))";
        // not enough left
        test(s, false, testNumber++);
    }

    {   // Example 15
        std::string s = "((())";
        // not enough right
        test(s, false, testNumber++);
    }

    {   // Example 16
        std::string s = "((*)***)";
        test(s, true, testNumber++);
    }
}


int main(void)
{
    runtests();
    return 0;
}