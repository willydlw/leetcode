# 1018. Binary Prefix Divisible By 5 

### Problem Statement 

Given: a binary array nums (0-indexed).

Define x[i] as the number whose binary representation is the subarray nums[0..i] (from most significant bit to lease significant bit).

Example: If nums = [1,0,1], then x[0] = 1, x[1] = 2 (binary 10), and x[2] = 5 (binary 101).

Return an array of booleans answer where answer[i] is true if x[i] is divisible by 5.


### Examples 

**Example 1:** 

**Input:** nums = [0, 1, 1]
**Output:** [true, false, false]
**Explanation:** The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10. Only the first number is divisible by 5, so answer[0] is true.

**Example 2:** 

**Input:** nums = [1, 1, 1]
**Output:** [false, false, false]
**Explanation:** The input numbers in binary are 1, 11, 111; which are 1, 3, and 7 in base-10. None are divisible by 5.

### Constraints 

- 1 <= nums.length <= 10^5 
- nums[i] is either 0 or 1 


### C Solution Function Prototype 

Thinking I already knew how to solve this problem, my next step was looking at the C function prototype to confirm my understanding of the data provided and expected output.


```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize);
```

**Function Parameters** 

**Input:** nums - array containing 0's, 1's 

numsSize - number of elements in array nums 

**Output** 

returnSize - should contain the number of elements in the returned boolean array 

**Return** 

bool* - points to array of boolean values that has been dynamically allocated 


### Questions & Observations

1. What's the purpose of returnSize? Shouldn't it be the same as numsSize since there will be a true or false value for each array element? Yes, returnSize and numsSize should be the same unless the dynamic memory allocation for the returned array fails, then it will be zero.

2. How will the binary numbers be formed?
    -- num[0] is easy, it's just a single digit. Possible values: 0, 1
    -- num[1] is 2 digits: num[0] num[1]         Possible values: 00, 01, 10, 11
    -- num[2] is 3 digits: num[0] num[1] num[2]  Possible values: 000, 001, 010, 011, 100, 101, 110, 111 

    Let binary[i] be the binary number represented by the prefix of the array nums from index 0 to index i.
    Then 
        binary[0] = nums[0]
        binary[1] = nums[0] * 2 + nums[1] = binary[0] + nums[1]
        binary[2] = binary[1] + nums[2]

    When i > 0, binary[i] = binary[i-1] * 2 + nums[i]


3. How will we handle overflow? The constraint *1 <= nums.length <= 10^5* means we might have a number that contains 10^5 (100,000) one's. We don't have a numeric data type that can store such a large value. 

*Observation*: The only possible remainders when dividing a number by 5 are 0, 1, 2, 3, 4. 

*Intuition*: We only need to keep the remainder of the value mod 5 and then append the next bit to the binary string. 


## Algorithm 

Let nums be a 0-indexed array of length n, subject to constraint that nums contains only 0's or 1's.
Let value = 0
Let answer be an array of length n
for i in range (0, n-1):
    value = value * 2 + nums[i] 
    if value mod 5 equal 0:
        answer[i] = true
    else 
        answer[i] = false 
return answer

## C Solution 

[1018.c](1018.c)

### Complexity Analysis 

Let *n* be the length of *nums*. 

- Time complexity: *O(n)*.  
    -- Traverse the array once and compute the prefix as we loop.

- Space complexity: *O(1)*. 
    - In addition to the return value, the extra space used is constant.


### Leetcode Editorial Proof by Induction

Does checking whether remain[i] equals zero give the correct result?

When i = 0, since binary[0] = nums[0] < 5, we have remain[0] = binary[0], so remain[0] = binary[0] mod 5 holds.

When i > 0, assume that remain[i-1] = binary[i-1] mod 5 holds. 

Consider binary[i] mod 5 and remain[i]:

    binary[i] mod 5 = ((binary[i-1] * 2) + nums[i]) mod 5
                    = (binary[i-1] * 2) mod 5 + nums[i] mod 5 

    remain[i]       = (remain[i-1] * 2 + nums[i]) mod 5 
                    = ((binary[i-1] mod 5 * 2 + nums[i])) mod 5 
                    = (binary[i-1] mod 5 * 2) mod 5 + nums[i] mod 5 
                    = (binary[i-1] * 2) mod 5 + nums[i] mod 5 

Thus, remain[i] = binary[i] mod 5.

Therefore, for any 0 <= i < n, we have remain[i] = binary[i] mod 5, so computing remain[i] always yields the correct result.

