class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        int odd = 0;
        unordered_map<char, int> map;

        for (char& ch : s) {
            map[ch]++;
            
            if (map[ch] % 2 != 0) {
                odd++;
            } else {
                odd--;
            }
        }

        if (odd > 0) {
            return n - odd + 1;
        }
        return n;
    }
};