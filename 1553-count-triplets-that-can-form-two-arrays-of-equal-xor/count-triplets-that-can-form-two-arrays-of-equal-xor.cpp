class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            int a = arr[i];
            for (int k = i + 1; k < n; k++) {
                a ^= arr[k];
                if (a == 0) {
                    result += (k - i);
                }
            }
        }
        return result;
    }
};