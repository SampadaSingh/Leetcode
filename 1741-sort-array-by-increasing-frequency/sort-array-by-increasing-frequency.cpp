class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq;

        for(int num: nums){
            freq[num]++;
        }

        sort(nums.begin(), nums.end(), [&] (int a, int b){
        if(freq[a]==freq[b]){
            return a>b;
        }
        return freq[a]< freq[b];
        });

        return nums;
        
    }
};