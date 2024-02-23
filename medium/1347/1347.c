#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/*  
    Constraints
        strings s, t are same length
        contain only lowercase letters
*/
int minSteps(char* s, char* t) 
{
    int letterCount[26] = {0};
    int n = strlen(s);
    int diff = 0;

    for(int i = 0; i < n; ++i)
    {
        letterCount[s[i]-'a']++;
        letterCount[t[i]-'a']--;
    }

    for(int i = 0; i < 26; ++i)
    {
        diff += abs(letterCount[i]);
    }
    return diff / 2;
}


void runTests(void)
{
    {
        char *s = "bab";
        char *t = "aba";
        int diff = minSteps(s, t);
        printf("%d\n", diff);
        //assert(diff == 2);
    }

    {
        char *s = "leetcode";
        char *t = "practice";
        int diff = minSteps(s, t);
        printf("%d\n", diff);
        //assert(diff == 5);
    }

    {
        char *s = "anagram";
        char *t = "mangaar";
        int diff = minSteps(s, t);
        printf("%d\n", diff);
        //assert(diff == 0);
    }
}

int main(void)
{
    runTests();
    return 0;
}