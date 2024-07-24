class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> pairs;

        for (int i = 0; i < nums.size(); i++) {
            string str = to_string(nums[i]);
            string res;

            for (char c : str) {
                res += to_string(mapping[c - '0']);
            }

            int mapped = stoi(res);
            pairs.push_back({mapped, i});
        }
        
        sort(pairs.begin(), pairs.end());
        vector<int> answer;
        for (auto& pair : pairs) {
            answer.push_back(nums[pair.second]);
        }

        return answer;
        
    }
};