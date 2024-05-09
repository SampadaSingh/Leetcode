class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long result = 0;

        int count = 0;

        priority_queue<int> pq;

        for (int& happ : happiness) {
            pq.push(happ);
        }

        for (int i = 0; i < k; i++) {
            int happ = pq.top();
            pq.pop();
            result += max(happ - count, 0);
            count++;
        }
        return result;
    }
};