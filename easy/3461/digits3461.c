/* 3461. Check if Digits are Equal in String after Operations I 

   Time Complexity O(n^2)
   Space Complexity O(1)

   Note: This is my original solution. I did not read the problem
   carefully to understand that only the final two digits were 
   to be compared for equality. I misunderstood, thinking that 
   all digits needed to be compared and stop if that were true.

*/



// refactored solution
#include <string.h>

bool hasSameDigits(char* s) {
    size_t n = strlen(s);
    size_t stop = n;
    int digits[n];

    // convert char to int digits
    for(size_t i = 0; i < n; i++){
        digits[i] = s[i] - '0';
    }

    // repeatedly sum digit pairs
    while(stop > 2){
        for(size_t i = 1; i < stop; i++){
            digits[i-1] = (digits[i-1] + digits[i]) % 10;
        }
        stop--;
    }

    return (digits[0] == digits[1]);
}


#if 0
// original solution
#include <string.h>

void reduceString(char * s, int n)
{
    static const int CHAR_TO_INT = 2 * '0';
    for(size_t i = 1; i < n; i++){
        int sum = (int)s[i-1] + (int)s[i] - CHAR_TO_INT; 
        s[i-1] = (char)(sum % 10);
    }
    s[n-1] = '\0';
}

bool checkDigits(char* s, size_t n){
    for(int i = 1; i < n; i++){
        if(s[i-1] != s[i]){
            return false;
        }
    }
    return true;
}

bool hasSameDigits(char* s) {
    bool result = false;
    size_t n = strlen(s);
    while(n >= 2 && !(result = checkDigits(s,n)))
    {
        reduceString(s, n);
        n--;
    }
    return result;
}

#endif 