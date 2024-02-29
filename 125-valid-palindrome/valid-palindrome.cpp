class Solution {
public:
    bool isPalindrome(string s) {
    int n=s.length();
    if(n<=1)return true;
    int left=0,right=s.length()-1;
    while(left<right){
        //check if alphanumeric and within bounds
        while(left<right && !isalnum(s[left])) left++;
        while(left<right && !isalnum(s[right])) right--;
        if(left<right && tolower(s[left])!=tolower(s[right])) return false;
        right--;
        left++;
    }   
    return true;
    }
};