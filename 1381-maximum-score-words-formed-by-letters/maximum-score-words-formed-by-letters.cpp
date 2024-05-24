class Solution {
public:
    int getWordScore(const string& word, const vector<int>& score) {
        int totalScore = 0;
        for (char ch : word) {
            totalScore += score[ch - 'a'];
        }
        return totalScore;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> wordScores;
        unordered_map<char, int> letterCount;

        // Calculate the score for each word
        for (const string& word : words) {
            wordScores.push_back(getWordScore(word, score));
        }

        // Count the available letters
        for (char letter : letters) {
            letterCount[letter]++;
        }

        int n = words.size();
        int maxScore = 0;

        // Evaluate all subsets of words
        for (int i = 1; i < (1 << n); ++i) {
            unordered_map<char, int> subsetLetterCount;
            int subsetScore = 0;
            bool valid = true;

            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    for (char ch : words[j]) {
                        subsetLetterCount[ch]++;
                        if (subsetLetterCount[ch] > letterCount[ch]) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid)
                        break;
                    subsetScore += wordScores[j];
                }
            }

            if (valid) {
                maxScore = max(maxScore, subsetScore);
            }
        }

        return maxScore;
    }
};