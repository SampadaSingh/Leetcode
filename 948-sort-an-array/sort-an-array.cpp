class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid + 1, right);
        }
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1, 0);
        int idx = 0;
        int left_idx = left;
        int right_idx = mid;

        while (left_idx < mid && right_idx <= right) {
            if (nums[left_idx] <= nums[right_idx]) {
                temp[idx++] = nums[left_idx++];
            } else {
                temp[idx++] = nums[right_idx++];
            }
        }

        while (left_idx < mid) {
            temp[idx++] = nums[left_idx++];
        }

        while (right_idx <= right) {
            temp[idx++] = nums[right_idx++];
        }

        for (int i = 0; i < temp.size(); i++) {
            nums[left + i] = temp[i];
        }
    }
};