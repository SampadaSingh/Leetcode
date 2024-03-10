class Solution {
public:
    bool isValid(string s) {
    stack<char>stack;//create a stack to store opening brackets
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            stack.push(s[i]);//push opening bracket onto stack
        }else{
            if(stack.empty()){
            return false;
        }
        char c=stack.top();
        stack.pop();
        if((s[i]==')'&& c!='(')||
          (s[i]=='}'&& c!='{')||
          (s[i]==']'&& c!='['))
        return false; // If mismatched brackets found, return false
    }
    }
        return stack.empty();//if all opening brackets are matched,stack becomes empty
    }
};