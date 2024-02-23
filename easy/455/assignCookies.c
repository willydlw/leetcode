/*  Leetcode Easy Number 455

    Assume you are an awesome parent and want to give your children some cookies. 
    But, you should give each child at most one cookie.
    
    Each child i has a greed factor g[i], which is the minimum size of a cookie 
    that the child will be content with; and each cookie j has a size s[j]. 
    
    If s[j] >= g[i], we can assign the cookie j to the child i, and the child i 
    will be content. 
    
    Your goal is to maximize the number of your content children and output 
    the maximum number.

    Constraints:

    1 <= g.length <= 3 * 10^4
    0 <= s.length <= 3 * 10^4
    1 <= g[i], s[j] <= 2^31 - 1
*/


#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    // sort both sets into ascending order
    qsort(g, gSize, sizeof(int), cmpfunc);
    qsort(s, sSize, sizeof(int), cmpfunc);

    int count = 0;
    int i = 0;

    // Start by comparing the smallest size cookie to the least greedy child.
    while(i < sSize && count < gSize)
    {
        // if this size cookie is large enough for this child, increment count
        if(s[i] >= g[count])
        {
            ++count;
        }

        ++i;        
    }

    return count;
}

void test(void)
{
    int testNumber = 0;

    {
        int g[3] = {1,2,3};
        int s[2] = {1,1};
        int ans;
        ans = findContentChildren(g,3,s,2);
        fprintf(stdout, "test %d, ans: %d\n", testNumber, ans);
        ++testNumber;
    }
    {
        int g[2] = {1,2};
        int s[3] = {1,2,3};
        int ans;
        ans = findContentChildren(g,2,s,3);
        fprintf(stdout, "test %d, ans: %d\n", testNumber, ans);
        ++testNumber;
    }

    {
        int g[4] = {10, 9, 8, 7};
        int s[4] = {5, 6, 7, 8};
        int ans;
        ans = findContentChildren(g,4,s,4);
        fprintf(stdout, "test %d, ans: %d\n", testNumber, ans);
        ++testNumber;
    }


}

int main(void)
{
    test();
    return 0;
}