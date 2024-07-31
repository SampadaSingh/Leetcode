class Solution {
public:
    int n;
    int sw;
    vector<vector<int>> memo;

    int solve(vector<vector<int>>& books, int i, int remWidth, int maxHeight) {

        int keep = INT_MAX;
        int skip = INT_MAX;

        if (i >= n) {
            return maxHeight;
        }

        if (memo[i][remWidth] != -1) {
            return memo[i][remWidth];
        }

        int bookWidth = books[i][0];
        int bookHeight = books[i][1];

        // keep in same shelf
        if (bookWidth <= remWidth) {
            keep = solve(books, i + 1, remWidth - bookWidth, max(maxHeight, bookHeight));
        }

        // skip to next shelf
        skip = maxHeight + solve(books, i + 1, sw - bookWidth, bookHeight);

        return memo[i][remWidth] = min(keep, skip);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        sw = shelfWidth;
        memo = vector<vector<int>>(n, vector<int>(shelfWidth + 1, -1));
        int remWidth = shelfWidth;

        return solve(books, 0, remWidth, 0);
    }
};
