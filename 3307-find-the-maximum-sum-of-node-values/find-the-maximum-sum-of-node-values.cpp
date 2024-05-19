class Solution {
public:
    typedef long long LL;

    long long maximumValueSum(vector<int>& nums, int k,vector<vector<int>>& edges) {
        int count = 0;
        int minLoss = INT_MAX;
        LL sum = 0;

        for (LL num : nums) {
            if ((num ^ k) > num) {
                count++;
                sum += (num ^ k);
            } else {
                sum += num;
            }

            minLoss = min((LL)minLoss, abs(num - (num ^ k)));

        }

        if (count % 2 == 0) {
            return sum;
        }

        return sum - minLoss;

    }
};