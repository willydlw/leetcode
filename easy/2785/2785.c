/*  Given a 0-indexed string s, permute s to get a new string t such that
    - All consonants remain in their original places. If there is an index
      i with 0<= i < s.length such that s[i] is a consonant, then t[i] = s[i]

    - The vowels must be sorted in nondecreasing order of their ASCII values. 
      For pairs os indices i, j with 0 <= i < j < s.length such that s[i] and
      s[j] are vowels, then t[i] must not have a higher ASCII value than t[j]

    Return the resulting string.

    The vowels are 'a', 'e', 'i' 'o', and 'u'. They can appear in lowercase
    or uppercase. Consonants comprise all letters that are not vowels.  
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_VOWELS 10
const char VOWELS[NUM_VOWELS] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

const bool isVowel[128] = {
    ['a'] = true, ['e'] = true, 
    ['i'] = true, ['o'] = true,
    ['u'] = true, ['A'] = true,
    ['E'] = true, ['I'] = true,
    ['O'] = true, ['U'] = true
    };

/*  1 <= s.length <= 10^5 

    s consists only of the letters of the English alphabet in uppercase and lowercase.
*/
char * sortVowels(char * s)
{
    int length = strlen(s);
    
    char* result = (char*)malloc((length+1) * sizeof(char));
    if(result == NULL)
    {
        return NULL;
    }

    int vowelFrequency[128] = {0};
    int vowelPositions[length];
    int totalVowels = 0;
    
    for(int i = 0, j = 0; i < length; ++i)
    {
        if(isVowel[(int)s[i]])
        {
            vowelFrequency[(int)s[i]] += 1;
            vowelPositions[j] = i;
            ++totalVowels;
            ++j;
        }
        else 
        {
            result[i] = s[i];
        }
    }

    for(int i = 0, j = 0; i < NUM_VOWELS && totalVowels > 0; ++i)
    {
        while(vowelFrequency[(int)VOWELS[i]] > 0)
        {
            result[vowelPositions[j]] = VOWELS[i];
            ++j;
            vowelFrequency[(int)VOWELS[i]] -= 1;
            --totalVowels;
        }
    }

    result[length] = '\0';
    return result;
}


int main(void)
{
    //char* test1 = "lYmpH";
    char* test2 = "lEetcOde";
    char* result;

    /*
    result = sortVowels(test1);
    printf("%s\n", result);
    free(result);
    */

    result = sortVowels(test2);
    printf("%s\n", result);
    free(result);
    return 0;
}