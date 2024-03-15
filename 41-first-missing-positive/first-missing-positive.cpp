class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    int n=nums.size();
    for(int i=0;i<nums.size();i++){
        int element=nums[i];
        while(element>0 && element<=n && nums[element-1]!=element) {
            swap(nums[element - 1], element);
            }
    }  
      for(int i=0;i<nums.size();i++){
            if(i+1!=nums[i])
            return i+1;
        }
    return n+1;
    }
};