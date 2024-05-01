class Solution {
public:
    string reversePrefix(const string& word, char ch) {
        int idx = word.find(ch); // Find the first occurrence of ch

        if (idx == string::npos) { // ch not found, return original word
            return word;
        }

        string reversed = word.substr(0, idx + 1); // Get the segment to reverse
        reverse(reversed.begin(), reversed.end()); // Reverse the segment

        return reversed + word.substr(idx +1); // Combine reversed segment with remaining word
    }
};