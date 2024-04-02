class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, char> sMap;
        unordered_map<char, char> tMap;

        for (int i = 0; i < s.length(); ++i) {
            // Check if the current characters in s and t have not been mapped before
            if (sMap.find(s[i]) == sMap.end() &&
                tMap.find(t[i]) == tMap.end()) {
                //Establish mappings if both characters are new
                sMap[s[i]] = t[i];
                tMap[t[i]] = s[i];
            } else {
                if (sMap[s[i]] != t[i] || tMap[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};