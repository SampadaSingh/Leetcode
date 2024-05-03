class Solution {
public:
    vector<int> splitVersion(string version) {
        vector<int> result;
        istringstream iss(version);
        string token;
        
        while (getline(iss, token, '.')) {
            result.push_back(stoi(token));
        }
        return result;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1 = splitVersion(version1);
        vector<int> v2 = splitVersion(version2);

        int n = max(v1.size(), v2.size());
        v1.resize(n, 0);
        v2.resize(n, 0);

        for (int i = 0; i < n; i++) {
            if (v1[i] > v2[i])
                return 1;
            else if (v1[i] < v2[i])
                return -1;
        }
        return 0;
    }
};