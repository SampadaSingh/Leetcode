class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int count = 0;
        vector<int> subset;
        backtrack(nums, k, 0, subset, count);
        return count - 1; // Exclude the empty subset
    }

    void backtrack(vector<int>& nums, int k, int index, vector<int>& subset, int& count) {
        count++;

        for (int i = index; i < nums.size(); i++) {
            bool isBeautiful = true;
            for (int num : subset) {
                if (abs(num - nums[i]) == k) {
                    isBeautiful = false;
                    break;
                }
            }

            if (isBeautiful) {
                subset.push_back(nums[i]);
                backtrack(nums, k, i + 1, subset, count);
                subset.pop_back();
            }
        }
    }
};
