class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int ans = 0;
        int i = 0;
        int j = 0;

        while (j < nums.size()) {
            map[nums[j]]++;

            while (i <= j && map[nums[j]] > k) {
                map[nums[i]]--;
                i++;
            }

            if (map[nums[j]] <= k) {
                ans = max(ans, j - i + 1);
            }
            j++;
        }
        return ans;
    }
};