class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        part(s, 0, curr, result);
        return result;
    }

    void part(string& s, int index, vector<string> curr, vector<vector<string>>& result) {
        int n = s.size();
        if (index == n) {
            result.push_back(curr);
            return;
        }

        for (int i = index; i < n; ++i) {
            if (isPalindrome(s, index, i)) {
                curr.push_back(s.substr(index,i-index+1));
                part(s, i + 1, curr, result);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};