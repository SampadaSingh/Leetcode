class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n; i += 2) {
            if (i + 1 < n && nums[i] == nums[i + 1]) {
                continue;
            } else {
                result.push_back(nums[i]);
                if (result.size() == 2) {
                    break;
                }
                i--;
            }
        }
        return result;
    }
};