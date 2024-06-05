class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common_count(26, INT_MAX);

        for (const string& word : words) {
            vector<int> word_count(26, 0);
            for (char c : word) {
                word_count[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                common_count[i] = min(common_count[i], word_count[i]);
            }
        }

        vector<string> result;
        for (int i = 0; i < 26; ++i) {
            while (common_count[i] > 0) {
                result.push_back(string(1, i + 'a'));
                common_count[i]--;
            }
        }
        return result;
    }
};