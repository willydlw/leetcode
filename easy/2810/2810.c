#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * reverse(char * s)
{
    int left, right;
    char temp;

    for(left = 0, right = strlen(s)-1; left < right; ++left, --right)
    {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
    }

    return s;
}

/* Constraints
    s consists of lowercase English letters
    s[0] != 'i'
    1 <= s.length <= 100
*/
char * finalString(char * s)
{
    int readIndex;
    int writeIndex;
    int slen = strlen(s);
    char *ans = (char*)malloc( (slen + 1) * sizeof(char));
    if(ans == NULL)
    {
        return NULL;
    }
    
    for(readIndex = 0, writeIndex = 0; readIndex < slen; ++readIndex)
    {
        if(s[readIndex] != 'i')
        {
            ans[writeIndex] = s[readIndex];
            ++writeIndex;
        }
        else
        {
            ans[writeIndex] = '\0';
            reverse(ans);
        }
    }

    ans[writeIndex] = '\0';
    return ans;
}

void test(char * s)
{
    char *a;
    a = finalString(s);
    printf("s: %s, a: %s\n", s, a);
    free(a);
}


void run_tests(void)
{
    {
        char *s = "string";
        test(s);
    }

    {
        char *s = "poiinter";
        test(s);
    }
}


int main(void)
{
    run_tests();
    return 0;
}