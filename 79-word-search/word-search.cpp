class Solution {
public:
    bool search(vector<vector<char>>& board, string word, int i, int j, int row, int col, int k) {

        if (k >= word.size())
            return true;
        if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] == '.' || word[k] != board[i][j])
            return false; // checking if the cell is out of bound
        if (word.size() == 1 && word[k] == board[i][j])
            return true;

        board[i][j] = '.'; // mark as visited
        bool temp = false;
        int x[4] = {1, 0, -1, 0}; // x coordinates
        int y[4] = {0, 1, 0, -1}; // y coordinates

        // checking neighbouring cells
        for (int index = 0; index < 4; index++) {
            temp = temp || search(board, word, i + x[index], j + y[index], row, col, k + 1);
        }
        board[i][j] = word[k]; // reset to current cell
        return temp;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if (row == 0)
            return false;
        int col = board[0].size();
        if (word.size() == 0)
            return false;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (word[0] == board[i][j]) {
                    if (search(board, word, i, j, row, col, 0))
                        return true;
                }
            }
        }
        return false;
    }
};