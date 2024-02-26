class Solution {
public:
    int trap(vector<int>& height) {
     int n = height.size();
    if (n <= 2) return 0; // Cannot trap water if there are less than 3 bars

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int waterTrapped = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                waterTrapped += leftMax - height[left];
            left++;//move left pointer to right
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                waterTrapped += rightMax - height[right];
            right--;// move right pointer to left
        }
    }

    return waterTrapped;    
    }
};