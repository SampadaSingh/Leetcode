class Solution {
public:
    int m, n;

    int getPath(vector<vector<int>>& grid, int i, int j) {
        //grid bound or cell with no gold
        if (i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0) {
            return 0;
        }

        //original value of cell
        int originalValue = grid[i][j];
        grid[i][j] = 0;

        int maxGold = originalValue + max({
                                      getPath(grid, i - 1, j), // up
                                      getPath(grid, i + 1, j), // down
                                      getPath(grid, i, j - 1), // left
                                      getPath(grid, i, j + 1)  // right
                                    });

        grid[i][j] = originalValue; //restore the original value
        return maxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxGold = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, getPath(grid, i, j));
                }
            }
        }
        return maxGold;
    }
};