class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stackIndex;
        stack<int> starIndex;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stackIndex.push(i);
            } else if (s[i] == '*') {
                starIndex.push(i);
            } else {
                if (!stackIndex.empty()) {
                    stackIndex.pop();
                } else if (!starIndex.empty()) {
                    starIndex.pop();
                } else {
                    return false;
                }
            }
        }
        
        while (!stackIndex.empty() && !starIndex.empty()) {
            // If the unmatched '(' index is after the unmatched '*' index
            if (stackIndex.top() > starIndex.top()) {
                return false;
            }
            stackIndex.pop();
            starIndex.pop();
        }
        // If there are no unmatched '(' left, the expression is valid
        return stackIndex.empty();
    }
};