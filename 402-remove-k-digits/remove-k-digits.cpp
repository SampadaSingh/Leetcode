class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k >= n)
            return "0";
        int top = -1;
        for (int i = 0; i < n; ++i) {
            while (k > 0 && top >= 0 && num[top] > num[i]) {
                --top;
                --k;
            }
            num[++top] = num[i];
        }
        top -= k;
        int startIndex = 0;
        while (startIndex <= top && num[startIndex] == '0')
            ++startIndex;
        string result = startIndex > top ? "0": string(num.begin() + startIndex, num.begin() + top + 1);

        return result;
    }
};