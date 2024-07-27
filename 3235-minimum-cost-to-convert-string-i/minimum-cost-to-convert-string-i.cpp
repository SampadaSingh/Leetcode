class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,vector<char>& changed, vector<int>& cost) {

        vector<vector<long long>> minCost(26, vector<long long>(26, INT_MAX));
        long long ans = 0;

        for (int i = 0; i < original.size(); ++i) {
            int o = original[i] - 'a';
            int c = changed[i] - 'a';
            minCost[o][c] = min(minCost[o][c], (long long)cost[i]);
        }

        // Using Floyd Warshall
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                }
            }
        }

        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) {
                continue;
            }

            if (minCost[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
                return -1;
            }
            ans += minCost[source[i] - 'a'][target[i] - 'a'];
        }

        return ans;
    }
};