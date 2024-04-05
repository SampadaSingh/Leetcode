class Solution {
public:
    string makeGood(string s) {
        if (s.length() <= 1)
           return s; 
        string ans = "";

        for (int i = 0; i < s.length(); ++i) {
            if (!ans.empty() && abs(ans.back() - s[i]) == 32) { //ASCII difference between characters
                ans.pop_back(); // Remove the last character from ans
            } else {
                ans.push_back(s[i]); // Add current character to ans
            }
        }
        return ans;
    }
};