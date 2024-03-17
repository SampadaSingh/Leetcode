class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights; // A copy of heights
        sort(expected.begin(), expected.end());
        int count = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != expected[i])
                count++; // counting the no. of elements not in correct position
        }
        return count;
    }
};