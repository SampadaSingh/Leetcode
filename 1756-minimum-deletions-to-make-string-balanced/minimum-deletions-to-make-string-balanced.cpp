class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        stack<char> stack;
        int del = 0;

        for (int i = 0; i < n; i++) {
            if (!stack.empty() && stack.top() == 'b' && s[i] == 'a') {
                stack.pop();
                del++;
            } else {
                stack.push(s[i]);
            }
        }
        return del;
    }
};