class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int> cost(n);

        for (int i = 0; i < n; ++i) {
            cost[i] = abs(s[i] - t[i]);
        }

        int maxLength = 0;
        int currentCost = 0;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            currentCost += cost[end];

            while (currentCost > maxCost) {
                currentCost -= cost[start];
                start++;
            }
            
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};