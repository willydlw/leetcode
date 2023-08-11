#include <stdio.h>
#include <stdint.h>



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
int hammingWeight(uint32_t n){
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

void generateHeaderFile(const char* filename, int n)
{
    int i, perLine;

    FILE* fptr; 
    fptr = fopen(filename, "w");
    if(fptr == NULL) perror("Error opeing file");
    
    fprintf(fptr, "#ifndef WEIGHTS_H\n");
    fprintf(fptr, "#define WEIGHTS_H\n");
    fprintf(fptr, "const int HAMMING_WEIGHT[%d] = { ", n);

    for(i = 0, perLine = 0; i < (n-1); ++i, ++perLine)
    {
        if((perLine % 16) == 0)
        {
            fprintf(fptr, "\n");
        }

        fprintf(fptr, "%d, ", hammingWeight(i));
    }

    fprintf(fptr, "%d };\n\n", hammingWeight(i));
    fprintf(fptr, "#endif\n");

    fclose(fptr);
}

int main(void)
{
    const char* filename = "weights.h";
    generateHeaderFile(filename, 256);
    return 0;
}