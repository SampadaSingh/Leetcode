class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        for (string& age : details) {
            int tens = age[11] - '0';
            int ones = age[12] - '0';
            int a = tens * 10 + ones;

            if (a > 60) {
                count++;
            }
        }
        return count;
    }
};