class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> countMap;
        for (int num : arr1) {
            countMap[num]++;
        }

        vector<int> result;

        for (int num : arr2) {
            while (countMap[num] > 0) {
                result.push_back(num);
                countMap[num]--;
            }
        }

        //remaining nums arrays in arr2
        vector<int> remain;
        for (auto& pair : countMap) {
            while (pair.second > 0) {
                remain.push_back(pair.first);
                pair.second--;
            }
        }
        sort(remain.begin(), remain.end());
        result.insert(result.end(), remain.begin(), remain.end());
        return result;
    }
};