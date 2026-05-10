class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        
        int result = 0;

        while (l < r) {
            int minHeight = min(heights[l], heights[r]);
            int area = minHeight * (r - l);
            
            result = max(result, area);

            if (heights[l] > heights[r]) {
                r--;
            }
            else {
                l++;
            }


        }

        return result;

    }
};
