class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int row = grid.size();
        int col = grid[0].size();

        // mark visited cell
        grid[i][j] = '0';

        // up
        if (i - 1 >= 0 && grid[i - 1][j] == '1')
            dfs(grid, i - 1, j);
        // down
        if (i + 1 < row && grid[i + 1][j] == '1')
            dfs(grid, i + 1, j);
        // left
        if (j - 1 >= 0 && grid[i][j - 1] == '1')
            dfs(grid, i, j - 1);
        // right
        if (j + 1 < col && grid[i][j + 1] == '1')
            dfs(grid, i, j + 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int row = grid.size();
        int col = grid[0].size();
        int numIslands = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        return numIslands;
    }
};