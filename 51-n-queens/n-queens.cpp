class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));

        // board initialization
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = '.';
            }
        }

        // queen placement
        queen(ans, temp, n, 0);
        return ans;
    }

private:
    bool safe(int r, int c, const vector<string>& temp, int A) {
        //rows and columns
        for (int k = 0; k < A; k++) {
            if (temp[r][k] == 'Q' || temp[k][c] == 'Q')
                return false;
        }
        //diagonals
        for (int d = 1; d < A; d++) {
            if (inbound(r - d, c - d, A) && temp[r - d][c - d] == 'Q') return false;
            if (inbound(r - d, c + d, A) && temp[r - d][c + d] == 'Q') return false;
            if (inbound(r + d, c + d, A) && temp[r + d][c + d] == 'Q') return false;
            if (inbound(r + d, c - d, A) && temp[r + d][c - d] == 'Q') return false;
        }
        return true;
    }

    bool inbound(int i, int j, int A) {
        return i >= 0 && j >= 0 && i < A && j < A;
    }

    void queen(vector<vector<string>>& ans, vector<string>& temp, int n, int row) {
        if (row == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (safe(row, i, temp, n)) {
                temp[row][i] = 'Q';
                queen(ans, temp, n, row + 1);
                temp[row][i] = '.';
            }
        }
    }
};
