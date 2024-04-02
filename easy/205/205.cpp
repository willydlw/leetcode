#include <map>
#include <string>
#include <cassert>

class Solution {
public:
    #if 0
    bool isIsomorphic(std::string s, std::string t) {
        std::map<char,char> imap;

        // constraint t.length == s.length
        // so not coding if s.length() != t.length() return false
        std::size_t len = s.length();
        for(std::size_t i = 0; i < len; ++i)
        {
            // has this character been mapped?
            if(imap.find(s[i]) != imap.end())
            {
                // yes, is it mapped to the same character
                if(imap[s[i]] != t[i])
                    return false;
            }
            else // character has not been mapped
            {
                imap[s[i]] = t[i];
            }
        } 

        return true;
    }
    #endif 

    void initArray(int* arr, int len, int val)
    {
        for(int i = 0; i < len; ++i)
        {
            arr[i] = val;
        }
    }

    bool isIsomorphic(std::string s, std::string t) 
    {
        #define ASCII_RANGE 256
        #define INVALID_ASCII -1

        int stable[ASCII_RANGE];
        int ttable[ASCII_RANGE];

        // initialize to -1 which is not a valid ascii integer value
        initArray(stable, ASCII_RANGE, INVALID_ASCII);
        initArray(ttable, ASCII_RANGE, INVALID_ASCII);

        // constraint t.length == s.length
        // so not coding if s.length() != t.length() return false
        std::size_t len = s.length();
        for(std::size_t i = 0; i < len; ++i)
        {
            // has this s character been mapped to a t character?
            if( stable[(int)s[i]] != INVALID_ASCII)
            {
                // yes, is it mapped to the same character in t
                if(stable[(int)s[i]] != (int)t[i])
                    return false;
            }
            else // s character has not been mapped
            {
                // has the t character already been mapped to an s character?
                // Example: s is "babc" , t is "baba"
                //      The a in s maps to a in t 
                //      The c in s maps to a in t. 
                //      Cannot not have two different characters in s map to 
                //      same character in t
                if(ttable[(int)t[i]] != INVALID_ASCII){
                    return false;
                }
                else{
                    stable[(int)s[i]] = (int)t[i];
                    ttable[(int)t[i]] = (int)s[i];
                }
            }
        } 

        return true;
    }
};


void test(std::string s, std::string t, bool expected)
{
    Solution sol;
    bool result = sol.isIsomorphic(s, t);
    assert(result == expected);
}

void runtests(void)
{
    #if 1
    {
        std::string s("egg");
        std::string t("add");
        test(s, t, true);
    }

    {
        std::string s("foo");
        std::string t("bar");
        test(s, t, false);
    }

    {
        std::string s("paper");
        std::string t("title");
        test(s, t, true);
    }

    #endif

    #if 1
    {
        std::string s("badc");
        std::string t("baba");
        test(s, t, false);
    }
    #endif
}

int main(void)
{
    runtests();
    return 0;
}