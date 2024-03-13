class Solution {
public:
    int missingNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());//sorting in ascending order
    int curr=0;
    for(int i=0;i<nums.size();i++){
        if(curr!=nums[i]){
            return curr;
        }
        curr++;
        
    }   
        return curr;
    }
};