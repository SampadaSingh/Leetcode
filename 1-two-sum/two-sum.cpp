class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (index.find(complement) != index.end()) {
                return vector<int>{index[complement], i};
            }
            index[nums[i]] = i;
        }
        return vector<int>{};
    }
};