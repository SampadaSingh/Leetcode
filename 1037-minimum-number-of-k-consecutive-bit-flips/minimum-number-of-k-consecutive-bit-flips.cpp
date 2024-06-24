class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int currFlip = 0;
        int totalFlip = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i >= k && nums[i - k] == 2) {
                currFlip--;
            }
            if (currFlip % 2 == nums[i]) {
                if ((i + k) > nums.size()) {
                    return -1;
                }
                nums[i] = 2;
                currFlip++;
                totalFlip++;
            }
        }
        return totalFlip;
    }
};