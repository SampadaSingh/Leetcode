class Solution {
public:
    string longestPalindrome(string s) {
    if(s.length()<=1) return s;
    int start=0, end=0;
    int max=1;
    int n=s.length();
    //odd
    for(int i=0; i<n-1;++i){
        int l=i, r=i;
        while(l>=0 && r<n && s[l]==s[r]){
            l--;r++;
            }
        int len=r-l-1;
        if(len>max){
            max=len;
            start=l+1;
            end=r-1;
        }
    }
    //even
    for(int i=0; i<n-1; ++i){
    int l=i, r=i+1;
    while(l>=0 && r<n && s[l]==s[r]){
            l--;r++;
        }
    int len=r-l-1;
    if(len>max){
        max=len;
        start=l+1;
        end=r-1;
    }
    }
    return s.substr(start,end-start+1);
    }
};