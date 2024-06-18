class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        vector<pair<int, int>> job;

        for (int i = 0; i < n; i++) {
            job.push_back({difficulty[i], profit[i]});
        }

        sort(worker.begin(), worker.end());
        sort(job.begin(), job.end());

        int index = 0;
        int maxProfit = 0;
        int res = 0;
        
        for (int i = 0; i < m; i++) {
            while (index <n && worker[i] >= job[index].first) {
                maxProfit = max(maxProfit, job[index].second);
                index++;
            }
            res += maxProfit;
        }

        return res;
    }
};