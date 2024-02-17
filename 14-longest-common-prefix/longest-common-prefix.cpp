class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    string result="";
    for(int i=0;i<strs[0].length();i++){
        for(int j=0;j<strs.size()-1;j++){
            if(strs[j][i]!=strs[j+1][i]) return result;
        }
        result+=strs[0][i];
    } 
    return result;  
    }
};