class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> ratios;

        for (int i = 0; i < n; ++i) {
            ratios.push_back({(double)wage[i] / quality[i], quality[i]});
        }

        sort(ratios.begin(), ratios.end());

        double result = DBL_MAX;
        int sum = 0;
        priority_queue<int> max_heap;

        for (auto& ratio : ratios) {
            sum += ratio.second;
            max_heap.push(ratio.second);

            if (max_heap.size() > k) {
                sum -= max_heap.top();
                max_heap.pop();
            }

            if (max_heap.size() == k) {
                result = min(result, sum * ratio.first);
            }
        }

        return result;
    }
};