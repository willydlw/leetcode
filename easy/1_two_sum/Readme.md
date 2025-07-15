# 1. Two Sum 

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1

Input: nums = [2, 7, 11, 15], target = 9 
Output: [0,1]
Explanation: nums[0] + nums[1] == 9, return indices [0, 1]

Example 2

Input: nums = [3,2,4], target = 6
Output: [1,2]
Explanation: nums[1] + nums[2] == target 6, return indices [1,2]


Constraints 

- 2 <= nums.length <= 10^4
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9 


## Possible Solutions 

### Brute Force 

Starting with the first array element, loop the remaining array elements to see if the sum equals the target. If 

Pseudocode:

let n = number of elements in array num
let i = 0 
while i is less than n
    let j = i + 1 
    while j < n
        let sum = nums[i] + nums[j]
        if sum equals target
            return i, j
        else 
            j = j + 1
    i = i + 1 

Because the problem statement guarantees there is one solution, the code should return the answer before i equals n and j equals n (meaning all possible sums have been checked).

Time Complexity - Worst case O(n^2) where the values num[n-1] + num[n-2] equal target, requiring the nested loop to execute (n-1)*(n-2) times. 

Space Complexity - O(1). Only requires memory for indexing variables, sum, and the answer 


### C Brute Force Solution

This solution was accepted. It passed all test cases and did not time out. Now we attempt the challenge of improving the solution to run in O(n) time.

```c
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* answer = (int*)malloc(2 * sizeof(int));
    if(answer == NULL){
        *returnSize = 0;
        return NULL;
    }

    for(int i = 0; i < numsSize; i++){
        for(int j = i+1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                answer[0] = i;
                answer[1] = j;
                *returnSize = 2;
                return answer;
            }
        }
    }

    *returnSize = 0;
    return answer;
}
```

### Follow-up: Can you come up with an algorithm that is less than the O(n^2) time complexity?

#### Hash table (hash map) solution

A hash table is a data structure that stores data in key-value pairs, allowing for fast retrieval of values based on their associated key. A hash function is used to map keys to specific locations (indices) within an underlying array, enabling direct access to the corresponding value.

let hashmap
let n = number of elements in nums array
let i = 0
while i < n
    diff = target - nums[i]
    if hashmap[diff] in hashmap:
        key = hashmap[diff].value
        answer = i, key 
        return answer 
    else store this in hashmap
        key = nums[i]
        value = i 
        hashmap[key] = value 

if here return no answer found


##### cpp hashmap solution using unordered_map 

The runtime is much faster than the brute force solution. More memory is re

Time complexity: worst case is O(n)
Space complexity: worst case is O(n) when hash map has to store (n-1) array elements 

```c++
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        std::unordered_map<int,size_t> hashmap;
        for(size_t i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            // is diff in hashmap?
            auto it = hashmap.find(diff);
            if(it != hashmap.end()){
                std::vector<int> answer(2);
                answer[0] = i;
                answer[1] = it->second;
                return answer;
            }
            else{
                hashmap[nums[i]] = i;
            }
        }

        return {};      // return empty vector
    }
};
```


My cpp code can be simplified as shown below. 

```cpp
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> hashmap;
        for(int i = 0; i < (int)nums.size(); i++){
            int diff = target - nums[i];
            // is diff in hashmap?
            if(hashmap.find(diff) != hashmap.end()){
                return {i, hashmap[diff]};
            }
            hashmap[nums[i]] = i;
        }
        return {};      // return empty vector
    }
};
```


```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}    # empty dictionary
        for i, num in enumerate(nums):
            diff = target - num
            if diff in hashmap:
                return [i, hashmap[diff]]
            hashmap[num] = i 
        
        return []
```