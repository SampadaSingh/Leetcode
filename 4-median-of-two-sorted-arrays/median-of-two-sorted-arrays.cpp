class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 == 0 && n2 == 0) {
            return 0.0;
        } else {
           vector<int> merged;
           int i=0, j=0;
           while(i<n1 && j<n2){
               if(nums1[i]<=nums2[j]){
               merged.push_back(nums1[i]);
               i++;
           }else{
               merged.push_back(nums2[j]);
               j++;
           }}
            while(i<n1){
                merged.push_back(nums1[i]);
                i++;
            }
            while(j<n2){
                merged.push_back(nums2[j]);
                j++;
            }
        //calculation for median
        int x=n1+n2;
        if(x%2==0){
             int m1=merged[x/2-1];
             int m2=merged[x/2];
            return (m1+m2)/2.0;
        }else{
            return merged[x/2.0];
        } 
    }
    }
};