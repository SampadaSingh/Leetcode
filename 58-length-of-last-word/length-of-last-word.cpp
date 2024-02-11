class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        bool lastword=false;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' '){
            if(lastword){
                break;
           } }else{
                lastword=true;
                count++;
            }
        }
        return count;
    }
};