class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int subsetCount = pow(2, n);

        vector<vector<int>> subsets;

        for (int i = 0; i < subsetCount; i++) {
            int XOR = 0; //subset XOR
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    XOR ^= nums[j];
                }
            }
            sum += XOR;
        }

        return sum;

    }
};