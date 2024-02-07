class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;

     vector<string> rows(min(numRows,int(s.size())));
     int curr=0;
     bool last=false;
     for (char c:s){
         rows[curr]+=c;
         if(curr==0 || curr==numRows-1)last=!last;
         curr+=last?1:-1;
     }
     string result;
     for(string row:rows){
         result+=row;
     }
     return result;
    }
};