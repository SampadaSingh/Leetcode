class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     set<char>cset;
     int max=0,start=0,end=0;
        while(start<s.size()){
            auto it=cset.find(s[start]);
            if(it==cset.end()){
             if((start-end+1)>max){
                 max=start-end+1;
                 }
                 cset.insert(s[start]);
                 start++;
            }else{
            cset.erase(s[end]);
            end++;
            }  
        }
        return max;
    }
};