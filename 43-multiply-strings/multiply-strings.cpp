class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        vector<int> num(num1.length() + num2.length(), 0);
        for (int i = num1.length() - 1; i >= 0; --i) {
            for (int j = num2.length() - 1; j >= 0; --j) {
                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                num[i + j] += num[i + j + 1] / 10;
                num[i + j + 1] %= 10;
            }
        }
        // skip leading zero
        int i = 0;
        while (i < num.size() && num[i] == 0)
            ++i;
        // vector to string
        string result = "";
        while (i < num.size()) {
            result.push_back(num[i++] + '0');
        }
        return result;
    }
};