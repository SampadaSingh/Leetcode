class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int result=0;
        for(int i=0;i<nums.size();i++){
        int first=nums[i];
        int start=i+1;
        int end=nums.size()-1;
        while(start<end){
            int sum=first+nums[start]+nums[end];
            if(sum==target) return target;
           else if(abs(sum-target)<diff){
                diff=abs(sum-target);
                result=sum;
            }
          (sum>target)?end--:start++;
        }
    }    
    return result;
    }
};