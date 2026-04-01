class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        int area = 0;

        while(left < right) {
            int minHeight = heights[left] < heights[right] ? heights[left] : heights[right];
            int tempArea = (minHeight * (right - left));
            area = tempArea > area ? tempArea : area;
            if (heights[left] < heights[right]){
                left++;
            }
            else {
                right--;
            }
        }


        return area;

    }
};
