class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minkpos = -1;
        int maxkpos = -1;
        int bad_index = -1;//position of element out of range

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK)
                bad_index = i;

            if (nums[i] == minK)
                minkpos = i;

            if (nums[i] == maxK)
                maxkpos = i;

            long long smaller = min(minkpos, maxkpos);//min element position
            long long temp = smaller - bad_index;//length of the subarray within the range
            ans += (temp <= 0) ? 0 : temp;//valid subarrays
        }
        return ans;
    }
};