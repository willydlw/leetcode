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