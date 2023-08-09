/*  Write a function that takes an unsigned integer and returns
    the number of '1' bits it has (also known as the Hamming weight);

    Constraints: input must be a binary string of length 32.

    Comment: word string is misleading. Data type given to the
    function parameter is uint32_t. I would rephrase "binary string"
    to 32 bit integer type.
*/

#include <stdio.h>
#include <stdint.h>
#include <assert.h>

/* Method 1a: Test each bit

   Time Complexity O(k) where k is the bit size for the data time.
        uint32_t has 32 bits, time complexity O(32)
*/

int hammingWeight1a(uint32_t n)
{
    int count = 0;
       
    for(int i = 0; i < 32; ++i)
    {
        int bitMask = 1 << i;
        if((n & bitMask) != 0)
        { 
            count = count + 1;
        }
    }
    return count;
}



/*  Method 1a: Brute Force using division and modulus operators

        Let n = input value
        While n is greater than zero
            Calculate the remainder of n divided by 2. 
            If the remainder is one
                add one to count.
            Let n = n / 2
        Return count 

    Worst case time Complexity 0(k) where k is the number of bits 
    in the data type size.

    Example: O(32) when leftmost bit is a 1 in a 32 bit number.
*/

int hammingWeight1a(uint32_t n)
{
    int count = 0;
    while(n > 0)
    {
        if( (n%2) == 1 )
        {
            count += 1;
        }

        n = n / 2;
    }
    return count;
}

/*  Method 1: Brute force using bit shifing and bitwise logical operations.

        Let n = input value
        While n is greater than zero
            Calculate the remainder of n divided by 2. 
            If the remainder is one
                add one to count.
            Let n = n / 2 
        Return count 

    Worst case Time Complexity 0(k) where k is the number of bits 
    in the data type size.
*/
int hammingWeight1b(uint32_t n)
{
    int count = 0;
    while(n){
        count += n & 0x1;
        n >>= 1;            
    }
    return count;
}


/* Method 2: Remove lowest set bit of n

    Example 1: 
        n = 0xF;        1111
        n - 1 = 0xE;    1110
                        -----
        n & (n-1):      1110

        n = 0x18;       0001 1000
        n - 1 = 0x17    0001 0111
                        ---------
        n & (n-1):      0001 0000

    
    Time complexity is O(k) where k are the
    number of bits set to 1.
    
    Worst case time complexity is O(n) where n are the
    number of bits in the data type size.

    Best case is O(1)
*/
int hammingWeight2(uint32_t n){
    int count = 0;

    while(n){
        // increment count by 1 because n must contain
        // at least one bit of value 1
        ++count;

        // remove the lowest power one bit
        n  &= (n-1);
    }

    return count;
}


/* Follow up question: 
    If this function is called many times, how would you optimize it?

   Answer: precompute hamming weights and store them in an array.

   See file precompute.c for an example that generates a header file
   containing an array of precomputed Hamming weights.

   Here, we use a global constant array to store the one's bit count
   of values 0 - 255. 

   This solution adds space complexity for the memory required to
   store the precomputed values.
    
*/


int weights[256];

void preComputeHammingWeight(int len)
{
    for(int i = 0; i < len; ++i){
        weights[i] = hammingWeight2(i);
    }
}

/*  Use the precomputed array of one's count for the 8 bit values
    0 - 255;

    The time complexity is constant O(4) as it requires four lookups
    for 32 bits (32/8 = 4)
*/
int hammingWeight3(uint32_t n)
{
    const int shift = 8;
    const uint32_t mask = 0xFF;
    int count = 0;

    while(n){
        count += weights[n & mask];
        n >>= shift;
    }
    return count;
}


int main(void){
    uint32_t test[6] = {0x0, 0x01, 0xB, 0x1111, 0xEFFF, 0xFFFF};
    int count;

    printf("\n*** Method 2 ***\n");
    printf("%8s  %8s\n", "n", "count");
    for(int i = 0; i < 6; ++i){
        count = hammingWeight2(test[i]);
        printf("%#8x %8d\n", test[i], count);
    }

    /*  Answer to follow up question. For convenience sake, we will 
        compute the Hamming Weights for 8-bit values: 0 - 255 and store
        them in a global array.

        The more efficient solution is found in precompute.c which 
        generates an array with all the values initialized.
    */
   
   printf("\n*** Method 3 ***\n");
   printf("%8s  %8s\n", "n", "count");
   preComputeHammingWeight(256);
   for(int i = 0; i < 6; ++i){
        count = hammingWeight3(test[i]);
        printf("%#8x %8d\n", test[i], count);
    }

    printf("\n*** Testing Largest Value ***\n");
    printf("%#8x %8d\n", 0xFFFFFFFF, hammingWeight3(0xFFFFFFFF));
    

    return 0;
}