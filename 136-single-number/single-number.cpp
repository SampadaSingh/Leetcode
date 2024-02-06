class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int n=nums.size();
    int result=0;
    int i=0;
        for( i=0; i<nums.size();++i){
            result^=nums[i];
        }
    return result;
    }
};