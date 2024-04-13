class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int maxArea = 0;
        vector<int> heights(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                // Update the height to count consecutive ones
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            // Calculate the max area for the current histogram (row)
            maxArea = max(maxArea, largestRectArea(heights));
        }

        return maxArea;
    }

    int largestRectArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0, i = 0;
        int n = heights.size();
        while (i <= n) {
            if (st.empty() || (i < n && heights[i] >= heights[st.top()])) {
                st.push(i++);
            } else {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
        }
        return maxArea;
    }
};