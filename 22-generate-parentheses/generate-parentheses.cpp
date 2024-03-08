class Solution {
public:
    vector<string> generateParenthesis(int n) {
    vector<string> result;
    func(result,n,0,0,"");
    return result;
    }
    //base case
    void func(vector<string>&result,int n,int open,int close,string cur){
        if(cur.size()==n*2){
            result.push_back(cur);
            return;
        }
        if(open<n) {
            func(result,n,open+1,close,cur+"(");//add open parenthesis
        }
        if(close<open){
            func(result,n,open,close+1,cur+")");//add close parenthesis
        }
    }
};