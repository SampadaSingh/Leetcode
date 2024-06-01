class Solution {
public:
    int scoreOfString(string s) {
        int n = s.length();
        int score = 0;
        int diff = 0;

        for (int i = 0; i < n - 1; i++) {
            diff = static_cast<int>(s[i]) - static_cast<int>(s[i + 1]);
            score += abs(diff);
        }
        return score;
    }
};