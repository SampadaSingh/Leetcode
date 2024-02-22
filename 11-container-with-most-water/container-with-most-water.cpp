class Solution {
public:
    int maxArea(vector<int>& height) {
    int start=0;
    int end=height.size()-1;
    int area; //stores current area
    int maxarea=0; //stores max area

    while(start<end){
        area=min(height[start],height[end])*(end-start); //area=height*width
        if(area>maxarea) 
             maxarea=area;
        if(min(height[start],height[end])==height[start])
             start++;
        else
             end--;
    }
    return maxarea;
    }
};