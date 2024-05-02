class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int result = -1;
        int i = 0;
        int j = nums.size() - 1;

        while (i < j) {
            if (-nums[i] == nums[j]) {
                return nums[j];
            }
            if (-nums[i] < nums[j]) {
                j--;
            } else {
                i++;
            }
        }
        return result;
    }
};