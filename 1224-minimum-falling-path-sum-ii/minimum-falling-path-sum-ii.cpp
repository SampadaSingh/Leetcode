class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> g(n, vector<int>(n, INT_MAX));

        // Initialize the last row of the table with values from the bottom row of the grid
        for (int col = 0; col < n; col++) {
            g[n - 1][col] = grid[n - 1][col];
        }

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int ans = INT_MAX;
                for (int nextCol = 0; nextCol < n; nextCol++) {
                    if (nextCol != col) {
                        ans = min(ans, g[row + 1][nextCol]);
                    }
                }
                g[row][col] = ans + grid[row][col];
            }
        }

        int result = INT_MAX;
        for (int col = 0; col < n; col++) {
            result = min(result, g[0][col]);
        }

        return result;
        
    }
};