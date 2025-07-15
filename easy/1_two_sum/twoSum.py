class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}    # empty dictionary
        for i, num in enumerate(nums):
            diff = target - num
            if diff in hashmap:
                return [i, hashmap[diff]]
            hashmap[num] = i 
        
        return []
