class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        bool match[m + 1][n + 1];
        // Initialize array
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                match[i][j] = false;
            }
        }
        match[0][0] = true; // Empty pattern matches empty string
        // Handling '*' at the beginning of pattern
        for(int j = 1; j <= n; j++) {
            if(p.at(j - 1) == '*') {
                match[0][j] = match[0][j - 1];
            }
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p.at(j - 1) == s.at(i - 1) || p.at(j - 1) == '?') {
                    match[i][j] = match[i - 1][j - 1];
                } else if(p.at(j - 1) == '*') {
                    match[i][j] = match[i][j - 1] || match[i - 1][j];
                }
            }
        }
        return match[m][n];
    }
};
