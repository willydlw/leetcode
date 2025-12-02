#include <stdlib.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    bool* result = (bool*)malloc(numsSize * sizeof(bool));
    if(result == NULL){
        *returnSize = 0;
        return NULL;
    }

    int value = 0;
    for(int i = 0; i < numsSize; i++){
        value = ((value << 1) | nums[i]) % 5;
        if(value == 0){
            result[i] = true;
        }
        else{
            result[i] = false;
        }
    }

    *returnSize = numsSize;
    return result;
}

