class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();   // row
        int n = grid[0].size();   // col

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) { // flip row
                for (int j = 0; j < n; j++) {
                    grid[i][j] = 1 - grid[i][j]; //flip
                }
            }
        }

        for (int j = 1; j < n; j++) {
            int countZero = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 0) {
                    countZero++;
                }
            }

            int countOne = m - countZero;
            if (countZero > countOne) {
                for (int i = 0; i < m; i++) {
                    grid[i][j] = 1 - grid[i][j]; //flip
                }
            }
        }

        int score = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int value = grid[i][j] * pow(2, n - j - 1);
                score += value;
            }
        }
        return score;
    }
};