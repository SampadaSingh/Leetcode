class Solution {
public:
    unordered_set<string> set; //set dictionary words
    unordered_map<string, vector<string>> map; //memoization map for previously computed substring

    vector<string> solve(string &s) {
        if (s.empty()) {
            return {""};
        }

        if (map.count(s)) {
            return map[s];
        }

        vector<string> result;
        for (int i = 0; i < s.length(); i++) {
            string curr = s.substr(0, i+1);
            // Check if the current prefix exists in the set of dictionary words
            if (set.count(curr)) {
                string remainWord = s.substr(i+1);
                vector<string> remainResult = solve(remainWord);
                for (string& w : remainResult) {
                    string add = curr + (w.empty() ? "" : " ") + w;
                    result.push_back(add);
                }
            }
        }
        map[s] = result;// store result of curr substring in map to avoid recomputation
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string& word : wordDict) {
            set.insert(word);
        }
        return solve(s);
    }
};