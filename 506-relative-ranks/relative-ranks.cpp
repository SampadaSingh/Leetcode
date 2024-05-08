class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector <string> result(n);
        unordered_map <int, int> map;

        for (int i = 0; i < n; i++) {
            map[score[i]] = i;
        }

        sort(score.begin(), score.end(), greater<int>()); // descending order

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                int ath = map[score[i]];
                result[ath] = "Gold Medal";
            } else if (i == 1) {
                int ath = map[score[i]];
                result[ath] = "Silver Medal";
            } else if (i == 2) {
                int ath = map[score[i]];
                result[ath] = "Bronze Medal";
            } else {
                int ath = map[score[i]];
                result[ath] = to_string(i + 1);
            }
        }
        return result;
    }
};