class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        unordered_map<int, string> map;
        vector<string> output(n);

        for (int i = 0; i < n; i++) {
            map[heights[i]] = names[i];
        }

        sort(heights.begin(), heights.end());

        for (int i = n - 1; i >= 0; i--) {
            output[n - i - 1] = map[heights[i]];
        }

        return output;
        
    }
};