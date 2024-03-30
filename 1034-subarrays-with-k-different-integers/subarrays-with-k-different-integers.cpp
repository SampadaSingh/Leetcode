class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int i = 0, j = 0, ans = 0;

        while (j < nums.size()) {
            map[nums[j]]++;

            while (i <= j && map.size() > k) {
                map[nums[i]]--;
                if (map[nums[i]] == 0) {
                    map.erase(nums[i]);
                }
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = atMost(nums, k) - atMost(nums, k - 1);
        return ans;
    }
};